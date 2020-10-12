#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int Q[MAX];
int front = -1;
int rear = -1;

void insert()
{
	int elem;
	if(rear==MAX-1)
		printf("\nQueue Overflow\n");
	else
	{
		if(front==-1)
			front=0;
		printf("\nEnter the element to be inserted into the Queue: ");
		scanf("%d",&elem);
		Q[++rear]=elem;
		printf("\nElement successfully inserted\n");
	}	
}

void delete()
{
	if(front==-1||front>rear)
		printf("\nQueue underflow\n");
	else
	{
		printf("\nDeleted Element: %d\n",Q[front++]);
		if(front>rear)
		{
			front=-1;
			rear=-1;
		}
	}
}

void display()
{
	int i;
	if(front==-1)
		printf("\nQueue is empty\n");
	else
	{
		printf("\nQueue Elements are: \n");
		for(i=front;i<=rear;i++)
			printf("\n%d",Q[i]);
		printf("\n");						
	}	
}

int main()
{
	int choice;
	
	while(1)
	{
		printf("\n------------MENU--------------");
		printf("\n1)INSERT\n2)DELETE\n3)DISPLAY\n4)EXIT");
		printf("\nEnter you choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("\nInvalid choice\n");
		}	
	}
	return 0;
}
