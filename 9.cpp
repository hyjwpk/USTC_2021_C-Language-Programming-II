#include <cstdio>
#include <iostream>
#include <algorithm>
int a[15]={1,2,3,4,5,6,7,8,9};
using namespace std;
int main() 
{
    int n,k;
    scanf("%d%d", &n, &k);
    k--;
    while (k--)   next_permutation(a, a + n);
    for (int i=0;i<n;i++)   printf("%d", a[i]);
    return 0;
}