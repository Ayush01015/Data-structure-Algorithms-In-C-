#include<stdio.h>

int main()
{
    int i,r,n=14,t,flag=0;
    int a[15]={55,81,32,90,16,25,66,72,89,43,15,7,88,12};
    for(r=0;r<=13;r++)
    {
        for(i=0,flag=0;i<=13-r-1;i++)
        {
            if(a[i]>a[i+1])
            {
                flag=1;
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
        if(flag==0)
            break;
    }
    for(i=0;i<=13;i++)
        printf("%d ",a[i]);
    return 0;
}
