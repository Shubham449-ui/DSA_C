#include<stdio.h>
int main()
{
	int a[25],n,i,j,temp;
	printf("Enter the size of the array :: ");
	scanf("%d",&n);
	printf("Enter the element of the array :: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				continue;
			}
			else
			{
			   temp=a[j];
			   a[j]=a[j+1];
			   a[j+1]=temp;
			}
		}
	}
	printf("After sorting the array is :: ");
	for(i=0;i<n;i++)
	{
			printf("%d\t",a[i]);
	}
}