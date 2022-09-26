#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Array
{
    int capacity;
    int lastIndex;
    int *ptr;
};
struct Array* CreateArray(int cap)
{
    struct Array *arr;
    arr=malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=malloc(sizeof(int)*cap);
    return arr;
}
void doubleArray(struct Array *arr)
{
    int *t,i;
    arr->capacity*=2;
    t=malloc(sizeof(int)*arr->capacity);
    for(i=0;i<=arr->lastIndex;i++)
        t[i]=arr->ptr[i];
    free(arr->ptr);
    arr->ptr=t;
}
void halfArray(struct Array *arr)
{
    int *t,i;
    arr->capacity/=2;
    t=malloc(sizeof(int)*arr->capacity);
    for(i=0;i<=arr->lastIndex;i++)
        t[i]=arr->ptr[i];
    free(arr->ptr);
    arr->ptr=t;
}
void insert(struct Array *arr,int index,int data)
{
    int i;
    if(index<0||index>arr->lastIndex+1)
        printf("\nInvalid Index\n");
    else if(arr->lastIndex==arr->capacity-1)
    {
        doubleArray(arr);
        arr->ptr[index]=data;
        arr->lastIndex+=1;
    }
    else
    {
        for(i=arr->lastIndex;index<=i;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastIndex+=1;
    }   

    int *t,l;
    t=malloc(sizeof(int)*arr->lastIndex+1);
    for(l=0;l<=arr->lastIndex;l++)
        t[l]=arr->ptr[l];
    free(arr->ptr);
    arr->ptr=t;

}

void showdata(struct Array *arr)
{
    for(int i=0;i<=arr->lastIndex;i++)
        printf("%d ",arr->ptr[i]);
    printf("\n");
}

int main()
{
    struct Array *arr;
    arr=CreateArray(1);
    insert(arr,0,10);
    insert(arr,1,20);
    insert(arr,2,30);
    insert(arr,3,40);
    insert(arr,4,50);
    // insert(arr,2,300);
    printf("lastIndex=%d\n",arr->lastIndex);
    showdata(arr);
    printf("capacity=%d",arr->capacity);
    return 0;
}
