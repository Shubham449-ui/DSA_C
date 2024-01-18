#include<stdio.h>
#include<stdlib.h>
int height = 0;
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
#include<stdio.hstruct node *recur_search(struct node *ptr,int key)
{
	if(ptr==NULL)
	{
		printf("Key is not found");
		return NULL;
	}
	else if(key<ptr->data)
	{
		height++;
		return recur_search(ptr->left,key);
	}
	else if(key>ptr->data)
	{
		height++;
		return recur_search(ptr->right,key);
	}
	else
	{
		printf("Node is found at height %d\n",height);
		return ptr;
	}
}
int main()
{
        int choice,key,height;
      	struct node *root;
      	struct node *pos;
        printf("Enter the key you want to search :: ");
				scanf("%d",&key);
				pos = recur_search(root,key);
				if(pos == NULL)
				{
					break;
				}
				else
				{
					printf("Node is found\n");
					
				}
}
