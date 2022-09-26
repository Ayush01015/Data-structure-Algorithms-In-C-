#include<stdio.h>
#include<stdlib.h>


struct Graph
{
    int V;
    int G;
    int **Adj;
};

struct Graph* CreateGraph(int Nv)
{
    int i;
    struct Graph *g;
    g=malloc(sizeof(struct Graph));
    g->V=Nv;
    g->G=Nv+1;
    g->Adj=(int**)malloc((sizeof(int*))*Nv);
    for(i=0;i<Nv;i++)
        g->Adj[i]=(int*)malloc((sizeof(int))*Nv);
    return g;
}

int menu()
{
    char c;
    printf("\nEnter Y/N-->");
    scanf("%c",&c);
    if(c==121 || c==89)
        return 1;
    else if(c==110 || c==78)
        return 0;
}

void insertEdgeData(struct Graph *g)
{
    int i,j,c;
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            printf("i=%d j=%d c=%d\n",i,j,c);
            printf("Do V%d & V%d Have Edge Between Them\n",i+1,j+1);
            printf("Enter 1 for yes and 0 for No\n");
            scanf("%d",&c);
            if(c==121 || c==89)
                g->Adj[i][j]=1;
            if(c==78 || c==110)
                g->Adj[i][j]=0;
        }
    }
}
void Array(struct Graph *g)
{
        int i,j;
        char c;
    int a[5][5];
    printf("%d",g->V);
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            printf("Do V%d & V%d Have Edge Between Them\n",i+1,j+1);
            scanf("%d",&g->Adj[i][j]);

        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            // printf("Do V%d & V%d Have Edge Between Them\n",i+1,j+1);
            printf("%d ",g->Adj[i][j]);
        }
        printf("\n");
    }

}
int main()
{
    int i,j;
    struct Graph *g=NULL;
    g=CreateGraph(5);    
    insertEdgeData(g);
    // Array(g);
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            // printf("Do V%d & V%d Have Edge Between Them\n",i+1,j+1);
            printf("%d ",g->Adj[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}
