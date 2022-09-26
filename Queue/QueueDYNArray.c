#include<stdio.h>
#include<stdlib.h>
struct QueueDArray
{
    int capacity;
    int front,rear;
    int *ptr;
};
struct QueueDArray* CreateArray(int cap)
{
    struct QueueDArray *n;
    n=malloc(sizeof(struct QueueDArray));
    n->capacity=cap;
    n->front=-1;
    n->rear=-1;
    n->ptr=malloc(sizeof(int)*cap);
    return n;
}
void doubleArray(struct QueueDArray *q)
{
    int *t;
    q->capacity*=2;
    t=malloc(sizeof(int)*q->capacity);
    for(int i=q->front;i<=q->rear;i++)
        t[i]=q->ptr[i];
    free(q->ptr);
    q->ptr=t;
}
void insert(struct QueueDArray *q,int data)
{
    if((q->rear==q->capacity-1&&q->front==0)||(q->front-1==q->rear))
    {
        doubleArray(q);
        q->rear+=1;
        q->ptr[q->rear]=data;
    }
    else if(q->front==-1)
    {
        q->front+=1;
        q->rear+=1;
        q->ptr[q->rear]=data;
    }
    else if(q->capacity-1==q->rear)
    {
        q->rear=0;
        q->ptr[q->rear]=data;
    }
    else
    {
        q->rear+=1;
        q->ptr[q->rear]=data;
    }
}
void view(struct QueueDArray *q)
{
    for(int i=q->front;i<=q->rear;i++)
        printf("%d ",q->ptr[i]);
    printf("\n");
}
void Remove(struct QueueDArray *q)
{
    if(q->front==-1)
        printf("Queue is Empty\n");
    else if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
        printf("Queue is Empty\n");
    }
    else if(q->capacity-1==q->front)
    {
        q->front=0;
        printf("Queue is Empty\n");
    }
    else
    {
        q->front+=1;
    }
}
void halfArray(struct QueueDArray *q)
{
    int *t;
    q->capacity/=2;
    t=malloc(sizeof(int)*q->capacity);
    for(int i=q->front;i<=q->rear;i++)
        t[i]=q->ptr[i];
    free(q->ptr);
    q->ptr=t;
}
int main()
{
    struct QueueDArray *q=NULL;
    q=CreateArray(6);
    insert(q,10);
    insert(q,20);
    insert(q,30);
    insert(q,40);
    insert(q,50);
    insert(q,60);
    insert(q,70);
    insert(q,80);
    insert(q,90);
    insert(q,100);
    view(q);
    return 0;
}
