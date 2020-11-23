#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void insert_front()
{
	struct node *ptr;
	int new_data;
	ptr = (struct node *)malloc(sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("\nOVERFLOW!!!");	
	}
	else
	{
		printf("\nEnter Value:");
		scanf("%d",&new_data);
		ptr->data = new_data;
		ptr->next = head;
		head = ptr;
		printf("\nNODE INSERTED\n");	
	}
}

void insert_end()
{
	struct node *ptr,*temp;
	int new_data;
	ptr = (struct node *)malloc(sizeof(struct node));	
	
	if(ptr == NULL)
	{
		printf("\nOVERFLOW!!!\n");	
	}
	else
	{
		printf("\nEnter Value:");
		scanf("%d",&new_data);
		ptr->data = new_data;
		if(head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
			printf("\nNODE INSERTED\n");	
		}
		else
		{
			temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
			printf("\nNODE INSERTED\n");
		}	
	}
}

void insert_specificpos()
{
	int i,position,new_data;
	struct node *ptr,*temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("\nOVERFLOW!!!\n");	
	}
	else
	{
		printf("\nEnter Value:");
		scanf("%d",&new_data);
		ptr->data = new_data;
		printf("\nEnter the position to insert the element:");
		scanf("%d",&position);
		temp = head;
		if(position == 1)
		{
			ptr->next = temp;
			head = ptr;
			return;
		}
		for(i=1;i<position-1;i++)
		{
			temp = temp->next;	
		}
		ptr->next = temp->next;
		temp->next = ptr;
		printf("\nNODE INSERTED\n");	
	}	
}

void delete_front()
{
	struct node *ptr;
	if(head == NULL)
	{
		printf("EMPTY LIST!!!");
	}
	else
	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		printf("\nNODE DELETED FROM THE BEGINING\n");
	}	
}

void delete_end()
{
	struct node *ptr,*ptr1;
	if(head == NULL)
	{
		printf("EMPTY LIST!!!");
	}
	else if(head->next == NULL)
	{
		head = NULL;
		free(head);
		printf("\nONLY NODE IN THE LIST DELETED\n");
	}
	else
	{
		ptr = head;
		while(ptr->next != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->next;	
		}
		ptr1->next = NULL;
		free(ptr);
		printf("\nNODE DELETED FROM THE END\n");
	}
}

void delete_specificpos()
{
	struct node *ptr,*ptr1;
	int position,i;
	printf("\nEnter the position to delete the element:");
	scanf("%d",&position);
	ptr = head;
	for(i=0;i<position;i++)
	{
		ptr1 = ptr;
		ptr = ptr->next;
		
		if(ptr == NULL)
		{
			printf("\nLess Than Required Elements in the List!");
			return;
		}
	}
	ptr1->next = ptr->next;
	free(ptr);
	printf("\nNODE DELETED %d\n",position+1);
}

void display_list()
{
	struct node *ptr;
	ptr = head;
	if(ptr == NULL)
	{
		printf("EMPTY LIST!!!INSERT FEW ELEMENTS!!");
	}
	else
	{
		printf("\n\nLIST-->");
		while(ptr != NULL)
		{
			printf("\t%d",ptr->data);
			ptr = ptr->next;
		}
	}
}

int main()
{
	int choice = 0;
	while(1)
	{
		printf("\n\n------------MENU------------\n");
		printf("Choose an option from the list:");
		printf("\n[1]Insert in the Begining\n[2]Insert at the End\n[3]Insert at Specific Position\n[4]Delete from the Begining\n[5]Delete from the End\n[6]Delete at a Specific Position\n[7]Display Linked List\n[8]EXIT\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_front();
					break;
			case 2: insert_end();
					break;		
			case 3: insert_specificpos();
					break;		
			case 4: delete_front();
					break;
			case 5: delete_end();
					break;
			case 6: delete_specificpos();
					break;
			case 7: display_list();
					break;
			case 8: exit(1);
			default:
				printf("\nINVALID CHOICE!!!\n");								
		}
	}
}
