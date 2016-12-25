#include <bits/stdc++.h>
using namespace std;

struct Stack
{
	unsigned capacity;
	int top;
	int *array;
};

//int middle;
bool flag = true;
int midindex;
int totalindex = 0;

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
		printf("Stack is Empty");
		return 1; // signalling the stack is empty...
	}
	
	//printf("Stack is not Empty");
	return 0; // signalling the stack is not empty...
}

int isFull(struct Stack *stack)
{
	if(stack->top == (stack->capacity)-1)
	{
		printf("Stack is Full");
		return 1; // signalling the stack is full...
	}
	
//	printf("Stack is not Full");
	return 0; // signalling the stack is not full...
}

int peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Empty stack...");
		return -1;
	}
	
//	printf("Top Element:  %d\n", stack->array[stack->top]);
	return stack->array[stack->top];
}

void push(struct Stack *stack, int data) // chat data because infixToPostfix program...so, char would be inserted
{
	if(isFull(stack))
	{
		printf("Stack Full..");
		return;
	}
	else
	{
		stack->array[++stack->top] = data;
		printf("The element inserted:  %d\n", stack->array[stack->top]);
		totalindex++;
		if(stack->top == 0)
		{
			midindex = stack->top;
			//middle = stack->array[midindex];
			flag = false;
		}
		else
		{
			if(flag)
			{
				midindex++;
				flag = false;
			}
			else
			{
				flag = true;
			}
		}
	}
	if(stack->top <0)
	{
		midindex = -1;
	}
}

void pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Stack empty...");
		if(stack->top <0)
		{
			midindex = -1;
		}
		return ;
	}
	
	else
	{
		printf("element popped:  %d\n", stack->array[stack->top]);
		int elem = stack->array[stack->top];
		totalindex--;
		if(totalindex < (2*midindex))
		{
			midindex--;
		}
		
		(stack->top)--;
		//return (elem);
	}
	
	if(stack->top <0)
	{
		midindex = -1;
	}
}





int main()
{
	struct Stack* stack = createstack(10);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	//	pop(stack);
//	pop(stack);
	push(stack, 60);
	push(stack, 70);
//	pop(stack);
	push(stack, 80);
		push(stack, 90);
//	pop(stack);
//	pop(stack);

	if(midindex >= 0)
	printf("\nMiddle element=  %d\n", stack->array[midindex]);
	else
	printf("Stack is Empty...");
	return 0;
}
