# OJ习题报告(上机2)

## 题目与要求

### 题目描述

Time limit: 1000 ms

Memory limit: 256 MB

Standard I/O

仔细学习老师关于“递归”的ppt之后,你学会了如何将一个逆波兰式转换回原本的表达式；只是,有些时候,你会输出大量多余的括号。
这次,我们仍旧要将一个逆波兰式转换回一个正常的表达式—— 但不能输出任何多余的括号 。

【警告】可以使用栈,但不允许使用C++的std::stack

[【逆逆波兰式】题面中的“多余”说明](https://git.ustc.edu.cn/programming-ii-spring2021/DiscussionBoard/-/issues/15)

### 输入描述

输入有且只有一行,行末回车符前只会出现“+”“-”“*”“/”和数字“0”到“9”；数字至少出现一次,每一个数字代表一个单独的数值（原表达式和逆波兰式中的数都是一位数）。

### 输出描述

输出包括一行,为输入逆波兰式对应的原表达式,但不能有任何多余的括号！

- 样例输入 123++
    样例输出 1+(2+3)

- 样例输入 12+3+
    样例输出 1+2+3

- 样例输入 12+34+*
    样例输出 (1+2)*(3+4)

- 样例输入 123*+
    样例输出 1+2*3


## 具体设计

该部分**简单介绍**题目实现的细节,例如,包括哪些函数,函数参数是什么,作用是什么等。

主要思路是使用分治法来将逆波兰式拆分成多个子式,递归地拆分直到拆到单个的数字或者符号,再将各部分按顺序拼接就得到了原表达式

```C++
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
```

`symbol`表示当前拆分的式子的连接符号,`condition`用于表示函数操作的子式位于符号的左侧（0）或是符号的右侧（1）,`result`用于存放结果,`expression`存放初始的表达式,`position`是全局变量表示现在读取的字符位置

`int compare(char sym)`函数用于将符号转化为优先级返回

```C++
int compare(char sym)
{
	switch (sym)
	{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default : return 0;
	}
}
```

## 实验过程

该部分介绍实验中遇到的bug与报错

- bug内容
    输出了多余的括号

- bug原因
    未考虑基本运算顺序是从左到右的,这会使得在左侧的表达式有时不需要加括号

- 解决方案
    加入`condition`来标识表达式在符号的两侧位置来判断是否需要加括号

## 实验总结

该部分介绍实验中的收获。

通过这次上机实验了解了逆波兰式这种表达式表示方法,同时对使用分治以及递归解决问题有了更深入的理解
