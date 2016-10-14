#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isOperand(char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
			
		case '*':
		case '/':
			return 2;
			
		case '^':
			return 3;
	}
	
	return -1;
}


void infixToPostfix(char *exp)
{
	int i;
	int j =0;
	int len = strlen(exp);
	
	struct Stack* stack = createStack(strlen(exp));
	
	char postfix[len];
	
	for(i=0;i<len;i++)
	{
		if(isOperand(exp[i]))
		{
			postfix[j] = exp[i];
			j++;
		}
		
		else if(exp[i]=='(')
		{
			push(stack, exp[i]);
		}
		
		else if(exp[i] == ')')
		{
			while(!isEmpty(stack) && peek(stack) != '(')
			{
				postfix[j] = pop(stack);
				j++;
			}
			pop(stack);
		}
		
		else
		{
			while(precedence(peek(stack))>= precedence(exp[i]) && !isEmpty(stack))
			{
				postfix[j] = pop(stack);
				j++;
			}
			
			push(stack, exp[i]);
		}
	}
	
	while(!isEmpty(stack))
	{
		postfix[j] = pop(stack);
		j++;
	}
	
	postfix[j] = '\0';
	
	printf( "%s\n", postfix );
	
}

int main()
{
	char infix[] = "((a+b)*c)/d";
	
	infixToPostfix(infix);
	return 0;
}
