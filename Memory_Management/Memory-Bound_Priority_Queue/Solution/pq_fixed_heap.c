/**
 * @file pq_fixed_heap.c
 * @brief Memory-bound max-priority queue implemented as a binary heap in a
 * fixed array.
 * @author Yashwanth Naidu Tikkisetty
 * @date   September 8, 2025
 *
 * @details
 * What: A priority queue that returns the highest-priority (maximum) element
 * first. Why: For embedded/RT environments (or any place with tight memory
 * budgets) where dynamic allocation is disallowed; delivers O(log N)
 * insert/remove with deterministic space usage.
 *
 * Design
 * - Storage: single fixed array `int data[PQ_CAPACITY]` and a `size` counter.
 * - Invariant: Max-heap property: for all valid indices i, data[parent(i)] >=
 * data[i].
 * - Indexing (0-based heap):
 *   - parent(i) = (i-1)/2  (undefined for i==0; the loop logic prevents calling
 * it)
 *   - left(i)   = 2*i + 1
 *   - right(i)  = 2*i + 2
 *
 * Operations:
 * - pq_push (heapify-up): O(log N)
 * - pq_pop_max (heapify-down): O(log N)
 * - pq_peek_max: O(1)
 *
 * Constraints/Assumptions:
 * - No dynamic memory; capacity is compile-time `PQ_CAPACITY`.
 * - Not thread-safe; callers must externally synchronize for concurrent use.
 * - Not stable with equal priorities; if stability is required, store
 * (priority, -seq).
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#ifndef PQ_CAPACITY
/// Compile-time fixed capacity of the priority queue (number of elements).
#define PQ_CAPACITY 64
#endif

/**
 * @brief POD holding heap storage and current logical size.
 *
 * The array is always kept in a valid max-heap shape over the first @c size
 * elements.
 */
typedef struct {
  int data[PQ_CAPACITY]; /**< Heap storage (max-heap) */
  size_t size; /**< Logical size: number of active elements in @c data */
} PriorityQueue;

/* ============================= Internal helpers =============================
 */

/**
 * @brief Compute parent index in a 0-based heap.
 * @param i Node index (must be > 0).
 * @return Parent index.
 *
 * @note Undefined for i==0; callers avoid calling with i==0.
 */
static inline size_t parent(size_t i) { return (i - 1U) / 2U; }

/**
 * @brief Left child index (may be >= size, caller checks).
 */
static inline size_t left(size_t i) { return 2U * i + 1U; }

/**
 * @brief Right child index (may be >= size, caller checks).
 */
static inline size_t right(size_t i) { return 2U * i + 2U; }

/**
 * @brief Swap two elements in the heap.
 * @param a First element pointer.
 * @param b Second element pointer.
 * @details Small, inlined swap keeps code clear and branch-free.
 */
static inline void swap_int(int *a, int *b) {
  int tmp = *a; // hold A
  *a = *b;      // copy B into A
  *b = tmp;     // move held A into B
}

/**
 * @brief Restore heap property by sifting node @p i upward.
 * @param pq Priority queue.
 * @param i  Index to sift (0 <= i < pq->size).
 * @details
 * Repeatedly swaps the node with its parent while it is larger than the parent.
 * Complexity: O(log N).
 */
static void sift_up(PriorityQueue *pq, size_t i) {
  // Loop until we reach root (i==0) or parent >= node (heap property
  // satisfied).
  while (i > 0) {
    size_t p = parent(i); // compute parent index
    if (pq->data[p] >=
        pq->data[i]) // if parent already >= child, heap is valid here
      break;         // stop; no more upward movement needed
    swap_int(&pq->data[p],
             &pq->data[i]); // parent < child → swap to fix local violation
    i = p;                  // continue sifting from parent's former position
  }
}

/**
 * @brief Restore heap property by sifting node @p i downward.
 * @param pq Priority queue.
 * @param i  Index to sift (0 <= i < pq->size).
 * @details
 * Selects the larger child and swaps down until both children are <= node.
 * Complexity: O(log N).
 */
static void sift_down(PriorityQueue *pq, size_t i) {
  for (;;) {
    size_t l = left(i), r = right(i); // compute children indices for node i
    size_t largest = i; // assume current node is largest in its small subtree

    // If left child exists and is larger than current "largest", select it.
    if (l < pq->size && pq->data[l] > pq->data[largest])
      largest = l;

    // If right child exists and is larger than the current "largest" (node or
    // left), select it.
    if (r < pq->size && pq->data[r] > pq->data[largest])
      largest = r;

    // If neither child is larger, the heap property holds at i.
    if (largest == i)
      break; // stop; node is in correct position

    // Otherwise, swap the node with the larger of its children to fix the local
    // violation.
    swap_int(&pq->data[i], &pq->data[largest]);

    // Continue sifting from the child's position; the moved value may still be
    // too small.
    i = largest;
  }
}

