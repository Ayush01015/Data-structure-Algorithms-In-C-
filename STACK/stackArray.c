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
void push(struct stack *s,int data)
{
    if(s->capacity-1==s->top)
        printf("Overflow");
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
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    peek(s);

    return 0;
}
