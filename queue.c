#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 4
void display();
void enqueue(int x);
int dequeue();
int peek();
bool isfull();
bool isempty();

int head=0;
int tail=0;
int a[max]={};
int main()
{
	int x;
	int t=1;
	while(t==1)
	{	
		int sel, rem, pek;
		printf("Select an integer from below\n");
		printf("1. add element    2. delete element   3. display\n");
		scanf("%d", &sel);
		switch(sel)
		{
			case 1:
			printf("Enter the element\n");
			scanf("%d", &x);
			enqueue(x);
			break;

			case 2:
			rem = dequeue();
			printf("The removed element is %d\n", rem);
			break;

			case 3:
			display();
			break;

			case 4:
			pek = peek();
			printf("The first element of the queue is%d\n", pek);

			default:
			printf("Enter a valid option\n");
			break;
		}

		printf("Press 1 if you want to try once again\n");
		scanf("%d", &t);
	}
}

void enqueue(int x)
{
	a[tail]=x;
	if(tail==max-1)
	{
		tail = 0;
	}
	else
		tail++;
}

int dequeue()
{
	int del;
	del = a[head];
	if(head==max-1)
	{
		head = 0;
	}
	else
		head++;
	return del;	
}

void display()
{
	int i;
	if(head<=tail)
	{
		for(i=head; i<tail; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=head; i<max; i++)
		{
			printf("%d ",a[i]);
		}
		for(i=0; i<tail; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
}

int peek()
{
	return a[tail-1];
}

bool isfull()
{
	if(tail==max-1)
		return true;
	else
		return false;
}


bool isempty()
{
	if(head < 0|| head > tail)
		return true;
	else
		return false;
}
