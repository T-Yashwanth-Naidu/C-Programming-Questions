/*
 * Find the unique element in an array using XOR.
 *
 * Problem:
 *   Given an array where every element appears exactly twice except for one
 *   element which appears once, find the unique element using bitwise
 *   operations in O(n) time and O(1) space.
 *
 * Algorithm:
 *   XOR all elements together. By XOR's properties (x ^ x = 0, x ^ 0 = x,
 *   commutative and associative), every paired element cancels to zero.
 *   The unique element remains.
 *
 * Example:
 *   Input:  [4, 1, 2, 1, 2]
 *   Output: 4
 *
 * Logic: XOR cancellation finds the lone element in O(n) time, O(1) space.
 *
 *   For every value x: x ^ x = 0   (a value XORed with itself cancels)
 *                      x ^ 0 = x   (XOR with zero is the identity)
 *                      XOR is commutative and associative
 *
 *   When every element appears twice except one, XORing all elements together
 *   pairs them off in any order. Each pair reduces to 0. The lone element
 *   XORs with the accumulated zeros and survives unchanged.
 *
 *   Example: [4, 1, 2, 1, 2]
 *     0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
 *     = 4 ^ (1 ^ 1) ^ (2 ^ 2)    (rearrange via commutativity)
 *     = 4 ^ 0 ^ 0
 *     = 4
 *
 *   The result variable is initialized to 0 because 0 is XOR's identity -
 *   it does not contribute to the final result.
 *
 * @Author: Yashwanth Naidu Tikkisetty (https://github.com/T-Yashwanth-Naidu)
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ============================================================
 * Status codes
 * ============================================================ */

typedef enum {
  SN_OK = 0,
  SN_NULL_POINTER,
  SN_INVALID_SIZE,
  SN_ALLOCATION_FAILED
} sn_status_t;

static const char *sn_status_str(sn_status_t status);

/* ============================================================
 * Public API declarations
 * ============================================================ */

sn_status_t find_unique_element(const int32_t *arr, size_t size,
                                int32_t *out_result);

sn_status_t generate_test_array(size_t size, int32_t **out_array,
                                int32_t *out_unique);

/* ============================================================
 * Internal helper declarations
 * ============================================================ */

static void shuffle_array(int32_t *arr, size_t size);
static void print_array(const int32_t *arr, size_t size);
static bool run_single_test(size_t size);

/* ============================================================
 * Entry point
 * ============================================================ */

int main(void) {
  srand((unsigned int)time(NULL));

  static const size_t test_sizes[] = {1, 3, 5, 11, 25, 99, 255, 999};
  const size_t num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

  size_t passed = 0;

  printf("Running %zu test cases...\n\n", num_tests);
  for (size_t i = 0; i < num_tests; i++) {
    if (run_single_test(test_sizes[i])) {
      passed++;
    }
  }

  printf("\n=========================================\n");
  printf("Results: %zu / %zu tests passed\n", passed, num_tests);
  printf("=========================================\n");

  return (passed == num_tests) ? 0 : 1;
}

/* ============================================================
 * Public API implementations
 * ============================================================ */

/*
 * Finds the unique element in an array where every other element appears
 * exactly twice.
 *
 * Preconditions:
 *   - arr must not be NULL
 *   - size must be odd and >= 1
 *   - exactly one element appears once; all others appear exactly twice
 *
 * Postconditions:
 *   - On success, *out_result contains the unique element
 *   - On failure, *out_result is unchanged
 *
 * Complexity: O(n) time, O(1) space
 */
sn_status_t find_unique_element(const int32_t *arr, size_t size,
                                int32_t *out_result) {
  if (arr == NULL || out_result == NULL) {
    return SN_NULL_POINTER;
  }
  if (size == 0 || (size % 2) == 0) {
    return SN_INVALID_SIZE;
  }

  int32_t result = 0;
  for (size_t i = 0; i < size; i++) {
    result ^= arr[i];
  }

  *out_result = result;
  return SN_OK;
}

