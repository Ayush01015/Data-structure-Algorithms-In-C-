#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int item;
    struct node *next;

};
void insertAtlast(struct node **s,int data)
{
    struct node *n,*t;
    t=*s;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
    {
        n->prev=NULL;
        *s=n;
    }
    else
    {
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }
}
void insertAtfirst(struct node **s,int data)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->prev=NULL;
    n->next=*s;
    *s=n;
}
void insertnode(struct node **s,struct node *t,int data)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->prev=t;
    n->next=t->next;
    t->next=n;
}
struct node* Search(struct node *s,int data)
{
    while(s!=NULL)
    {
        if(s->item==data)
            return s;
        s=s->next;
    }
}
void view(struct node *s)
{
    while(s!=NULL)
    {
        printf("%d ",s->item);
        s=s->next;
    }
    printf("\n");
}
void removeFirst(struct node **s)
{
    struct node *t;
    t=*s;
    if(*s==NULL)
        printf("\nNothing to delete\n");
    else
    {
            t->next->prev=NULL;
        *s=t->next;
            free(t);
    }
}
void removeLast(struct node **s)
{
    struct node *t;
    t=*s;
    if(t->next==NULL)
    {
        free(t);
        *s=NULL;
    }
    else
    {
        while(t->next!=NULL)
            t=t->next;
        t->prev->next=NULL;
        free(t);
    }
}
void removeNode(struct node **s,struct node *r)
{
    struct node *t;
    t=*s;
    if(*s==r)
    {
        t->next->prev=NULL;
        *s=t->next;
    }
    else
    {
        while(t->next!=r)
            t=t->next;
        t->next=r->next;
        r->next->prev=t;
    }
}
int main()
{
    struct node *start=NULL;
    struct node *s,*t;
    insertAtfirst(&start,10);
    insertAtlast(&start,20);
    insertAtlast(&start,30);
    insertAtlast(&start,40);
    insertAtlast(&start,50);
    view(start);
    s=Search(start,30);
    insertnode(&start,s,100);
    view(start);
    t=Search(start,100);
    insertnode(&start,t,200);
    view(start);
    insertAtfirst(&start,900);
    view(start);
    removeFirst(&start);
    view(start);
    removeLast(&start);
    view(start);
    
    
    return 0;
}
