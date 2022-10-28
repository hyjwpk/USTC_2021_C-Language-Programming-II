#include <stdio.h>
#include <string.h>
char num1[1000],num2[1000];


void multiply(void) //num1=num1*num2 
{
	int len1 = strlen(num1),len2 = strlen(num2),i,j;
    char temp1[1000]={0},temp2[1000]={0};
    int result[1000]={0};

	for (i=0;i<len1;i++)
		temp1[len1-1-i]=num1[i]-'0';
	for (i=0;i<len2;i++)
		temp2[len2-1-i]=num2[i]-'0';
		
	for (i=0;i<len1; i++)
		for (j=0;j<len2 ; j++)
			result[i+j]+=temp1[i]*temp2[j];
		
	int maxlen=len1+len2-1; 
	for (i=0;i<maxlen;i++)
	{
		result[i+1]+=result[i]/10;
		result[i]%=10;
	}
	if (result[maxlen]>0) maxlen++;
    for(i=0;i<maxlen;i++)
        num1[i]=result[maxlen-1-i]+'0';
    num1[i]=0;
}

int main()
{
    char base[10];
    int times;
    while(scanf("%s%d",base,&times)==2)
    {
        int len=strlen(base),i,j,dot=0,num=0;
        //Calculate decimal digits
        for(i=0;i<len&&base[i]!='.';i++);
        for(j=len-1;base[j]=='0'&&base[j]!='.';j--);
        dot=j-i;
        //delete decimal point and store in type of integer
        for(i=0;base[i]!='.';i++) 
        {
            num*=10;
            num+=base[i]-'0';
        }
        for(i+=1,j=0;j!=dot;i++,j++)
        {
            num*=10;
            num+=base[i]-'0';
        }
        //Convert int to string
        int temp=num;
        for(i=0;temp!=0;i++,temp/=10);
        num1[i]=num2[i]=0;
        for(i-=1;num!=0;i--)
        {
            num1[i]=num2[i]=num%10+'0';
            num/=10;
        }
        //Calculate result
        dot*=times;
        for(;times>1;times--) multiply();
        //Output results and Add decimal point
        int a=strlen(num1)-dot;
        for(i=0;i<a;i++) putchar(num1[i]);
        if(dot) putchar('.');
        for(j=-a;j>0;j--) putchar('0');
        for(;num1[i]!=0;i++) putchar(num1[i]);
        putchar('\n');
    }
	return 0;
}