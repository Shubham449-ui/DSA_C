#include<stdio.h>
int main()
{
	int a[25],n,i,j,min_idx,temp;
	printf("Enter the size of array:: ");
	scanf("%d",&n);
	printf("Enter the element of array :: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		min_idx=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min_idx])
			{
				min_idx=j;
				temp = a[i];
				a[i] = a[min_idx];
				a[min_idx] = temp;
			}
		}
	}
	printf("After soring the new array is :: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}