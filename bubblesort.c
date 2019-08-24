#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i, temp;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int A[n];
	printf("Enter the elements\n");
	for(i=0; i<n; i++)
		scanf("%d", &A[i]);
	for(int j=0; j<n; j++)
	{
		for (i=0; i<n-j-1; i++)
		{
			if(A[i]>A[i+1])
			{
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
			}
		}
	}
	
	for(i=0; i<n; i++)
		printf("%d ", A[i]);

}	