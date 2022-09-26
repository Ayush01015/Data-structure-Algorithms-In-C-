#include<stdio.h>
#include<stdlib.h>
struct QueueLL
{
    int item;
    struct QueueLL *next;
};
void insertAtlast(struct QueueLL **s,int data)
{
    struct QueueLL *n;
    n=malloc(sizeof(struct QueueLL));
    n->item=data;
    
}
int main()
{
    
    return 0;
}
