#pragma once

struct List;

// Creates list
struct List* createList();

// Adds value in sorted list, recisves value and list
void addValue(int value, struct List* list);

// Delete element in list by value, recives value and list
void deleteValue(struct List* list, int value);

// Checks, that list is empty, recieves list
bool isEmpty(struct List* list);

// Deletes all list, recieves list
void deleteList(struct List* list);

// Prints all list, recieves list
void printList(struct List* list);