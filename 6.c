#include <stdio.h>
#define MAX(a,b) (a>b?a:b)

int main()
{
    int i,k,length[105]={0},max1=0,max2=0;//max1 is Maximum without end,max2 is Maximum include end
    for(i=0;(scanf("%d",&length[i]))!=EOF;i++);
    for(k=0;k<i;k++)
    {
        int max1o=max1,max2o=max2;
        max1=MAX(max1o,max2o);
        max2=max1o+length[k];
    }
    printf("%d",MAX(max1,max2));
}