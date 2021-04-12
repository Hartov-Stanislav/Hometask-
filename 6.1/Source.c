#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

bool tests() 
{
	struct List* list1 = createList();
	struct List* list2 = createList();
	addValue(6, list1);
	if (isEmpty(list1) && !isEmpty(list2))
	{
		deleteList(list1);
		deleteList(list2);
		return false;
	}
	deleteValue(list1, 6);
	if (!isEmpty(list1) && !isEmpty(list2))
	{
		return false;
	}
	deleteList(list1);
	deleteList(list2);
	return true;
}

void callMenu() 
{
	printf("Choose the state:\n");
	printf("0)Exit\n");
	printf("1)Add value in list\n");
	printf("2)Delete value from list\n");
	printf("3)Print list:\n");
}

int main() {
	if (!tests()) 
	{
		printf("Tests failed");
		return 1;
	}
	struct List* list = createList();
	int exit = 0;
	while (exit == 0) 
	{
		callMenu();
		int state = 0;
		scanf("%d", &state);
		switch (state)
		{
		case 0:
		{
			exit = 1;
			break;
		}
		case 1: 
		{
			printf("Please, enter value: ");
			int value = 0;
			scanf("%d", &value);
			addValue(value, list);
			break;
		}
		case 2:
		{
			printf("Enter value to delete: ");
			int value = 0;
			scanf("%d", &value);
			deleteValue(list, value);
			break;
		}
		case 3:
		{
			printList(list);
			break;
		}
		default:
		{
			printf("Wrong argument\n");
			break;
		}
		}
	}
	deleteList(list);
	return 0;
}