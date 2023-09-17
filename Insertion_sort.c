#include<stdio.h>
int main()
{
	int a[25],n,i,j,k;
	printf("Enter the size of array:: ");
	scanf("%d",&n);
	printf("Enter the element of array :: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		k = a[i];
		for(j=i-1;j>=0 && k<a[j];j--)
		{
			a[j+1] = a[j];
			a[j] = k;
		}
		
	}
	printf("After soring the new array is :: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}