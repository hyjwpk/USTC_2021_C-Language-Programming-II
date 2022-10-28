#include<stdio.h>
#define MAX 55

int roomnum,space[MAX*MAX],maxspace,visit[MAX][MAX];

struct Room
{
    char s,n,w,e;
} room[MAX][MAX];

void dfs(int i,int j)
{
    if(visit[i][j]>0) return;
    visit[i][j]=roomnum;
    space[roomnum]++;
    //If there is not a wall, enter the adjoining room
    if(room[i][j].s==0) dfs(i+1,j);
    if(room[i][j].n==0) dfs(i-1,j);
    if(room[i][j].w==0) dfs(i,j-1);
    if(room[i][j].e==0) dfs(i,j+1);
}

int main()
{
    int n,m,wall,removei,removej,direction;
    scanf("%d %d",&m,&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&wall);
            //1=1<<0 2=1<<1 4=1<<2 8=1<<3
            if(wall&1<<0) room[i][j].w=1;
            if(wall&1<<1) room[i][j].n=1;
            if(wall&1<<2) room[i][j].e=1;
            if(wall&1<<3) room[i][j].s=1;
        }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(visit[i][j]==0)
            {
                roomnum++;
                dfs(i,j);
            }
    //maxspace is the maximum space of the current room
    for(int i=1;i<=roomnum;i++) maxspace=space[i]>maxspace?space[i]:maxspace;
    printf("%d\n%d\n",roomnum,maxspace);

    //maxspace is the maximum space of the expanded room
    maxspace=0;
    for(int j=m-1;j>=0;j--)
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&visit[i][j]!=visit[i+1][j]&&space[visit[i][j]]+space[visit[i+1][j]]>=maxspace)
            {
                maxspace=space[visit[i][j]]+space[visit[i+1][j]];
                removei=i+1;removej=j;direction='N';
            }
            if(j-1>=0&&visit[i][j]!=visit[i][j-1]&&space[visit[i][j]]+space[visit[i][j-1]]>=maxspace)
            {
                maxspace=space[visit[i][j]]+space[visit[i][j-1]];
                removei=i;removej=j-1;direction='E';
            }
        }
    printf("%d\n%d %d %c\n",maxspace,removei+1,removej+1,direction);
}