/* =================================== API ===================================
 */

/**
 * @brief Initialize an empty priority queue.
 * @param pq Priority queue (output).
 * @post @c pq->size == 0 and heap is empty.
 */
static inline void pq_init(PriorityQueue *pq) {
  pq->size = 0; // mark heap as empty; array contents are irrelevant until used
}

/**
 * @brief Query if the priority queue is empty.
 * @param pq Priority queue (const).
 * @retval true  if empty.
 * @retval false otherwise.
 */
static inline bool pq_is_empty(const PriorityQueue *pq) {
  return pq->size == 0; // no elements present
}

/**
 * @brief Query if the priority queue is full.
 * @param pq Priority queue (const).
 * @retval true  if @c pq->size == PQ_CAPACITY
 * @retval false otherwise.
 */
static inline bool pq_is_full(const PriorityQueue *pq) {
  return pq->size == PQ_CAPACITY; // cannot accept more inserts
}

/**
 * @brief Current number of elements in the queue.
 * @param pq Priority queue (const).
 * @return size as @c size_t (0..PQ_CAPACITY).
 */
static inline size_t pq_size(const PriorityQueue *pq) {
  return pq->size; // cheap accessor for callers
}

/**
 * @brief Insert a new element into the max-heap.
 * @param pq Priority queue.
 * @param x  Element to insert.
 * @retval true  on success.
 * @retval false if the queue is full (no insertion performed).
 *
 * @details
 * Places @p x at the next free slot, then restores the heap with sift-up.
 * Complexity: O(log N).
 */
bool pq_push(PriorityQueue *pq, int x) {
  if (pq->size == PQ_CAPACITY) // capacity check: fixed memory budget
    return false;              // cannot insert; signal overflow to caller

  pq->data[pq->size] =
      x; // write new value at the end (maintains complete tree shape)
  sift_up(pq, pq->size); // bubble it up until heap property is restored
  pq->size++;            // commit the insertion by increasing logical size
  return true;           // success
}

/**
 * @brief Read the current maximum element without removing it.
 * @param pq  Priority queue (const).
 * @param out Optional output pointer to receive the max element.
 * @retval true  if queue is non-empty; @p *out receives the max if non-NULL.
 * @retval false if queue is empty; @p *out is left untouched.
 *
 * @details
 * Complexity: O(1).
 */
bool pq_peek_max(const PriorityQueue *pq, int *out) {
  if (pq->size == 0) // empty guard
    return false;    // nothing to peek
  if (out) // optional out: caller may pass NULL to just query existence
    *out = pq->data[0]; // root of the heap holds the maximum
  return true;          // success
}

/**
 * @brief Remove and return the maximum element.
 * @param pq  Priority queue.
 * @param out Optional output pointer to receive the removed max element.
 * @retval true  if an element was removed; @p *out receives the value if
 * non-NULL.
 * @retval false if the queue was empty (no removal).
 *
 * @details
 * Swaps the last element into the root, reduces size, and restores heap via
 * sift-down. Complexity: O(log N).
 */
bool pq_pop_max(PriorityQueue *pq, int *out) {
  if (pq->size == 0) // underflow guard
    return false;    // cannot pop from empty queue

  if (out)
    *out = pq->data[0]; // capture current max (root) for caller

  pq->size--;         // logically remove one element (the root)
  if (pq->size > 0) { // if elements remain, we must re-heapify
    pq->data[0] =
        pq->data[pq->size]; // move last element to root (keeps tree complete)
    sift_down(pq, 0);       // push it down until heap property is restored
  }
  // If pq->size == 0 after decrement, heap is now empty; nothing else to do.

  return true; // success
}

/* ================================== Demo ===================================
 */

int main(void) {
  PriorityQueue pq;
  pq_init(&pq);

  // Example: Insert 5, 9, 2; Remove → should remove 9 first
  (void)pq_push(&pq, 5);
  (void)pq_push(&pq, 9);
  (void)pq_push(&pq, 2);

  int top;
  if (pq_pop_max(&pq, &top)) {
    printf("Removed %d\n", top); // Expected: 9
  } else {
    printf("Queue empty\n");
  }

  // Extra sanity: push a few more and drain
  int inputs[] = {4, 7, 1, 7, 6};
  for (size_t i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i) {
    (void)pq_push(&pq, inputs[i]);
  }

  printf("Draining in priority order: ");
  while (pq_pop_max(&pq, &top)) {
    printf("%d ", top);
  }
  printf("\n");

  return 0;
}
