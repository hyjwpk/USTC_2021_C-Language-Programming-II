#include <stdio.h>
#include <string.h>

int main()
{
    char target[55];
    char input[55];
    gets(target);
    while(gets(input)!=NULL)
    {
        int length=strlen(input),sum=0,i;//sum is the number of times
        for(i=0;i<length-1;i++)
        {
            char *search;//location of the first occurrence in the rest
            if((search=strstr(input+i,target))!=NULL) 
            {
                i=search-input;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}