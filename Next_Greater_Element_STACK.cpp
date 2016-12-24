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
	//	printf("The element inserted:  %d\n", stack->array[stack->top]);
	}
}

int pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
	//	printf("Stack empty...");
		return -1;
	}
	
	else
	{
	//	printf("element popped:  %d\n", stack->array[stack->top]);
		int elem = stack->array[stack->top];
		(stack->top)--;
		return (elem);
	}
}


void nextGreaterElement(int arr[], int len)
{
	
	struct Stack *stack = createstack(len);
	int i=0;
//	printf("%d", len);
	int next = 1;
	push(stack, arr[i]);
	while(next<len)
	{
	
			while(!isEmpty(stack) && peek(stack) < arr[next])
			{
				printf("NGE of %d is %d \n", pop(stack), arr[next]);
			}
			push(stack, arr[next]);
			next++;
		if(peek(stack) >= arr[next])
		{
			push(stack, arr[next]);
			next++;
		} 
		
	} 
	
	while(!isEmpty(stack))
	{
		printf("NGE of %d is %d \n", pop(stack), -1);
	}
	
	
}


int main()
{
//	struct Stack* stack = createstack(10);
	int arr[]= {11, 13, 42, 17 ,21, 3, 5};
	int len = sizeof(arr)/sizeof(arr[0]);
	nextGreaterElement(arr, len);
	return 0;
}
