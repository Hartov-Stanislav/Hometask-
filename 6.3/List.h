#pragma once

typedef struct List List;

// Creates list
List* createList();

// Checks, that list is empty, recieves list
bool isEmpty(List* list);

// Adds new record in list, recieves list, name of human and his phone number
void addEntry(List* list, const char name[], const char phone[]);

// Prints all list, recieves list
void printList(List* list);

// Deletes all list, recieves list
void deleteList(List* list);

// Delete element in head of list, recieves list
void deleteHead(List* list);

// Gets phone name from head of list, recieves list
char* returnNameFromHead(List* list);

// Gets phone number from head of list, recieves list
char* returnPhoneFromHead(List* list);

// Gets length of list, recieves list
int listLength(List* list);