/*
 * Generates a random test array suitable for find_unique_element.
 * Uses sequential values 1..n_pairs each twice, plus value (n_pairs+1)
 * once, shuffled into random positions.
 *
 * Preconditions:
 *   - size must be odd and >= 1
 *   - out_array and out_unique must not be NULL
 *
 * Postconditions:
 *   - On success: *out_array points to a heap-allocated array of length
 *     size; caller must free() it. *out_unique contains the singleton.
 *   - On failure: *out_array is set to NULL; *out_unique is unchanged.
 */
sn_status_t generate_test_array(size_t size, int32_t **out_array,
                                int32_t *out_unique) {
  if (out_array == NULL || out_unique == NULL) {
    return SN_NULL_POINTER;
  }
  *out_array = NULL;

  if (size == 0 || (size % 2) == 0) {
    return SN_INVALID_SIZE;
  }

  int32_t *arr = malloc(size * sizeof(int32_t));
  if (arr == NULL) {
    return SN_ALLOCATION_FAILED;
  }

  const size_t n_pairs = (size - 1) / 2;
  const int32_t unique_value = (int32_t)(n_pairs + 1);

  /* Fill with pairs: positions 0..(2*n_pairs - 1) get values 1..n_pairs twice
   */
  for (size_t i = 0; i < n_pairs; i++) {
    arr[2 * i] = (int32_t)(i + 1);
    arr[2 * i + 1] = (int32_t)(i + 1);
  }
  /* Last position gets the singleton */
  arr[size - 1] = unique_value;

  shuffle_array(arr, size);

  *out_array = arr;
  *out_unique = unique_value;
  return SN_OK;
}

/* ============================================================
 * Internal helper implementations
 * ============================================================ */

/*
 * Fisher-Yates shuffle. Permutes the array uniformly at random in place.
 * Safe to call with size 0 or 1 (no-op).
 */
static void shuffle_array(int32_t *arr, size_t size) {
  if (arr == NULL || size < 2) {
    return;
  }

  for (size_t i = size - 1; i > 0; i--) {
    size_t j = (size_t)rand() % (i + 1);
    int32_t temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

/*
 * Prints an array to stdout in the format [v1 v2 v3 ...].
 * Safe to call with NULL or size 0 (prints empty brackets).
 */
static void print_array(const int32_t *arr, size_t size) {
  printf("[");
  if (arr != NULL) {
    for (size_t i = 0; i < size; i++) {
      printf("%d", arr[i]);
      if (i < size - 1) {
        printf(" ");
      }
    }
  }
  printf("]");
}

/*
 * Runs a single test case: generates an array, runs the algorithm,
 * compares the result to the expected value.
 *
 * Returns true if the test passed, false otherwise.
 */
static bool run_single_test(size_t size) {
  int32_t *arr = NULL;
  int32_t expected = 0;
  int32_t actual = 0;
  bool passed = false;

  sn_status_t status = generate_test_array(size, &arr, &expected);
  if (status != SN_OK) {
    printf("[FAIL] size=%zu: generator returned %s\n", size,
           sn_status_str(status));
    goto cleanup;
  }

  if (size <= 25) {
    printf("       size=%zu: array=", size);
    print_array(arr, size);
    printf("\n");
  }

  status = find_unique_element(arr, size, &actual);
  if (status != SN_OK) {
    printf("[FAIL] size=%zu: algorithm returned %s\n", size,
           sn_status_str(status));
    goto cleanup;
  }

  if (actual != expected) {
    printf("[FAIL] size=%zu: expected %d, got %d\n", size, expected, actual);
    goto cleanup;
  }

  printf("[PASS] size=%zu: unique=%d\n", size, expected);
  passed = true;

cleanup:
  free(arr);
  return passed;
}

/*
 * Maps a status code to a human-readable string for error messages.
 */
static const char *sn_status_str(sn_status_t status) {
  switch (status) {
  case SN_OK:
    return "OK";
  case SN_NULL_POINTER:
    return "NULL pointer";
  case SN_INVALID_SIZE:
    return "invalid size";
  case SN_ALLOCATION_FAILED:
    return "allocation failed";
  default:
    return "unknown status";
  }
}