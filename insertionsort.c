#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i, j;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i]>a[j])
			{
				while(j!=i)
				{
					int temp = a[j];
					a[j] = a[j-1];
					a[j-1] = temp;
					j--;
				}
			}
		}
	}

	for(i=0; i<n; i++)
		printf("%d ", a[i]);



}