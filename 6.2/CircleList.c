#include <stdlib.h>
#include <stdbool.h>
#include "CircleList.h"

struct Node
{
	int value;
	struct Node* next;
};

struct List
{
	struct Node* head;
	struct Node* tail;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

bool isEmpty(struct List* list) {
	return list->head == NULL;
}

void addValue(struct List* list, int value) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	newNode->value = value;
	if (isEmpty(list)) {
		list->head = newNode;
		list->head->next = list->head;
		list->tail = list->head;
	}
	else {
		list->tail->next = newNode;
		list->tail = list->tail->next;
		list->tail->next = list->head;
	}
}

bool headIsTail(struct List* list) {
	return list->head == list->tail;
}

void deleteValue(struct List* list, int positionNumber)
{
	if (headIsTail(list)) {
		deleteList(list);
		return;
	}
	struct Node* current = list->head;
	struct Node* previous = list->tail;
	for (int i = 1; i < positionNumber; ++i) {
		previous = current;
		current = current->next;
	}
	struct Node* oldElement = current;
	list->head = current->next;
	list->tail = previous;
	previous->next = current->next;
	free(oldElement);
}


int headValue(struct List* list) {
	if (list->head->value != NULL) {
		return list->head->value;
	}
	return NULL;
}

void deleteList(struct List* list)
{
	while (!headIsTail(list)) 
	{
		deleteValue(list, 1);
	}
	free(list->head);
	free(list);
}