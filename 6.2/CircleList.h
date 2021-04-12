#pragma once
#include <stdbool.h>

struct List;

// Creates list
struct List* createList();

// Checks, that list is empty, recieves list
bool isEmpty(struct List* list);

// Add value in circle list, recisves value and list
void addValue(struct List* list, int value);

// Deletes value from list, recives position to deletion and list
void deleteValue(struct List* list, int positionNumber);

// Checks, that list has 1 element, recieves list
bool headIsTail(struct List* list);

// Returns value in head of list, recieves list
int headValue(struct List* list);

// Deletes all list, recieves list
void deleteList(struct List* list);