#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

typedef struct Entry
{
	char* name;
	char* phone;
	struct Entry* next;
} Entry;

typedef struct List
{
	int length;
	struct Entry* head;
	struct Entry* tail;
} List;

struct List* createList()
{
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

bool isEmpty(struct List* list)
{
	return list->head == NULL;
}

void addEntry(struct List* list, const char name[], const char phone[])
{
	list->length++;
	struct Entry* newEntry = malloc(sizeof(struct Entry));
	if (newEntry == NULL)
	{
		return;
	}
	newEntry->name = malloc(strlen(name) + 1);
	newEntry->phone = malloc(strlen(phone) + 1);

	strcpy(newEntry->name, name);
	strcpy(newEntry->phone, phone);
	if (isEmpty(list))
	{
		list->head = newEntry;
		newEntry->next = NULL;
		list->tail = list->head;
		return;
	}
	list->tail->next = newEntry;
	list->tail = list->tail->next;
	list->tail->next = NULL;
}

void printList(struct List* list)
	{
	if (isEmpty(list))
	{
		return;
	}
	struct Entry* current = list->head;
	while (current != NULL)
	{
		printf("%s   %s\n", current->name, current->phone);
		current = current->next;
	}
}

void deleteHead(struct List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	list->length--;
	struct Entry* temp = list->head->next;
	free(list->head->name);
	free(list->head->phone);
	free(list->head);
	list->head = temp;
}

void deleteList(struct List* list)
{
	while (!isEmpty(list))
	{
		deleteHead(list);
	}
	free(list);
}

char* returnNameFromHead(struct List* list)
{
	return list->head->name;
}

char* returnPhoneFromHead(struct List* list)
{
	return list->head->phone;
}

int listLength(struct List* list)
{
	return list->length;
}