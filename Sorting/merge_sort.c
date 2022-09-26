#include<stdio.h>

void merge(int a[],int mid,int low,int high)
{
    int i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }    

    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }

    for(i=low;i<=high;i++)
        a[i]=b[i];

}

void merge_sort(int a[],int l,int h)
{  
    int mid;                     
    if(l<h)
    {
        mid=(l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge(a,mid,l,h);
    }
}
  
int main()
{
    int i,a[]={100,20,150,90,70,30,10,140,80,120,40,60,110,50,130}; 
    merge_sort(a,0,14);
    for(i=0;i<=14;i++)
        printf("%d ",a[i]);
    return 0;
}

// void merge(int a[],int b[],int c[],int asize,int bsize)
// {
//     int i,j,k;
//     i=j=k=0;

//     while(i<asize && j<bsize)
//     {
//         if(a[i]<b[j])
//         {
//             c[k]=a[i];
//             i++; 

//         }
//         else
//         {
//             c[k]=b[j];
//             j++;
//         }
//             k++;
//     }

//     if(j==bsize && i<asize)
//     {
//         while(i<asize)
//         {
//             c[k]=a[i];
//             k++;
//             i++;
//         }    
//     }
//     if(i==asize && j<bsize)
//     {
//         while(j<bsize)
//         {
//             c[k]=b[j];
//             j++;
//             k++;
//         }
//     }
// }