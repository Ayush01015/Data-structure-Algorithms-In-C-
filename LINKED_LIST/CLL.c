#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
void insertAtlast(struct node **l,int data)
{
    struct node *n=malloc(sizeof(struct node));
    struct node *t=*l;
    n->item=data;
    if(t==NULL)
    {
        n->next=n;
        *l=n;
        
    }
    else
    {
        n->next=t->next;
        t->next=n;
        *l=n;
    }
}
void insertAtfirst(struct node **l,int data)
{
    struct node *n=malloc(sizeof(struct node));
    struct node *t=*l;
    n->item=data;
    if(*l==NULL)
    {
        n->next=n;
        *l=n;
    }
    else
    {
        n->next=t->next;
        t->next=n;
    }
}
void insertNode(struct node **l,struct node *r,int data)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    if(*l==r)
    {
        n->next=(*l)->next;
        (*l)->next=n;
        *l=n;

    }
    else
    {
        n->next=r->next;
        r->next=n;
    }
}
struct node* search(struct node *l,int data)
{
    struct node *s;
    s=l->next;
    do
    {
        if(s->item==data)
        return s;
        s=s->next;
    } while (s!=l->next);
    return NULL;
}
void view(struct node *last)
{
    struct node *t;
    if(last==NULL)
        printf("\nList is Empty\n");
    else
        t=last->next;
    do
    {
        if(last!=NULL)
        printf("%d ",t->item);
        t=t->next;
    }
    while (t!=last->next);
    printf("\n");
}
void removeLast(struct node **l)
{
    struct node *s=(*l)->next;
    struct node *t;
    do
    {
        t=s;
        s=s->next;
    }
    while(s!=(*l));
    t->next=(*l)->next;
    *l=t;
    free(s);
}
void removeFirst(struct node **l)
{
    struct node *s=(*l)->next;
    if(*l==NULL)
        printf("\nNothing to delete\n");
    else
    {
        (*l)->next=s->next;
        free(s);
    }
}
void removeNode(struct node **l,struct node *r)
{
    struct node *s=(*l)->next;
    struct node *n;
    if(r==s)
    {
        (*l)->next=s->next;
        free(r);
    }
    else if(r==*l)
    {
        do
        {
            n=s;
            s=s->next;
        }
        while(s!=*l);
        n->next=(*l)->next;
        *l=n;
        free(r);
    }
    else
    {
        do
        {
            n=s;
            s=s->next;
        }
        while(s!=r);
        n->next=r->next;
        free(r); 
    }
}
int main()
{
    struct node *last=NULL;
    struct node *r,*i;
    insertAtfirst(&last,10);
    insertAtlast(&last,20);
    insertAtlast(&last,30);
    insertAtlast(&last,40);
    insertAtlast(&last,50);
    view(last);
    removeLast(&last);
    view(last);


    return 0;
}
