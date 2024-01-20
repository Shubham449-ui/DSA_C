#include<stdio.h>
int partition(int low,int high,int a[])
{
	int temp,i,j,pivot;
	i = low + 1;
	j = high;
	pivot = a[low];
	while(i <= j)
	{
		while((a[i]<pivot)&&(i<high))
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else
		{
			i++;
		}
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}
void quick(int low,int high,int a[])
{
	int pivloc;
	if(low>=high)
	{
		return;
	}
	pivloc = partition(low,high,a);
	quick(low,pivloc-1,a);
	quick(pivloc+1,high,a);
}
int main()
{
	int a[25],n,i,j,k;
	printf("Enter the size of array:: \n");
	scanf("%d",&n);
	printf("Enter the element of array :: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The array is :: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	quick(0,n-1,a);
	printf("After sorting the array is :: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
