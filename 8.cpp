#include <cstdio>
#include <iostream>
#include <algorithm>
int a[15]={1,2,3,4,5,6,7,8,9},chartable[15];
using namespace std;
int main() 
{
    int i;
    for(i=0;(scanf("%d",&chartable[i]))!=EOF;i++);
    do
    {
        for (int j=0;j<i;j++) printf("%c", chartable[a[j]-1]+'0');
        putchar('\n');
    }while (next_permutation(a, a + i));
    return 0;
}