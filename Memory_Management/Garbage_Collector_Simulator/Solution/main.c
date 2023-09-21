/*
Garbage Collector Simulator:

Implement a simple mark-and-sweep garbage collector.

(e.g.: I/P: Allocate 5, Allocate 7, Mark 5, Sweep; O/P: 7 collected)

If you allocate blocks of 5 and 7 bytes and then mark the 5-byte block, running the sweep should collect the 7-byte block.

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct block{
    int data;
    struct block* link;
    int size;
    bool mark;
}block;

block* allocate(  block* list ,block* new_block,int blocks){
    block* ptr;
    new_block = NULL;
    for(int i=0;i<blocks;i++){
        if(list == NULL){
            ptr=list=(block*)malloc(sizeof(block));
            list->data = 0;
            list->link = NULL;
            list->mark = 0;
            list->size = blocks;
            new_block = list;
        }
        else{

            for(ptr=list;ptr->link!=NULL;ptr=ptr->link);
            ptr->link = (block*)malloc(sizeof(block));
            if(!new_block){new_block=ptr->link;}
            ptr=ptr->link;
            ptr->link=NULL;
            ptr->data = 0;
            ptr->size = blocks;
        }
    }
    return new_block;
}

void print(block* list){
    for(;list!=NULL;list=list->link){
        printf("data is:%d & mark is : %d\n\n",list->data,list->mark);
    }
}

block* mark(block* ptr){
    block* p=ptr;
    for(int i=0;i<ptr->size;i++){
        p->mark=1;
        p=p->link;
    }
    return ptr;
}

block* sweep(block* list){
    block* p;
    block* q;
    block* temp;
    p=q=list;
    if(!list->mark){
        p=list->link;
        q=list;
        list=list->link;
        free(q);
        q=p;

    }
    while(p->link!=NULL && p->link->mark){
        p=p->link;
    }
    temp=p->link;
    if(temp!=NULL){
        q=temp->link;
        while(q->link!=NULL &&!q->link->mark){
        free(temp);
        temp=q;
        q=q->link;
        }
        p->link=q->link;
        free(q);
        return list;
    }
    /*while(!q->link->mark){
        q=q->link;
    }
    p->link = q->link;*/
    
    else{
        return list;
    }
    
     
}

int main(){
    block* list=NULL;                                   //the main list with all memory blocks
    list = allocate(list,list,1);                       
    block* new_block0 = allocate(list,new_block0,3);    //new memory block allocated having 3-sub blocks
    block* new_block1 = allocate(list,new_block1,4);    //new memory block added having 4-sub blocks
    new_block0=mark(new_block0);                        //marked the block new_block0
    print(list);                                        //print the whole list
    printf("---------------\n\n");
    list=sweep(list);                                   //sweep the whole main list
    print(list);                                        //print list
}