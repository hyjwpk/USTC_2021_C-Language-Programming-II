#include <stdio.h>
#include <string.h>
#define MAXCHAR 100

char result[10*MAXCHAR],expression[MAXCHAR];
int position;

int compare(char sym)
{
	switch (sym)
	{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default : return 0;
	}
}

void transfer(char symbol,char condition)// The expression in result is in reverse order,condition is a symbol of right(1) or left(0)
{
	char symnow=expression[position--];
	if(symnow>='0'&&symnow<='9') result[strlen(result)]=symnow;
	else
	{
		//Judge whether it is necessary to add the brackets
		if((compare(symnow)<compare(symbol))||(compare(symnow)==compare(symbol)&&condition==1))
		{
			result[strlen(result)]=')';
			transfer(symnow,1);
			result[strlen(result)]=symnow;
			transfer(symnow,0);
			result[strlen(result)]='(';
		}
		else
		{
			transfer(symnow,1);
			result[strlen(result)]=symnow;
			transfer(symnow,0);
		}
	}
}

int main()
{
	gets(expression);
	position=strlen(expression)-1;
	transfer(0,0);
	for(int i=strlen(result)-1;i>=0;i--) putchar(result[i]);
}