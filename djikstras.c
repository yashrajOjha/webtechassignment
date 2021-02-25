#include<stdio.h>
#include<time.h>
#define infinity 999
void djik(int n,int v, int cost[10][10],int dist[])
{
    int i,u,count,w,flag[10],min;
    for(i=1;i<=n;i++)
        flag[i]=0;
        dist[i]=cost[v][i];
    count=2;
    while(count<=n)
        {
            min=99;
            for(w=1;w<=n;w++)
            {
                if(dist[w]<min && !flag[w])
                {
                    min= dist[w];
                    u=w;
                } }
            flag[u]=1;
            count++;
            for(w=1;w<=n;w++)
            {
                if(dist[u]+cost[u][w]<dist[w] && !flag[w])
                {
                    dist[w]=dist[u]+cost[u][w];
                }

                }
            }
}
void main()
{
    int n,v,i,j,cost[10][10],dist[10],st,et;
    printf("Enter the number of nodes");
    scanf("%d",&n);
    printf("Enter the cost matrix");
    for (i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=infinity;
            }
        }
    }
    printf("Enter the source node\n");
    scanf("%d",&v);
    st=clock();
    djik(n,v,cost,dist);
    printf("Shortest path");
    for(i=1;i<=n;i++)
    {
        if(i!=v)
        {
            printf("%d->%d,cost=%d",v,i,dist[i]);
        }
    }
    et=clock();
    printf("Start time =%d\nEnd time=%d",st,et);
}
