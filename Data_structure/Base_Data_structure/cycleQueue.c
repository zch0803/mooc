#include "stdio.h"
#include "stdlib.h"
#define MAXQSIZE 100

typedef struct{
    int *base;
    int front;
    int rear;
}cycleQueue;

void initQueue(cycleQueue *q){
    q->base = (int *)malloc(MAXQSIZE*sizeof(int));
    if(!q->base)exit(0);
    q->front = q->rear = 0;
}

void EnQueue(cycleQueue *q, int e){
    if((q->rear + 1)%MAXQSIZE == q->front) return;
    q->base[q->rear] = e;
    q->rear = (q->rear+1)%MAXQSIZE;
}

void DeQueue(cycleQueue *q, int *e){
    if(q->front == q->rear) return;
    *e = q->base[q->front];
    q->front = (q->front + 1)%MAXQSIZE;
}

void DestroyQueue(cycleQueue *q){
    free(q->base);
}

int main(){
    cycleQueue q;
    int i;
    initQueue(&q);
    EnQueue(&q, 0);
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    DeQueue(&q, &i);
    printf("%d",i);
    DeQueue(&q, &i);
    printf("%d",i);
    DeQueue(&q, &i);
    printf("%d",i);
    DestroyQueue(&q);
    return 0;
}
