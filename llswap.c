#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course 
{
	char code[10];
	char name[15];
	struct course* next;
};

struct course* head = NULL;

void touppercase(char *string);
void insert(char ccode[], char cname[]);
void display(struct course *n);
void swap(char ccodes1[], char ccodes2[]);
void traverse();

int main()
{
	int sel, t=1, i=0, j=0;
	char ch;
	char ccode[8], cname[20];
	char ccodes1[8], ccodes2[8];
	printf("Enter the course code\n");
	scanf("%s", ccode);
	touppercase(ccode);
	printf("Enter the name of the course\n");
	scanf("%s", cname);

	head = (struct course*)malloc(sizeof(struct course));
	while(ccode[i]!='\0')
	{
		head -> code[i] = ccode[i];
		i++;
	}
	while(cname[j]!='\0')
	{
		head -> name[j] = cname[j];
		j++;
	}
	//printf("%s\n", head->code);
	//printf("%s\n", head->name);
	head -> next = NULL;

	while(t==1)
	{
		printf("1. Enter another course code\n2. Swap 2 entries\n3. display the entries\n4. exit\n");
		scanf("%d", &sel);
		while ((ch = getchar()) != '\n' && ch != EOF){}

		
		if(sel==1)
		{
			printf("Enter the course code\n");
			scanf("%s", ccode);
			touppercase(ccode);
			printf("Enter the name of the course\n");
			scanf("%s", cname);
			insert(ccode, cname);
		}

		if(sel==2)
		{
			printf("Enter the course code 1\n");
			scanf("%s", ccodes1);
			printf("Enter the course code 2\n");
			scanf("%s", ccodes2);
			touppercase(ccodes1);
			touppercase(ccodes2);
			swap(ccodes1, ccodes2);
			
		}

		if(sel==3)
		{
			display(head);
			//traverse();
		}	

		if(sel==4)
		{
			return 0;
		}
		
	}
}

void display(struct course *n)
{
	printf("\n");
	int count = 0;
	while(1)
	{
		
		printf("Course %d:\n", count+1);
		printf("%s\t%s\n\n", n->code, n->name);
		count++;
		if(n->next == NULL)
			break;
		n=n->next;
	}
}

void insert(char ccode[], char cname[])
{
	int i=0, j=0;
	struct course* p = (struct course*)malloc(sizeof(struct course));
	struct course* ptr = head;
	while(ccode[i]!='\0')
	{
		p -> code[i] = ccode[i];
		i++;
	}
	while(cname[j]!='\0')
	{
		p -> name[j] = cname[j];
		j++;
	}


	p->next = NULL;
	for(ptr = head; ptr->next != NULL; ptr=ptr->next) {}
	
	ptr->next = p;
}


void touppercase(char *string)
{
	char* t = string;
	while(*t!='\0')
	{
		if(*t>='a' && *t<='z')
			*t = *t - 32;
		t++;
	}
}

void swap(char ccodes1[], char ccodes2[])
{
	if(ccodes1==ccodes2)
		return;
	struct course* ptr1 = head;
	struct course* ptr2 = head;
	struct course* ptr3 = head;
	struct course* ptr4 = head;
	while(ptr1->next != NULL && strcmp(ccodes1, ptr1->code)!=0)
	{
			ptr1=ptr1->next;
	}

	while(ptr2->next != NULL && strcmp(ccodes2, ptr2->code)!=0)
	{
			ptr2=ptr2->next;
	}
	if(ptr1 != head && ptr2 != head)
	{
		while(ptr3->next != ptr1)
		{
			ptr3=ptr3->next;
		} 	

		while(ptr4->next != ptr2)
		{
			ptr4=ptr4->next;
		}	 	
	

		struct course* temp1;
		struct course* temp2;

		temp1 = ptr3->next;
		ptr3->next = ptr4->next;
		ptr4->next = temp1;

		ptr3 = ptr3->next;
		ptr4 = ptr4->next;
  	
  		temp2 = ptr3->next;
		ptr3->next = ptr4->next;
		ptr4->next = temp2;

	}


	else if(ptr1==head)
	{
		while(ptr3->next != ptr2)
		{
			ptr3=ptr3->next;
		}	 
		struct course* temp;

		ptr3->next = ptr1;

		temp = ptr1->next;
		ptr1->next = ptr2->next;
		ptr2->next = temp;
	}
 
	else if(ptr2==head)
	{
		while(ptr3->next != ptr1)
		{
			ptr3=ptr3->next;
		}	 
		struct course* temp;

		ptr3->next = ptr2;

		temp = ptr2->next;
		ptr2->next = ptr1->next;
		ptr1->next = temp;
	}
}


