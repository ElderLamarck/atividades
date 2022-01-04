#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
	char character;
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

void push(struct pile *pile, char character)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));

	node->character = character;
	node->next = pile->head;
	pile->head = node;
}

int is_open(char character)
{
	if (character == '(') {
		return 1;
	} else if (character == '{') {
		return 1;
	} else if (character == '[') {
		return 1;
	} else {
		return 0;
	}
}

void pop(struct pile *pile)
{
	struct node *pointer = pile->head;

	pile->head = pointer->next;
	free(pointer);
}

int main(void)
{
	int key;
	int count = 0;
	int i = 0;
	int test = 0;
	char character[100000];

	struct pile *pile = create_pile();

	scanf("%d", &key);
	while (count < key) {
		scanf("%s", character);
		while (character[i] != '\0') {
			test = is_open(character[i]);
			if (test == 1) {
				push(pile, character[i]);
				i++;
			} else {
				//caso especial (primeiro valor = "}])")
				if (pile->head == NULL) {
					push(pile, character[i]);
					break;
				}
				if (character[i] == ')') {
					if (pile->head->character == '(') {
						pop(pile);
						i++;
					} else {
						break;
					}
				} else if (character[i] == '}') {
					if (pile->head->character == '{') {
						pop(pile);
						i++;
					} else {
						break;
					}
				} else if (character[i] == ']') {
					if (pile->head->character == '[') {
						pop(pile);
						i++;
					} else {
						break;
					}
				}
			}
		}
		if (pile->head == NULL) {
			printf("S\n");
		} else {
			printf("N\n");
		}
		while (pile->head != NULL) {
			pop(pile);
		}
		i = 0;
		count++;
	}
	return 0;
}