#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
	int top;
	unsigned capacity;
	
	int *array;	
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	
	stack->array = (int*)malloc(sizeof(stack->capacity * sizeof(struct Stack)));
	
	return stack;
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

void push(struct Stack *stack, char ch)
{
	stack->array[++stack->top] = ch;
}

char pop(struct Stack *stack)
{
	char popped = stack->array[stack->top--];
	return popped;
}

char peek(struct Stack *stack)
{
	char ch = stack->array[stack->top];
	return ch;
}

void evalpostfix(char *exp)
{
	int len = strlen(exp);
	struct Stack *stack = createStack(len);
	int i=0;
	
	if (!stack) 
	return ;
	
	
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		{
			push(stack, exp[i]-'0');
		}
		
		else
		{
			int val1 = pop(stack) ;
			int val2 = pop(stack) ;
			switch (exp[i])
            {
             case '+': push(stack, val2 + val1); break;
             case '-': push(stack, val2 - val1); break;
             case '*': push(stack, val2 * val1); break;
             case '/': push(stack, val2/val1);   break;
            }
		}
		i++;
	}
	
	int answer = pop(stack);
	printf("the result is = %d", answer);
}

int main()
{
	char postfix[] = "231*+9-";
	evalpostfix(postfix);
	return 0;
}
