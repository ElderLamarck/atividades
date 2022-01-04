#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
	int value;
    int level;
	struct node *next;
};

struct pile {
	struct node *head;
};

struct pile *create_pile(void)
{
	struct pile *pile = (struct pile *)malloc(sizeof(struct pile));
	pile->head = NULL;
	return pile;
}

void push(struct pile *pile, int value, int level)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));

	node->value = value;
	node->level = level;
	node->next = pile->head;
	pile->head = node;
}

void pop(struct pile *pile)
{
	struct node *pointer = pile->head;

	pile->head = pointer->next;
	free(pointer);
}

int main(void) 
{
	char tree;
	int value, level;

	struct pile *pile = create_pile();
	while (scanf("%c", &tree) != '\n')
	{
		printf("%c\n",tree);
	}
	scanf("%d", &value);
	
	return 0;
}