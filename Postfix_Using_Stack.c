#include<stdio.h>
#include<ctype.h>
#include<String.h>
#define max 30
int i=0,j=0,top=-1,x,p;
char ch;
char inf[100],pos[100];
char stack[100];
void push(char value)
{
	if(top == max-1)
	{
		printf("Stack is Overflow ");
	}
	else
	{
		top++;
		stack[top] = value;
	}
		
}
int pop()
{
	if(top == -1)
	{
		printf("Stack Is Underflow");
	}
	else
	{
		x = stack[top];
		top--;
	}
	return x;
}
int precdence(char c)
	{
		//int x;
		if(c=='(')
		{
			p = 100;	
		}
	    if(c=='^')
		{
			p = 500;		
		}
		if(c=='*'||c=='/'||c=='%')
		{
			p = 400;	
		}
		if(c=='+'||c=='-')
		{
			p= 300;
		}
		return p;	
	}	
int main()
{
	printf("Enter the expression :: ");
	gets(inf);
	printf("The expression is :: %s",inf);
	push('(');
	while(inf[i]!='\0')
	{
		if(isalpha(inf[i]))
		{
			pos[j]=inf[i];
			j++;	
		}
		else if(inf[i] == '(')
		{
			push(inf[i]);
		}
		else if(inf[i]==')')
		{
			x = pop();
			while(x !='(')
			{
				pos[j] = x;
				j++;
				pop();	
			}	
		}
		else
		{
			
			while(precdence(stack[top]) >= precdence(inf[i]))
				{
					x = pop();
				    pos[j] = x;
				    j++;
				    //push(inf[i]);
				}
					
					
				while(precdence(stack[top]) < precdence(inf[i]))
				{
						push(inf[i]);
				}
			
						
		}
		i++;	
	}
	printf("The postfix expression is :: %s",pos);
}	