#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

int isEmpty(struct node *root)
{
	if(root==NULL)
	{
//		printf("the stack is empty");
		return 1;
	}
	
	else
	{return 0;}
}

void push(struct node **root, int data)
{
	if(isEmpty(*root))
	{
		*root = newNode(data);
		printf("the pushed node is %d\n", (*root)->data);
		return ;
	}
	
	struct node *temp =  newNode(data);
	
	temp->next = *root;
	*root= temp;
	printf("the pushed node is %d\n", temp->data);
	
	
}

int pop(struct node **root)
{
	if(isEmpty(*root))
	{
		return INT_MIN;
	}
	
	if((*root)->next == NULL)
	{
		int rootpop = (*root)->data;
		*root == NULL;
		return rootpop;
	}
	
	struct node *temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	
	printf("the poped node is %d\n", popped);
	return popped;
}

int peek(struct node **root)
{
	int peeked = (*root)->data;
	
	printf("%d\n", peeked);
	return peeked;
}

int main()
{
	struct node *root = NULL;
	push(&root, 20);
	push(&root, 30);
	push(&root, 40);
	peek(&root);
	pop(&root);
	peek(&root);
	return 0;
}


