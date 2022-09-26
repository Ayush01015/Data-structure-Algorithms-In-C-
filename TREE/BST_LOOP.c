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
    n->left=NULL;
    n->item=data;
    n->right=NULL;
    if(*r==NULL)
    {
        *r=n;   
    }
    else
    {
        t=*r;
        while(1)
        {
            if(t->item==data)
            {
                //duplicate case
                printf("Duplicate value cannot be Inserted\n");
                free(n);
                break;

            }
            else if(t->item>data)
            {
                //left
                if(t->left==NULL)
                {
                    t->left=n;
                    break;
                }
                t=t->left;
            }
            else
            {
                //right
                if(t->right==NULL)
                {
                    t->right=n;
                    break;
                }
                t=t->right;
            }
        }
    }

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
    insert(&r,20);
    insert(&r,65); 
    inorder(r);
    
    return 0;
}
