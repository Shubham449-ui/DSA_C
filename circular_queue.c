#include<stdio.h>
#include<stdlib.h>
#define max 3
int cqueue[max],front=-1,rear=-1,value,p,i;
void insertion()
{
	printf("Enter the Value you want to Insert ::\n");
	scanf("%d",&value);
	if((front ==0 && rear == max-1)||(front == rear+1))
	{
		printf("Stack Overflow");
	}
	else
	{
	    if(front == -1)
     	{
		    front=0;
		    rear = 0;
    	}
	    else if(rear == max-1)
	    {
			rear = 0;
	    }
	    else
	    {
			rear++;		
	    }
	
	cqueue[rear] = value;	
	}
	
	//rear++;
}
int deletion()
{
	p = cqueue[front];
	if(front == -1)
	{
		printf("Queue is Underflow ");
	}
	else
	{
	    if(front == rear)
		{
			front = -1;	
			rear = -1;
		}
		else if(front==max-1)
		{
			front = 0;
		}
		else
		{
			front++;		
		}

	return p;
	}
	
}
void display()
{
	printf("The Queue is ::\n");
	i = front;
	if(front<=rear)
	{
		while(i<=rear)
		{
			printf("|%d| ",cqueue[i++]);
		}
	}
	else
	{
		while(i<=max-1)
		{
			printf("|%d| ",cqueue[i++]);
		}
		i=0;
		while(i<=rear)
		{
			printf("|%d| ",cqueue[i++]);
		}
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