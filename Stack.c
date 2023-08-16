#include<stdio.h>
#define max 5
int stack[max];
int top=-1;
int x,i;
void push()
{
	printf("Enter the number you want to input :: \n");
	scanf("%d",&x);
	if(top==max-1)
	{
		printf("Stack Overflow \n");
		return;
	}
	top++;
	stack[top] = x;
}
int pop()
{
	if(top == -1);
	{
		x = -99;
	}
	x = stack[top];
	top--;
	return x;
}
void display()
{
	printf("The stack is :: \n");
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
	printf("\n");
}
int main()
{
	
	int c;
	while(1)
	{
		printf("Enter the choice :: \n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				printf("The Deleted element is ::%d\n",x);
				break;
			case 3:
				display();
				break;
		}
		
	}
}