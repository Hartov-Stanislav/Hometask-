#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "MergeSort.h"

void callMenu()
{
	printf("Choose the type of sorting : \n 1) sort by name\n 2) sort by phone\n");
}

int main() {
	FILE* input = fopen("input.txt", "r");
	if (!input) {
		printf("File can not be opened\n");
		return 1;
	}
	struct List* list = createList();
	while (!feof(input)) {
		char name[20] = { 0 };
		char phone[20] = { 0 };
		fscanf(input, "%s %s", name, phone);
		addEntry(list, name, phone);
	}
	fclose(input);
	callMenu();
	int typeOfSorting = 0;
	scanf("%d", &typeOfSorting);
	struct List* sortedList = mergeSort(list, typeOfSorting);
	printf("Sorted list:\n");
	printList(sortedList);
	deleteList(sortedList);
	return 0;
}