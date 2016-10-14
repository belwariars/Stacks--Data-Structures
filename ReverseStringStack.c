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



void reverse(char *ch)
{
	int len = strlen(ch);
	
	struct Stack *stack = createStack(len);
	
	int i=0;
	while(ch[i]!= '\0')
	{
		push(stack, ch[i]);
		i++;
	}
	int j;
	
	for(j=0;j<len;j++)
	{
		printf("%c", pop(stack));
	}
}





int main()
{
	char postfix[] = "shivang belwariar";
	reverse(postfix);
	return 0;
}
