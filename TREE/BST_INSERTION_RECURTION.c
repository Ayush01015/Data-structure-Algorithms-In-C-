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
struct BST* CreateTreeNode(struct BST **r,int data)
{
    struct BST *n=malloc(sizeof(struct BST));
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void insert(struct BST **r,int data)
{
    struct BST *n=malloc(sizeof(struct BST));
    struct BST *t;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(*r==NULL)
        *r=n;
    else
    {
        t=*r;
        if(t->item==data)
            printf("Duplicate item cannot be inserted\n");
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
int main()
{
    struct BST *r=NULL;
    struct BST *s;
    insert(&r,50);
    insert(&r,20);
    insert(&r,70);
    insert(&r,10);
    insert(&r,60);
    insert(&r,90);
    insert(&r,65);
    inorder(r);
    s=search(r,60);
    if(s!=NULL){
        printf("\nFound: %d",s->item);
    }
    else
        printf("\nData not Found");

    return 0;
}
