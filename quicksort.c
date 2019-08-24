#include <stdio.h>
void quickSort(int a[], int l, int q);
int partition(int a[], int l, int q);
int n;
int a[30];

int main()
{
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int i;
	printf("Enter the array elements\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n-1);

	printf("The sorted array is \n");
	for (i=0; i<n; i++)
		printf("%d ", a[i]);
}

void quickSort(int a[], int l, int q)
{
	if(l<q)
	{
		int j = partition(a, l, q);
		quickSort(a, l, j-1);
		quickSort(a, j+1, q);
	}
	
}

int partition(int a[], int l, int q)
{
	int pivot, i, j, temp;
	pivot = l;
	i = l;
	j = q;
	while(i<j)
	{
		while(a[i]<=a[pivot] && i<q)
		{
			i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if (i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

	}

	temp = a[pivot];
	a[pivot] = a[j];
	a[j] = temp;

	return j;
}