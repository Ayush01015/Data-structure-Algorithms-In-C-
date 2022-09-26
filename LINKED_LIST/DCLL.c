#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    struct node *prev;
    int item;
    struct node *next;
};
void insertAtlast(struct node **s,int data)
{
    struct node *n=malloc(sizeof(struct node));
    n->item=data;
    if(*s==NULL)
    {
        *s=n;
        n->next=n;
        n->prev=n;
    }
    else
    {
        n->next=*s;
        n->prev=(*s)->prev;
        (*s)->prev->next=n;
        (*s)->prev=n;
    }
}
void insertAtfirst(struct node **s,int data)
{
    struct node *n=malloc(sizeof(struct node));
    n->item=data;
    if(*s==NULL)
    {
        n->next=n;
        n->prev=n;
        *s=n;
    }
    else
    {
        n->prev=(*s)->prev;
        n->next=*s;
        (*s)->prev->next=n;
        (*s)->prev=n;
        *s=n;
    }
}
void insertNode(struct node **s,struct node *t,int data)
{
    struct node *n=malloc(sizeof(struct node));
    n->item=data;
    if(t==*s)
    {
        n->prev=(*s)->prev;
        n->next=*s;
        t->prev=n;
        (*s)->prev->next=n;
        (*s)->prev=n;
        (*s)=n;   
    }
   else if(t==(*s)->prev)
    {
        n->next=t->next;
        n->prev=t;
        t->next=n;
        (*s)->prev=n;  
    }
    else
    {
        n->next=t->next;
        n->prev=t;
        t->next=n;
    }
}

struct node* search(struct node *s,int data)
{
    struct node *t;
    t=s->prev->next;
    do
    {
        if(s->item==data)
        return s;
        s=s->next;
    } while (s!=t);
    return NULL;
}
void view(struct node *s)
{
    struct node *t;
    if(s==NULL)
        printf("List is Empty\n");
    else
    {
        t=s->prev->next;
        do
        {
            printf("%d ",s->item);
            s=s->next;
        }
        while (s!=t);
    }
        printf("\n");
}
void removeFirst(struct node **s)
{
    struct node *r=*s;
    if((*s)==(*s)->prev)
    {
        free(r);
        *s=NULL;
    }
    else if(*s==NULL)
    {
        printf("List is Empty Nothing to Delete\n");
        
    }
    else
    {
        (*s)->next->prev=(*s)->prev;
        (*s)->prev->next=(*s)->next;
        (*s)=(*s)->next;
    }
    free(r);
}
void removeLast(struct node **s)
{
    struct node *t;
    struct node *r=(*s)->prev;
    if((*s)==(*s)->prev)
    {
        free(r);
        *s=NULL;
    }
    else if(*s==NULL)
        printf("List is Empty Nothing to Delete\n");
    else
    {
        t=r->prev;
        t->next=*s;
        (*s)->prev=t;
        free(r);
    }
}
void removeNode(struct node **s,struct node *r)
{
    struct node *t,*l,*m;
    if((*s)==(*s)->prev) //when only one node remaining and its pointing itself...
    {
        *s=NULL;
    }
    else if(r==(*s)->prev) //lastnode
    {
        l=(*s)->prev;
        m=l->prev;
        m->next=*s;
        (*s)->prev=m;
    }
    else if(r==*s) //FirstNode
    {
        r->next->prev=(*s)->prev;
        r->prev->next=(*s)->next;
        *s=r->next;
    }
    else    //Node
    {
        t=r->prev;
        t->next=r->next;
        r->next->prev=t;
    }
        free(r);
}
int menu()
{
    int choice;
    printf("1.Insert At First\n2.Insert At Last\n3.InsertNode\n4.Remove First\n5.Remove Last\n6.Remove Node\n7.Exit\nEnter Your Choice-->");
    scanf("%d",&choice);
    return choice;
}
int main()
{
    struct node *start=NULL;
    struct node *a;
    int data,Ndata;
    view(start);
    while(1)
    {
        system("cls");
        view(start);
        printf("\n");
        switch(menu())
        {
            case 1:
                printf("Enter a number to Insert at first in the list- ");
                scanf("%d",&data);
                insertAtfirst(&start,data);
                break;
            case 2:
                printf("Enter a number to Insert at Last in the list- ");
                scanf("%d",&data);
                insertAtlast(&start,data);  
                break; 
        
           case 3:
                printf("Insert After\n");
                printf("Enter a number to Insert Node in the list- ");
                scanf("%d",&Ndata);
                printf("Enter a Number After which you want to Enter New Node\n");
                scanf("%d",&data);
                a=search(start,data);
                insertNode(&start,a,Ndata);  
                break;
            case 4:
                printf("Delete First Node\n");
                removeFirst(&start);
                break;
            case 5:
                printf("Delete Last Node\n");
                removeLast(&start);
                break;
            case 6:
                printf("Delete Particular node\n");
                printf("Enter a number to Search Node\n");
                scanf("%d",&data);
                a=search(start,data);
                removeNode(&start,a);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
       }
       getch();
    }       
    return 0;
}
// finish with bugs...
//insert/remove node..fun()
