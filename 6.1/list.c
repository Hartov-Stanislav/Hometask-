#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* next;
};

struct List
{
	struct Node* head;
};

struct List* createList()
{
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

void addValue(int value, struct List* list)
{
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->value = value;
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
	{
		newNode->next = list->head;
		list->head = newNode;
	}
	else
	{
		previous->next = newNode;
		newNode->next = current;
	}
}

void deleteValue(struct List* list, int value)
{
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL)
	{
		return;
	}
	if (current->value != value)
	{
		return;
	}
	struct Node* temp = current->next;
	free(current);
	if (previous == NULL)
	{
		list->head = temp;
	}
	else
	{
		previous->next = temp;
	}
}

bool isEmpty(struct List* list)
{
	return list->head == NULL;
}

void deleteList(struct List* list)
{
	while (!isEmpty(list))
	{
		struct Node* temp = list->head->next;
		deleteValue(list, list->head->value);
		list->head = temp;
	}
}

void printList(struct List* list)
{
	struct Node* current = list->head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}