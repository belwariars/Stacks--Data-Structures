#include <bits/stdc++.h>
using namespace std;

int size = 0; // number of elements in the stack

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
	
//	printf("Top Element:  %d\n", stack->array[stack->top]);
	return stack->array[stack->top];
}

void push(struct Stack *stack, int data) // chat data because infixToPostfix program...so, char would be inserted
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
		size++;
	}
}

int pop(struct Stack *stack, struct Stack *stack2)
{
	if(isEmpty(stack))
	{
	//	printf("Stack empty...");
		return -1;
	}
	
	else
	{
	//	printf("element popped:  %d\n", stack->array[stack->top]);
	/*	int elem = stack->array[stack->top];
		(stack->top)--;
		return (elem);  */
		int size2 = 0;
		while(size > 1)
		{
			int elem = stack->array[stack->top];
			(stack->top)--;
			stack2->array[++stack2->top] = elem;
			size--;
			size2++;
		}
		int elem = stack->array[stack->top];
		(stack->top)--;
		printf("Element popped = %d\n", elem);
		size--;
		while(size2)
		{
			int elem = stack2->array[stack2->top];
			(stack2->top)--;
			stack->array[++stack->top] = elem;
			size2--;
			size++;
		}
	}
}




int main()
{
	struct Stack* stack1 = createstack(10);
	struct Stack* stack2 = createstack(10);
//	pop(stack1, stack2);
	push(stack1, 10);
	push(stack1, 20);
	push(stack1, 30);
	push(stack1, 40);
	pop(stack1, stack2);
	pop(stack1, stack2);
	pop(stack1, stack2);
	pop(stack1, stack2);
	pop(stack1, stack2);
	return 0;
}
