#include<stdio.h>

int main()
{
    int i,j,r,t;
    //int a[15]={90,66,7,15,2};
    int a[15]={55,81,32,90,16,25,66,72,89,43,15,7,88,12};
    
    for(i=0;i<=14-1;i++)
    {
        for(j=i;j<=14-2;j++)
        {
            if(a[i]>a[j+1])
            {
                t=a[i];
                a[i]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("Sorted Array--> ");
    for(i=0;i<=13;i++)
        printf("%d ",a[i]);
    return 0;
}
