#include<stdio.h>
#define max 100
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int adj[max][max];
int n;
int max_edges,i,j,origin,destin;
int graph_type;
int stack[max],top = -1;
int state[max];
void push(int vertex);
int pop();
int isempty_queue();
void DFS(int v);
int p;
void create_graph()
{
	printf("Enter 1 for undirected graph or 2 for directed graph :: ");
	scanf("%d",&graph_type);
	printf("Enter the no of vertices :: ");
	scanf("%d",&n);
	if(graph_type == 1)
	{
		max_edges = (n*(n-1))/2;
	}
	else
	{
		max_edges = n*(n-1);
	}
	printf("If you want to stop the loop then press -1 otherwise press 0\n");
	for(i=0;i<max_edges;i++)
	{
		printf("Enter edge %d(-1,-1 to quit): ",i);
		scanf("%d %d",&origin,&destin);
		printf("If you want to stop the loop then press -1 otherwise press 0");
		scanf("%d",&p);
		if(origin == -1|| destin==-1||p == -1)
		{
			break;
		}
		if(origin>n || destin>n || origin<0 || destin<0)
		{
			printf("Invalid vertex\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			if(graph_type == 1)
			{
				adj[destin][origin] = 1;
			}
		}
	}
	printf("The adjacency matrix is ::\n ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
}
void DF_traversal()
{
	int v;
	for(v = 0;v<n;v++)
	{
		state[v] = initial;
	}
	printf("Enter the starting node for depth first search :: ");
	scanf("%d",&v);
	DFS(v);
}
int isEmpty_stack()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int v)
{
	if(top == MAX-1)
	{
		printf("Stack Overflow ");
		return;
	}
	else
	{
		top = top+1;
		stack[top] = v;	
	}
}
int pop()
{
	int v;
	if(top==-1)
	{
		printf("Stack is underflow");
	}
	else
	{
		v = stack[top];
		top = top-1;
		return v;
	}
}
void DFS(int v)
{
	int i;
	push(v);
	while(!isEmpty_stack())
	{
		v = pop();
		if(state[v] == initial)
		{
			printf("%d",v);
			state[v] = visited;
		}
		for(i = n-1;i>=0;i--)
		{
			if(adj[v][i]==1&&state[i] == initial)
			{
				push(i);
			}
		}
	}
}
int main()
{
	create_graph();
	DF_traversal();
}
