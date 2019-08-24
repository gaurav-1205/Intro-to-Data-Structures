#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapsort(int a[]);
void maxHeapify(int a[], int i);
void buildMaxHeap(int a[]);
int parent(int x);
void swap(int *a, int *b);
int left(int x);
int right(int x);

int size;
int len;
int main()
{
	int n , i;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	len = n;
	int a[n];
	printf("Enter the elements of the array\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	heapsort(a);


}

void heapsort(int a[])
{
	int i;
	buildMaxHeap(a);
	for(i=len-1; i>0; i--)
	{
		swap(&a[0], &a[i]);
		size--;
		maxHeapify(a, 0);
	}
	for(i=0; i<len; i++)
	{
		printf("%d ", a[i]);
	}
}

void maxHeapify(int a[], int i)
{
	int largest;
	int l = left(i);
	int r = right(i);
	if(l<size && a[l]>a[i])
	{
		largest = l;
	}
	else
		largest = i;
	if(r<size && a[r]>a[largest])
	{
		largest = r;
	}

	if(largest!=i)
	{
		swap(&a[largest], &a[i]);
		maxHeapify(a, largest);
	}



}

void buildMaxHeap(int a[])
{
	int i;
	size = len;
	int len1 = floor(len/2);
	for(i=len1-1; i>=0; i--)
	{
		maxHeapify(a, i);
	}
}

int parent(int x)
{
	return floor(x/2);
}

int left(int x)
{
	return 2*x + 1;
}

int right(int x)
{
	return 2*x + 2;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}