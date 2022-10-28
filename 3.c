#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dic
{
    char en[15];
    char fn[15];
}dic;

dic dictionary[100005];

int compare(const void *p1, const void *p2)
{
    return strcmp(((dic *)p1)->fn,((dic *)p2)->fn);
}

char * search(char *des,int length)
{
    int low = 0, high = length-1, middle = 0;
	while(low <= high) 
    {
		middle = (low + high)/2;
        int bool=strcmp(des,dictionary[middle].fn);
        if(bool>0)
        {
            low=middle+1;
        }
        else if(bool<0)
        {
            high=middle-1;
        }
        else if(bool==0)
        {
            return dictionary[middle].en;
        }
	}
    return "eh";
}

int main()
{
    
    int length=0;
    char line[30];
    gets(line);
    do
    {
        int i,j;
        for(i=0;line[i]!=' ';i++)
        {
            dictionary[length].en[i]=line[i];
        }
        for(i=i+1,j=0;line[i]!='\0';i++,j++)
        {
            dictionary[length].fn[j]=line[i];
        }
        length++;
        gets(line);
    } while (line[0]!='\0');
    qsort(dictionary,length,sizeof(dic),compare);


while (~scanf("%s",line))
    {
        printf("%s\n",search(line,length));
    }
}