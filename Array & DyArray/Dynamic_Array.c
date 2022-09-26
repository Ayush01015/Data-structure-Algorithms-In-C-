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
        for(i=arr->lastIndex;index<=arr->lastIndex;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastIndex+=1;
    }   
}

void showdata(struct Array *arr)
{
    for(int i=0;i<=arr->lastIndex;i++)
        printf("%d ",arr->ptr[i]);
    printf("\n");
}
void append(struct Array *arr,int data)
{
    if(arr->lastIndex==arr->capacity-1)
    {
        doubleArray(arr);
        arr->ptr[arr->lastIndex]=data;
    }
    else 
    {
        arr->lastIndex+=1;
        arr->ptr[arr->lastIndex]=data;
    }
}
int getItem(struct Array *arr,int index)
{
    if(index<0||index>arr->lastIndex+1)
    {   
        return -1;// -1 means invalid index
        printf("Invalid Index\n");
    }  
    else
        return arr->ptr[index];
}
int count(struct Array *arr)
{
    return arr->lastIndex+1;
}
void editItem(struct Array *arr,int index,int data)
{
    if(index<0||index>arr->lastIndex+1)
        printf("\nInvalid Index\n");
    else
    {
        arr->ptr[index]=data;
    }
}
void removeItem(struct Array *arr,int index)
{
    if(index<0||index>arr->lastIndex+1)
        printf("\nInvalid Index\n");
    else
    {
        for(int i=index;i<arr->lastIndex;i++)
            arr->ptr[i]=arr->ptr[i+1];
        arr->lastIndex-=1;
    }
}
int Search(struct Array *arr,int data)
{
    for(int i=0;i<=arr->lastIndex;i++)
        if(arr->ptr[i]==data)
            return i;
        return -1; //Not found
}

int main()
{
    struct Array *arr;
    arr=CreateArray(8);
    insert(arr,0,10);
    insert(arr,2,20);
    printf("lastIndex=%d\n",arr->lastIndex);
    showdata(arr);
    printf("capacity=%d",arr->capacity);
    return 0;
}
