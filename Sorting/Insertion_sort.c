#include<stdio.h>

int main()
{
    int i,n=5,j,t;
    int a[15]={7,2,91,77,3};
    for(i=1;i<=n-1;i++)
    {         
        t=a[i];
        j=i-1;
            while(j>=0 && a[i]<t)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=t;
    }
    printf("Sorted Array--> ");
    for(i=0;i<=4;i++)
        printf("%d ",a[i]);    
    return 0;
}
