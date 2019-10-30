#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "d_queue.h"
#define MIN_CAP 4

queue *double_q_create(char name[5]){
    queue *q=(queue*)malloc(sizeof(queue));
    q->body=(double *)malloc(5*sizeof(double));
    for (int i = 0; i < 5; ++i) {
        q->name[i]=name[i];
    }
    q->size=0;
    q->cap=5;
    q->front=0;
    return q;
}
bool q_is_empty(queue *q){
    if(q->size==0){
        return true;
    } else {
        return false;
    }
}
bool q_grow(queue *q){
    int new_cap=2*q->cap;
    double *new_body=(double *)realloc(q->body,new_cap* sizeof(double));
    if(new_body==NULL){
        return false;
    }
    for(int i = q->size-1 ;i >= q->front; i=i-1){
        new_body[i+(new_cap-q->cap)]=q->body[i];
    }
    q->body=new_body;
    if(q->front==0) {
        q->front = q->front;
    }else{
        q->front = q->front+(q->cap-new_cap);
    }
    q->cap=new_cap;
    return true;
}
void q_shrink(queue *q){
    if(q->size > q->cap/4){
        return;
    }
    int new_cap=q->cap/2;
    if(new_cap < MIN_CAP){
        new_cap=MIN_CAP;
    }
    if(q->front+q->size >= q->cap){
        for (int i = q->front; i < q->cap; ++i) {
            q->body[i-(q->cap-new_cap)]=q->body[i];
        }
        q->front=q->front-(q->cap-new_cap);
    } else{
        for (int i = q->front; i < q->size+q->front; ++i) {
            q->body[i-(q->cap-new_cap)]=q->body[i];
        }
    }
    q->body=(double *)realloc(q->body, sizeof(double)*new_cap);
    q->cap=new_cap;
    return;
}

double double_q_pop_front(queue *q){
    double val=q->body[q->front];
    if (q->front==q->cap-1){
        q->front=0;
    } else {
        q->front++;
    }
    q->size--;
    return val;
}
void double_q_destroy(queue *q){
    free(q->body);
    for (int i = 0; i < 5; ++i) {
        q->name[i]='\0';
    }
    q->size=0;
    q->cap=0;
    q->front=0;
}
bool double_q_push_back(queue *q, double val){
    if(q->size==q->cap){
        if(!q_grow(q)){
            return false;
        }
    }
    q->body[(q->size+q->front)%q->cap]=val;
    q->size++;
    return true;
}