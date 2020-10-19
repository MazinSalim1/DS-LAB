#include<stdio.h>
#include<stdlib.h>
#define size 5

int Q[size];
int front=-1,rear=-1;

int isfull()
{
	if(front==rear+1||(front==0&&rear==size-1))
	{
		return 1;	
	}
	return 0;
}

int isempty()
{
	if(front==-1)
	{
		return 1;	
	}
	return 0;
}

void insert()
{
	int elem;
	if(isfull())
	{
		printf("\nQueue Overflow\n");	
	}
	else
	{
		if(front==-1)
		{
			front=0;	
		}
		printf("\nEnter the element to the queue ");
		scanf("%d",&elem);
		rear = (rear+1)%size;
		Q[rear]=elem;
		printf("\nInserted-->%d\n",elem);
	}	
}

void delete()
{
	int elem;
	if(isempty())
	{
		printf("\nQueue Underflow\n");
	}
	else
	{
		elem=Q[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%size;
		}
		printf("\nDeleted Element-->%d\n",elem);	
	}	
}

void display()
{
	int i;
	if(isempty())
	{
		printf("\nQueue is Empty!!!Enter some Elements!!!\n");
	}
	else
	{
		printf("\nFront--> %d",front);
		printf("\nQueue Elements--> \n");
		for(i=front;i!=rear;i=(i+1)%size)
		{
			printf("%d\n",Q[i]);	
		}
		printf("%d",Q[i]);
		printf("\nRear--> %d\n",rear);
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
				printf("\nInvalid\n");
		}	
	}
	return 0;
}
