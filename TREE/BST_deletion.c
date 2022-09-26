#include<stdio.h>
#include<stdlib.h>
struct BST
{
    struct BST *left;
    int item;
    struct BST *right;
};
void inorder(struct BST *r)
{
    if(r!=NULL)
    {
        if(r->left!=NULL)
            inorder(r->left);
                printf("%d ",r->item);
        if(r->right!=NULL)
            inorder(r->right);
    }
}
void insert(struct BST **r,int data)
{
    struct BST *t,*n=malloc(sizeof(struct BST));
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(*r==NULL)
        *r=n;
    else
    {
        t=*r;
        if(t->item==data)
        {
            printf("Duplicate item cannot be inserted\n");
            free(n);
        }
        else if(t->item>data)
        {
            if(t->left==NULL)
                t->left=n;
            else
                insert(t->left,data);
        }
        else
        {
            if(t->right==NULL)
                t->right=n;
            else
                insert(t->right,data);
        }
    }
}
struct BST* search(struct BST *r,int data)
{
    if(r==NULL)
        return NULL;
    if(r->item==data)
        return r;
    else if(r->item>data)
        search(r->left,data);
    else if(r->item<data)
        search(r->right,data);
    // else
    //     printf("Item not found\n");
}
void delete(struct BST **r,int data)
{
    struct BST *parptr,*ptr;
    if(*r==NULL)
        printf("Underflow\n");
    else
    {
        parptr=NULL;
        ptr=*r;
        while(ptr->item!=data&&ptr!=NULL)
        {
            if(ptr->item>data)
            {
                parptr=ptr;
                ptr=ptr->left;
            }
            else
            {
                parptr=ptr;
                ptr=ptr->right;
            }
        }
        if(ptr==NULL)
            printf("Data not found\n");
        else
        {
            if(ptr->left==NULL&&ptr->right==NULL) //No child case
            {
                if(parptr==NULL)
                    *r=NULL;
                else if(ptr==parptr->left)
                    parptr->left=NULL;
                else 
                    parptr->right=NULL;
                free(ptr);
            }
            else if(ptr->left==NULL||ptr->right==NULL) // only 1 child case
            {
                if(parptr==NULL)
                {
                    if(ptr->left!=NULL)
                        *r=ptr->left;
                    else
                        *r=ptr->right;
                }
                else if(ptr==parptr->left) 
                {
                    if(ptr->left!=NULL)
                        parptr->left=ptr->left;
                    else
                        parptr->left=ptr->right;
                }
                else
                {
                    if(ptr->left!=NULL)
                        parptr->right=ptr->left;
                    else
                        parptr->right=ptr->right;
                }
                free(ptr);
            }
            else
            {
                delete2();
            }
        }
    }
}
int main()
{
    struct BST *r=NULL;
    struct BST *s;
    insert(&r,50);
    insert(&r,30);
    insert(&r,70);
    insert(&r,10);
    insert(&r,40);
    insert(&r,60);
    inorder(r);
    
    return 0;
}