#include<stdio.h>

int binary_search(int a[],int l,int u,int item)
{
    int m=(l+u)/2;
    if(a[m]==item)
        return item;
    if(a[m]>=item)
        binary_search(a,0,m,item);
    else
        binary_search(a,m+1,u,item);

}
int main()
{
    int i,a[10]={10,20,30,40,50,60,70,80,90,100};
    int data;
    data=binary_search(a,0,9,90);
    printf("Data=%d",data);
    
    
    return 0;
}
