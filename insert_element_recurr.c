struct node *insert_element_recur(struct node *ptr,int key)
{

	if(ptr == NULL)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = key;
		ptr->left = NULL;
		ptr->right = NULL;
	}
	else if(ptr->data > key)
	{
		ptr->left = insert_element_recur(ptr->left,key);
	}
	else if(ptr->data < key)
	{
		ptr->right = insert_element_recur(ptr->right,key);
	}
	else
	{
		printf("Duplicate key");
	}
	return ptr;
}
int main()
{
        int key;
        struct node *root,*pos;
        printf("Enter the key you want to insert :: ");
				scanf("%d",&key);
				pos = insert_element_recur(root,key);
}
