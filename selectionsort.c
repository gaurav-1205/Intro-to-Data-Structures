//copyright - Gaurav
#include <stdio.h>
int main()
{
	int p;
	printf("Enter the number of elements\n");
	scanf("%d", &p);
	int a[p], i, temp, j;
	printf("Enter the array elements\n");
	for(i=0; i<p; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0; i<p-1; i++)
	{
		for(j=i+1; j<p; j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		printf("\n");
		for(j=0; j<p; j++)
			printf("%d ", a[j]);
	}
	for(i=0; i<p; i++)
		printf("%d ", a[i]);
}