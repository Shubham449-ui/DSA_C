#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef;
	int expo;
	struct node *next;
};
struct node *newnode=NULL,*temp=NULL,*root1=NULL,*root2=NULL,*root3,*temp1,*temp2;
void create_first()
{
	int ch;
	do
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the coeff of first poly :: ");
		scanf("%d",&newnode->coef);
		printf("Enter the expo of first ploy :: ");
		scanf("%d",&newnode->expo);
		newnode->next = NULL;
		if(root1 == NULL)
		{
			root1 = newnode;
			temp = newnode;
		}
		else
		{
			temp = root1;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			temp = newnode;
		}
		printf("If you want to continue then press 1 otherwise presss 0 :: ");
		scanf("%d",&ch);
	}while(ch!=0);
}
void display_first()
{
	temp = root1;
	while(temp!=NULL)
	{
		printf("%d * %d\t",temp->coef,temp->expo);
		temp = temp->next;
	}
}
void create_second()
{
	int ch;
	do
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the coeff of Second poly :: ");
		scanf("%d",&newnode->coef);
		printf("Enter the expo of Second ploy :: ");
		scanf("%d",&newnode->expo);
		newnode->next = NULL;
		if(root2 == NULL)
		{
			root2 = newnode;
		}
		else
		{
			temp = root2;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			temp = newnode;
		}
		printf("If you want to continue then press 1 otherwise presss 0 :: ");
		scanf("%d",&ch);
	}while(ch!=0);
}
void display_second()
{
	temp = root2;
	while(temp!=NULL)
	{
		printf("%d * %d\t",temp->coef,temp->expo);
		temp = temp->next;
	}
}
void insert(int coef,int expo)
{
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->coef = coef;
	newnode->expo = expo;
	newnode->next = NULL;
	if(root3 == NULL)
	{
		root3 = newnode;
	}
	else
	{
		temp = root3;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		temp = newnode;
	}
}
void add()
{
	temp1 = root1;
	temp2 = root2;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->expo>temp2->expo)
		{
			insert(temp1->coef,temp1->expo);
			temp1= temp1->next;
		}
		else if(temp1->expo < temp2->expo)
		{
			insert(temp2->coef,temp2->expo);
			temp2 = temp2->next;
		}
		else
		{
			insert(temp1->coef+temp2->coef,temp1->expo);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	while(temp1!=NULL)
	{
		insert(temp1->coef,temp1->expo);
		temp1= temp1->next;
	}
	while(temp2!=NULL)
	{
		insert(temp2->coef,temp2->expo);
		temp2 = temp2->next;
	}
}
void display_add()
{
	temp = root3;
	while(temp!=NULL)
	{
		printf("%d * %d\t",temp->coef,temp->expo);
		temp = temp->next;
	}
}
int main()
{
	create_first();
	display_first();
	create_second();
	display_second();
	add();
	display_add();
}
