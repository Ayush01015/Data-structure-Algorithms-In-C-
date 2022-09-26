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

void insertInHeap(int heap[],int *hs,int data)
{
    int index,parindex;
    *hs=*hs+1;
    index=*hs-1;
    while(index>0)
    {
        parindex=(index-1)/2;
        if(data>heap[parindex])
            heap[index]=heap[parindex];
        else
            break;
        index=parindex;
    }
    heap[index]=data;
    //printf("capacity=%d ",arr->capacity);
}
int delete_in_heap(int heap[],int *hs)
{
    int index,item,temp,leftIndex,rightIndex;
    item=heap[0];
    temp=heap[*hs-1];
    *hs=*hs-1;
    index=0;
    while(index<=*hs-1)
    {
        leftIndex=2*index+1;
        rightIndex=2*index+2;
        if(leftIndex>*hs-1)
            break;
        if(rightIndex>*hs-1)
        {
            if(temp<heap[leftIndex])
                heap[index]=heap[leftIndex];
            else
                break;
            index=leftIndex;
        }
        if(heap[leftIndex]>heap[rightIndex])
        {
            if(temp<heap[leftIndex])
                heap[index]=heap[leftIndex];
            else
                break;
            index=leftIndex;
        }
        else
        {
            if(temp<heap[rightIndex])
                heap[index]=heap[rightIndex];
            else
                break;
            index=rightIndex;
        }
    }
        heap[index]=temp;
        return item;
}
void heap_sort(int heap[],int **hs,struct Array *arr)
{
    int j=arr->capacity,data;
    while(j>=0)
    {
        if(hs>0)
        {

            data=delete_in_heap(heap,*hs);
            j--;
            heap[j]=data;
            
        }
    }
}

int main()
{
    struct Array *arr;
    int j,data,i,*heap,hs=0;
    arr=CreateArray(6);
    heap=malloc(sizeof(int)*arr->capacity);
    insert(arr,0,10);
    insert(arr,1,20);
    insert(arr,2,30);
    insert(arr,3,40);
    insert(arr,4,50);
    insert(arr,5,60);
    insert(arr,6,70);
    insert(arr,7,80);
    insert(arr,8,90);
    insert(arr,9,100);
    showdata(arr);
    // printf("lastindex=%d",arr->lastIndex);
    for(i=0;i<=arr->lastIndex;i++)
    insertInHeap(heap,&hs,arr->ptr[i]);

    printf("\nHEAP ARRAY-->\n");
        printf("\nhs=%d\n",hs);
    for(i=0;i<hs;i++)
    printf("%d ",heap[i]);

    // if(hs>0)
    //     data=delete_in_heap(heap,&hs);

    // printf("\nAFTER DELETE HEAP ARRAY-->\n");
    // for(i=0;i<hs;i++)
    // printf("%d ",heap[i]);

    // heap_sort(heap,*hs,arr);

    // printf("\nSORTED HEAP ARRAY-->\n");
    // for(i=0;i<hs;i++)
    // printf("%d ",heap[i]);
    j=arr->lastIndex+1;
    printf("\nj=%d",j);
    while(j>0)
    {
        if(hs>0)
        {
            //printf("\n-00-\n");

            data=delete_in_heap(heap,&hs);
            j--;
            heap[j]=data;
                            
        }
    }
    printf("\nafter delete hs=%d",hs);
    printf("\nSORTED HEAP ARRAY-->\n");
    for(i=0;i<=arr->lastIndex;i++)
    printf("%d ",heap[i]);
    return 0;
}
