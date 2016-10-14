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



void balanced(char *exp)
{
	int len = strlen(exp);
	struct Stack *stack = createStack(len);
	int i=0;

	while(exp[i]!='\0')
	{
		if(exp[i] == '(' || exp[i]=='{' || exp[i]=='[' )
		{
			push(stack, exp[i]);
		}
		
		else if(exp[i]==')')
		{
			char chk1 = pop(stack);
			if(chk1!='(')
			{printf("NOT balanced");}
			return ;
			
		}
		
		
		
		else if(exp[i]=='}')
		{
			char chk1 = pop(stack);
			if(chk1!='{')
			{printf("NOT balanced");}
			return ;
			
		}
		
		else if(exp[i]==']')
		{
			char chk1 = pop(stack);
			if(chk1!='[')
			{printf("NOT balanced");}
			return ;
		
		}
		i++;
	}
	
	if(!isEmpty(stack))
	{
		printf("NOT balanced");
		return ;
	}
	
	else
	{
		printf("BALANCED");
	}
}





int main()
{
	char para[] = "{{([([{{}}])])}}[[[({{}})]]]";
	balanced(para);
	return 0;
}
