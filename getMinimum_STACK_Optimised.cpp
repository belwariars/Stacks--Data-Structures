#include <bits/stdc++.h>
using namespace std;

struct Stack
{
	unsigned capacity;
	int top;
	int *array;
};

struct Stack *createstack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	if(!stack) // This if statement is required because when if malloc won't return pointer...then in that case....
	{
		return NULL;
	}
    stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); // This if statement is required because when if malloc won't return pointer...then in that case....
//	printf("%d %d %d %d", stack, &stack->capacity, &stack->top, &stack->array[0]);
	if(!stack->array)
	{
		return NULL;
	}
	
	return stack;
}

int isEmpty(struct Stack *stack)
{
	if(stack->top<0)
	{
	//	printf("Stack is Empty");
		return 1; // signalling the stack is empty...
	}
	
	//printf("Stack is not Empty");
	return 0; // signalling the stack is not empty...
}

int isFull(struct Stack *stack)
{
	if(stack->top == (stack->capacity)-1)
	{
	//	printf("Stack is Full");
		return 1; // signalling the stack is full...
	}
	
//	printf("Stack is not Full");
	return 0; // signalling the stack is not full...
}

int peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
	//	printf("Empty stack...");
		return -1;
	}
	
	//printf("Top Element:  %d\n", stack->array[stack->top]);
	return stack->array[stack->top];
}

void push(struct Stack *stack, struct Stack *auxstack, int data) // chat data because infixToPostfix program...so, char would be inserted
{
	if(isFull(stack))
	{
	//	printf("Stack Full..");
		return;
	}
	
	else
	{
		stack->array[++stack->top] = data;
		printf("The element inserted:  %d\n", stack->array[stack->top]);
		if(isEmpty(auxstack))
		{
			auxstack->array[++auxstack->top] = data;
		}
		else
		{
			if(peek(auxstack) >= data)
			{
				auxstack->array[++auxstack->top] = data;
			}
		}
	}
}

void pop(struct Stack *stack, struct Stack *auxstack)
{
	if(isEmpty(stack))
	{
	//	printf("Stack empty...");
		return ;
	}
	
	else
	{
		printf("element popped:  %d\n", stack->array[stack->top]);
		int elem = stack->array[stack->top];
		(stack->top)--;
		if(peek(auxstack) == elem)
		{
			auxstack->array[--auxstack->top];
		}
		//return (elem);
	}
}

void getmin(struct Stack *stack, struct Stack *auxstack)
{
	printf("\nMinimum =  %d\n", peek(auxstack));
}


// http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
// See first method and then 2nd...but this is 2nd method implementation...


int main()
{
	struct Stack* stack = createstack(10);
	struct Stack* auxstack = createstack(10);
	push(stack, auxstack, 60);
	push(stack, auxstack, 20);
	push(stack, auxstack, 30);
	getmin(stack, auxstack);
	pop(stack, auxstack);
	pop(stack, auxstack);
	getmin(stack, auxstack);
	return 0;
}
