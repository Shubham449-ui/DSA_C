#include<stdio.h>
#include<stdlib.h>
#define max 3
int queue[3],front=-1,rear=-1,value,p,i;
void insertion()
{
	printf("Enter the Value you want to Insert ::\n");
	scanf("%d",&value);
	if(rear == max-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		if(rear == -1)
		{
			front=0;
		}
		rear++;
		queue[rear] = value;		
	} 
	
}
int deletion()
{
	
	if(front == -1||front == rear+1)
	{
		printf("Queue is Underflow\n");
	}
	
	else
	{
		p = queue[front];
		front++;
		return p;	
	}
}
void display()
{
	printf("The Queue is ::\n");
	for(i=front;i<=rear;i++)
	{
		printf("|%d| ",queue[i]);
	}
}
int main()
{
	int c;
	while(1)
	{
		printf("Enter the choice ::\n");
	    scanf("%d",&c);
	    switch(c)
	    {
	    	case 1:
	    		insertion();
	    		break;
	    	case 2:
	    		deletion();
	    		printf("The deleted Value is :: %d\n",p);
	    		break;
	    	case 3:
	    		display();
	    		break;
		}
	}
}