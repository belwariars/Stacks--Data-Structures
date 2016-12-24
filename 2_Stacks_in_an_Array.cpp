#include <bits/stdc++.h>
using namespace std;

struct Stack
{
	unsigned capacity;
	int top1;
	int top2;
	int *array;	
};

struct Stack* createstack(unsigned capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top1 = -1;
	stack->top2 = capacity;
	stack->array = (int*)malloc(capacity * sizeof(int));
	
	return stack;
}

int isEmpty(struct Stack *stack)
{
	if(stack->top1 == -1)
	{
		printf("Stack Empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(struct Stack *stack)
{
	if(stack->top2 == stack->top1 + 1)
	{
		printf("Stack Full\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

void push1(struct Stack *stack, int data)
{
	if(!isFull(stack))
	{
		printf("Pushed Element 1 :  %d\n", data);
		stack->array[++stack->top1] = data;
	}
	else
	{
		printf("Stack is full...can't fill more\n");
	}
}

void push2(struct Stack *stack, int data)
{
	if(!isFull(stack))
	{
		printf("Pushed Element 2 :  %d\n", data);
		stack->array[--stack->top2] = data;
	}
	else
	{
		printf("Stack is full...can't fill more\n");
	}
}

void pop1(struct Stack *stack)
{
	int elem = stack->array[stack->top1];
	(stack->top1)--;
	printf("Popped Element 1 :  %d\n", elem);
}

void pop2(struct Stack *stack)
{
	int elem = stack->array[stack->top2];
	stack->top2++;
	printf("Popped Element 2 :  %d\n", elem);
}

int main()
{
	struct Stack *stack = createstack(20);
	push1(stack, 10);
	push2(stack, 20);
	push1(stack, 30);
	push2(stack, 40);
	push2(stack, 50);
	push1(stack, 60);
	pop1(stack);
	pop2(stack);
	pop1(stack);
	pop2(stack);
	return 0;
}
