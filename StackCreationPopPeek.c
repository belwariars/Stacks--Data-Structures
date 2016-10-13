/* Following is the program demonstrating how create a STACK (Last in - First out) using ARRAY*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* First step is creation of a structure (struct node) which would contain the data types for a cell of linked list*/

struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	
	stack->array = (int*)malloc(stack->capacity * sizeof(struct Stack));
	
	return stack;
}

int isFull(struct Stack *stack)
{
	if(stack->top == stack->capacity-1)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int isEmpty(struct Stack *stack)
{
	if(stack->top == -1)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

void push(struct Stack *stack, int data)
{
	if(isFull(stack))
	{
		printf("stack is full");
		return;
	}
	stack->array[++stack->top] = data;
	printf("New item to me pushed = %d\n", data);
}

int pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("the list is already empty");
		return INT_MAX;
	}
	int popitem = stack->array[stack->top--];
	return popitem;
}

int peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("the list is already empty");
		return INT_MAX;
	}
	int popitem = stack->array[stack->top];
	return popitem;
}

int main()
{
	struct Stack *stack = createStack(10);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	push(stack, 60);
	push(stack, 70);
	push(stack, 80);
	push(stack, 90);
	push(stack, 100);
	
	int peekitem = peek(stack);
	printf("%d", peekitem);
	
	return 0;
}
