#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top=-1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
	int choice, item;
	while(1)
	{
		printf("\n1.push\n");
		printf("2.pop\n");
		printf("3 display the top element\n");
		printf("4. display all stack element\n");
		printf("5.quit\n");
		printf("\n enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n enter theitem to be pushed: ");
				scanf("%d",& item);
				push(item);
				break;
				case 2:
					item= pop();
					printf("\n popped item is: %d \n",item);
					break;
					case 3:
					printf("\n item at the top is: %d \n", peek() );
					break;
					case 4:
						display();
						break;
						case 5:
							exit (1);
							default:
								printf("\n wrong choice\n");
    	}
    }
	return 0;   
}
void push (int item)
{
	if (isFull ())
	{
	 printf("\n stack overflow \n");
	 return;
	}
	top=top+1;
	stack_arr[top]=item;
}
int pop()
{
	int item;
	if(isEmpty ())
	{
		printf("\n Stack underflow\n");
		exit(1);
	}
	item=stack_arr[top];
	top=top-1;
	return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("\nstack underflow\n");
		exit(1);
	}
	return stack_arr[top];
}
int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isFull()
{
	if(top==MAX-1)
	return 1;
	else
	return 0;
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("\nstackis empty\n");
	return;
}
printf("\nstack elements:\n\n");
for(i=top;i>=0;i--)
printf("%d\n,stack_arr[i]");
printf("\n");
}