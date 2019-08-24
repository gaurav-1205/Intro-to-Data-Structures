#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node* next;
};


struct node* head = NULL;

node* create(int data, node* next)
{
	struct node* p = (struct node*)malloc(sizeof(struct node*));
	if(p==NULL)
	{
		printf("Error in creating node\n");
		return;
	}
	p->data = data;
	p->next = next;

	return p;
}

int count()
{
	struct node* cursor = head;
	int count = 0;
	while(cursor!=NULL)
	{
		c++;
		cursor=cursor->next;
	}
	return c;
}

node* prepend(int data)
{
	struct node* p = create(data, head);
	head = p;
}

void insert(int val)//inserts at the beginning
{
	struct node* p = (struct node*)malloc(sizeof(struct node*));
	p->data = val;
	p->next = head;
	head = p;
}

void deleteFirst()
{
	if(head == NULL)
		return;
	else
	{
		struct node* p = head;
		head = head->next;
		free(p);
	}
}

void insertatend(int val)
{
	struct node* cursor=head;
	while(cursor->next!=NULL)
	{
		cursor=cursor->next;
	}

	/*if(head == NULL)
		return
	struct node *ptr = head;
	while(ptr->next!=NULL)
		ptr=ptr->next;

	struct node* p = (struct node*)malloc(sizeof(struct node*));
	p->data = val;
	p->next = next;

	ptr->next = p;*/

}

void traverse()
{
	struct node* temp;
	if(head == NULL)
	{
		printf("List is emptyn\n");
	}
	else 
	{
		temp = head;
		while(temp!=NULL)
		{
			printf("%d ", temp->data);
			temp=temp->next;
		}
	}
}


void insertAfter(int x, int y)//insert y immediately after x
{
	struct node *p, *q, *r;
	if(head == NULL)
	{
		printf("Enter valid args");
		return;
	}
	for(p=head; p!=NULL; p=p->next)
	{
		if(p->val == x)
			break;
		if(p==NULL)
		{
			printf("Invalid\n");
			return;
		}
	}

	r = (struct node*)malloc(sizeof(struct node*))

	r->data = y;
	r->next = p->next;
	p->next = r;
}


void swap(char ccodes1[], char ccodes2[])
{
	if(ccodes1==ccodes2)
		return;
	struct course *prevx = NULL, *currx = head;
	while(currx && currx->code != ccodes1)
	{
		prevx = currx;
		currx = currx->next;
	} 

	struct course *prevy = NULL, *curry = head;
	while(curry && curry->code != ccodes2)
	{
		prevy = curry;
		curry = curry->next;
	} 

	if (currx == NULL || curry == NULL)
       return;
 
  	
   	if (prevx != NULL)
		prevx->next = curry;
   	else 
		head = curry;  
 
   
    if (prevy != NULL)
        prevy->next = currx;
    else  // Else make x as new head
        head = currx;
 
   // Swap next pointers
   struct course *temp = curry->next;
   curry->next = currx->next;
   currx->next  = temp;

}
