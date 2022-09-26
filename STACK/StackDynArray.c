#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int capacity;
    int top;
    int *ptr;
};
struct stack* CreateStack(int cap)
{
    struct stack *s;
    s=malloc(sizeof(struct stack));
    s->capacity=cap;
    s->top=-1;
    s->ptr=malloc(sizeof(int)*cap);
    return s;
}
void doublestack(struct stack *s)
{
    int *t;
    s->capacity*=2;
    t=malloc(sizeof(s->capacity));
    for(int i=0;i<=s->capacity-1;i++)
        t[i]=s->ptr[i];
    free(s->ptr);
    s->ptr=t;
}
void halfstack(struct stack *s)
{
    int *t;
    s->capacity/=2;
    t=malloc(sizeof(s->capacity));
    for(int i=0;i<=s->capacity-1;i++)
        t[i]=s->ptr[i];
    free(s->ptr);
    s->ptr=t;
}
void push(struct stack *s,int data)
{
    if(s->capacity-1==s->top)
    {
        doublestack(s);
        s->top+=1;
        s->ptr[s->top]=data;
    }
    else
    {
        s->top+=1;
        s->ptr[s->top]=data;
    }
}
void pop(struct stack *s)
{
    if(s->top==-1)
        printf("Stack is Empty");
    else
        s->top-=1;
}
void peek(struct stack *s)
{
    if(s->top==-1)
        printf("Stack is Empty");
    else
        printf("%d",s->ptr[s->top]);
}

int main()
{
    struct stack *s=NULL;
    s=CreateStack(5);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,500);
    peek(s);
   

    return 0;
}
//please modify code for dynamic Array...it is incomplete