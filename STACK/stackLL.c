#include<stdlib.h>
#include<stdio.h>
struct stackLL
{
    int item;
    struct stackLL *next;
};
void push(struct stackLL **s,int data)
{
    struct stackLL *n,*t;
    t=*s;
    n=malloc(sizeof(struct stackLL));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
        *s=n;
    else
    {
        while(t->next!=NULL)
            t=t->next;
        t->next=n;

    }
}
void pop(struct stackLL **s)
{
    struct stackLL *r,*r1;
    r=*s;
    r1=NULL;
    if(*s==NULL)
        printf("Stack is Empty\n");
    else
    {
        while(r->next!=NULL)
        {
            r1=r;
            r=r->next;
        }
        if(r1!=NULL)
            r1->next=NULL;
        else
            *s=NULL;
    }
    free(r);
}
void peek(struct stackLL *s)
{
    if(s==NULL)
        printf("Stack is Empty\n");
    else
    {
        while(s->next!=NULL)
            s=s->next;
        printf("%d",s->item);
    }
}
int main()
{
    struct stackLL *s=NULL;
    push(&s,10);        
    push(&s,20);        
    push(&s,30);        
    push(&s,40);        
    push(&s,50);   
    pop(&s);     
    pop(&s);     
    pop(&s);     
    peek(s);
    return 0;
}