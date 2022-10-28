#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 500
int input[MAXN*MAXN],map[MAXN][MAXN],empty[MAXN][MAXN],gold[MAXN][MAXN];
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))

int main()
{
    int n;
    for(n=0;(scanf("%d",&input[n]))!=EOF;n++);
    n=sqrt(n);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            map[i][j]=input[(i-1)*n+(j-1)];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            empty[i][j]=-1;
    gold[1][1]=map[1][1];

    for(int step=1;step<=2*(n-1);step++)
    {
        int temp[MAXN][MAXN];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            temp[i][j]=-1;
        for(int ax=MAX(0,step+1-n);ax<=MIN(step,n-1);ax++)
            for(int bx=MAX(0,step+1-n);bx<=MIN(step,n-1);bx++)
            {
                int ay=step-ax,by=step-bx;
                if(map[1+ay][1+ax]==-1||map[1+by][1+bx]==-1) continue;
                for(int dax=-1;dax<=0;dax++)
                    for(int dbx=-1;dbx<=0;dbx++)
                        if(dax+ax+1>=1&&dbx+bx+1>=1)
                            temp[1+ax][1+bx]=MAX(temp[1+ax][1+bx],gold[1+ax+dax][1+bx+dbx]);
                if(temp[1+ax][1+bx]!=-1) temp[1+ax][1+bx]+=map[1+ay][1+ax]+(ax!=bx)*map[1+by][1+bx];
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            gold[i][j]=temp[i][j];
    }
    printf("%d",MAX(0,gold[n][n]));
}