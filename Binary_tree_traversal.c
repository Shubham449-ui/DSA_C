#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *create()
{
	int data;
	struct node *newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the node ");
	scanf("%d",&data);
	if(data == 0)
	{
		return NULL;
	}
	newnode->data = data;
	printf("\n Enter the the left child of %d :: ",data);
	newnode->left = create();
	printf("\n Enter the the rigth child of %d :: ",data);
	newnode->right = create();
	return newnode;
}
void Inorder(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	Inorder(ptr->left);
	printf("%d ",ptr->data);
	Inorder(ptr->right);
}
void Preorder(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	printf("%d ",ptr->data);	
	Preorder(ptr->left);
	Preorder(ptr->right);
}
void Postorder(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	Postorder(ptr->left);
	Postorder(ptr->right);
	printf("%d ",ptr->data);
}
int main()
{
	int choice;
	struct node *root;
	while(1)
	{
		printf("Press 1 create tree\n");
		printf("Press 2 Inorder traversal\n");
		printf("Press 3 Preorder traversal\n");
		printf("Press 4 Postorder traversal\n");
		printf("<----Enter the choice----->");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				root = create();
				break;
			case 2:
				Inorder(root);
				break;
			case 3:
				Preorder(root);
				break;
			case 4:
				Postorder(root);
				break;
		}
	}
}
