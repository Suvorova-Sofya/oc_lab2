#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"


vector *v_create() {
    vector *v = (vector *) malloc(sizeof(vector));
    v->size = 0;
    v->body = NULL;
    return v;
}

void v_destroy(vector *v) {
    free(v->body);
    free(v);
}

int v_get_size(vector *v) {
    return v->size;
}

queue* v_get(vector *v, int i) {
    return &v->body[i];
}

bool v_set_size(vector *v, int size) {
    queue *bodyre = (queue *) realloc(v->body, size * sizeof(queue));
    if (bodyre == NULL && size != 0) {
        return false;
    }
    if(bodyre == NULL){
        return true;
    }
    for (int i = v->size; i<size; i++) {
        char str[5]={'0','0','0','0','0'};
        queue* q=double_q_create(str);
        bodyre[i]=*q;
    }
    v->body=bodyre;
    v->size=size;
    return true;
}

void v_set(vector *v, int i, queue* val) {
    v->body[i] = *val;
}

bool v_push(vector *v, queue* val) {
    int new_size=v->size + 1;
    if(!v_set_size(v,new_size)){
        return false;
    }
    v_set(v,new_size - 1,val);
    return true;
}
