#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};
struct Queue* CreateQueueArray(int cap)
{
    struct Queue *q;
    q=malloc(sizeof(struct Queue));
    q->capacity=cap;
    q->front=-1;
    q->rear=-1;
    q->ptr=malloc(sizeof(int)*cap);
    return q;
}

void insert(struct Queue *q,int data)
{
    if(q->front==-1)
    {   //empty

        q->rear+=1;
        q->front+=1;
        q->ptr[q->rear]=data;
    }
    else if((q->rear==q->capacity-1&&q->front==0)||(q->rear==q->front-1))
        printf("OverFlow\n"); //overflow
    else if(q->capacity-1==q->rear)
    {
        //insertion after deletion
        q->rear=0;
        q->ptr[q->rear]=data;
    }
    else
    {
        //normal case
        q->rear+=1;
        q->ptr[q->rear]=data;
    }
}
void view(struct Queue *q)
{
    int i;
    for(i=q->front;i<=q->rear;i++)
        printf("%d ",q->ptr[i]);
        printf("\n");
}
void delete(struct Queue *q)
{
    if(q->front==-1)
        printf("Queue is Empty\n");
    else if(q->rear==q->front)
    {
        //only 1 value
        q->front=q->rear=-1;
        printf("Queue is Empty\n");
        
    }
    else if(q->capacity-1==q->front)
    {
        //
        q->front=0;
        printf("Queue is Empty\n");
    }
    else
        q->front+=1;
}
void peek(struct Queue *q)
{
    printf("Rear=%d\nFront=%d\n",q->rear,q->front);
}
int main()
{
    struct Queue *q=NULL;
    q=CreateQueueArray(6);
    insert(q,10);
    insert(q,20);
    insert(q,30);
    insert(q,40);
    insert(q,50);
    insert(q,60);
    view(q);
    peek(q);
    return 0;
}
