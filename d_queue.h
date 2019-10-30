#include <stdbool.h>
#ifndef D_QUEUE_NEW
#define D_QUEUE_NEW

typedef struct {
    double *body;
    char name[5];
    int size;
    int cap;
    int front;
}queue;
bool q_grow(queue *s);
void q_srink(queue *s);
queue *double_q_create( char name[5]);
void double_q_destroy(queue *q);
bool q_is_empty(queue *q);
bool double_q_push_back(queue *q, double val);
double double_q_pop_front(queue *q);
#endif