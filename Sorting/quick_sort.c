#include<stdio.h>

int Quick(int a[],int l,int u)
{
    int left,right,loc,t;
    left=loc=l;
    right=u;
while(left<right)
{
    while(left<right&&a[loc]<a[right])
        right--;
    if(left==right)
        break;
    else
    {
    //swap
        t=a[loc];
        a[loc]=a[right];
        a[right]=t;
    //update loc
        loc=right;
    }
    while(left<right&&a[left]<a[loc])
        left++;
    if(left==right)
        break;
    else
    {
    //swap
        t=a[left];
        a[left]=a[loc];
        a[loc]=t;
    //update loc
        loc=left;
    }      
}
    return loc;

}
void quick_sort(int a[],int l,int u)
{
    int loc;
    loc=Quick(a,l,u);
    if(l<loc-1)
        quick_sort(a,l,loc-1);
    if(loc+1<u)
        quick_sort(a,loc+1,u);

}
int main()
{
    int a[10]={45,10,34,56,36,90,12,5,78,22};
    quick_sort(a,0,9);
    printf("Sorted Array--> ");
    for(int i=0;i<=9;i++)
        printf("%d ",a[i]);
    return 0;
}
