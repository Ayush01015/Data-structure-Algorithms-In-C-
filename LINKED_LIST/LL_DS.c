#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
struct node
{
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
        *s=n;
    else
    {
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void insertAtfirst(struct node **s,int data)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void insertAfter(struct node *t,int data)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->next=t->next;
    t->next=n;
}
void deleteFirst(struct node **s)
{
    struct node *t;
    t=*s;
    *s=t->next;
    free(t);
}
void deleteLast(struct node **s)
{
    struct node *t,*t1;
    t=*s;
    t1=NULL;
    if(*s==NULL)
        printf("Nothing to Delete\n");
    else
    {
        while(t->next!=NULL)
        {
            t1=t;
            t=t->next;
        }
        if(t1!=NULL)
            t1->next=NULL;
        else
            *s=NULL;    
    }
    free(t);
}
void deleteNode(struct node **s,struct node *r)
{
    struct node *t;
    if(*s==r)
      *s=r->next;
    else
    {
       t=*s;
       while(t->next!=r)
            t=t->next;
        t->next=r->next;
    }
   free(r);   
}
struct node* SearchNode(struct node *s,int data)
{
    while(s)
    {
        if(s->item==data)
            return s;
        s=s->next;
    }
    return NULL;
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
int main()
{
    struct node *start=NULL;
    insertAtfirst(&start,10);
    insertAtlast(&start,20);
    insertAtlast(&start,30);
    insertAtlast(&start,40);
    insertAtlast(&start,50);
    insertAtlast(&start,60);
    insertAtlast(&start,70);
    insertAtlast(&start,80);
    insertAtlast(&start,90);
    insertAtlast(&start,100);
    view(start);
    deleteFirst(&start);
    view(start);

    
    return 0;
}