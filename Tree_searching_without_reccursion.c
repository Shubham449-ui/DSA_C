struct node *non_recur_search(struct node *ptr,int key)
{
	int height = 0;
	while(ptr!=	NULL)
	{
		if(key<ptr->data)
		{
			ptr = ptr->left;
			height ++;
		}
		else if(key>ptr->data)
		{
			ptr = ptr->right;
			height ++;
		}
		else
		{
			printf("Node is found at %d\n",height);
			return ptr;
		}
	}
}
