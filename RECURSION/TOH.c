#include<stdio.h>
#include<math.h>
void TOH(int n,char beg,char aux,char end)
{
    if(n>0)
    {
        TOH(n-1,beg,end,aux);
        {
            printf("%c->%c\n",beg,end);
        }
        TOH(n-1,aux,beg,end);
    }
}
int main()
{
    int n,m;
    printf("Enter NO. OF DISC-->");
    scanf("%d",&n);
    m=pow(2,n)-1;
    TOH(n,'A','B','C');
    printf("MOVES=%d",m);
    return 0;
}
