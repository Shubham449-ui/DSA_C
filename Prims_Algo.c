//Prims Algorithm using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int vertex;
	int cost;
	struct node *next;
};
void creategraph(struct node *adj[],int no_of_nodes)
{
	struct node *new_node,*last;
	int i,j,n,val,k;
	for(i=0;i<no_of_nodes;i++)
	{
		last = NULL;
		printf("Enter the no of neighbours of %d :: ",i);
		scanf("%d",&n);
		
		for(j=1;j<= n;j++)
		{
			printf("Enter the neighbour %d of %d ",j,i);
			scanf("%d",&val);
			printf("Enter the length %d of %d ",j,i);
			scanf("%d",&k);
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->vertex = val;
			new_node->cost = k;
			new_node->next = NULL;
			if(adj[i]==NULL)
			{
				adj[i] = new_node;
			}
			else
			{
				last->next = new_node;
			}
			last = new_node;
		}
	}
}
void display_graph(struct node *adj[],int no_of_nodes)
{
	struct node *ptr;
	int i;
	for(i=0;i<no_of_nodes;i++)
	{
		ptr = adj[i];
		printf("The neighbour of %d  ----> ",i);
		while(ptr!=NULL)
		{
			printf("%d(%d), \n",ptr->vertex,ptr->cost);
			ptr = ptr->next;
		}
	}
}
void P_mst(struct node *adj[],int no_of_nodes)
{
	int key[no_of_nodes];
	int parent[no_of_nodes];
	bool inMST[no_of_nodes];
	
	int i;
	for(i=0;i<no_of_nodes;i++)
	{
		key[i] = INT_MAX;
		inMST[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	
	int count;
	for(count=0;count<no_of_nodes-1;count++)
	{
		int min = INT_MAX, min_index;
		for(i=0;i<no_of_nodes;i++)
		{
			if(!inMST[i] && key[i]<min)
			{
				min = key[i];
				min_index = i;
			}
		}
		
		int u  = min_index;
		inMST[u] = true;
		
		struct node *ptr;
		ptr = adj[u];
		while(ptr!=NULL)
		{
			int v = ptr->vertex;
			if(!inMST[v] && ptr->cost<key[v])
			{
				key[v] = ptr->cost;
				parent[v] = u;
			}
			ptr = ptr->next;
		}
	}
	
	printf("Edges\t Weight\n");
	for(i=1;i<no_of_nodes;i++)
	{
		printf("%d-%d\t %d \n",parent[i],i,key[i]);
	}
}
int main()
{
	struct node *adj[10];
	int no_of_nodes,choice,i;
	printf("Enter the number of vertices :: ");
	scanf("%d",&no_of_nodes);
	for(i=0;i<no_of_nodes;i++)
	{
		adj[i] = NULL;
	}
	creategraph(adj,no_of_nodes);
	printf("Do you want to display the graph :: ");
	scanf("%d",&choice);
	display_graph(adj,no_of_nodes);
	P_mst(adj,no_of_nodes);
	
}
