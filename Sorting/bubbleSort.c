#include<stdio.h>

int main()
{
    int i,r,t;
    int a[15]={55,81,32,90,16,25,66,72,89,43,15,7,88,12};
    //int a[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(r=0;r<=13;r++)
    {
        for(i=0;i<=13-r-1;i++)
        {
            if(a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    printf("Sorted Array--> ");
    for(i=0;i<=13;i++)
        printf("%d ",a[i]);
    return 0;
}
