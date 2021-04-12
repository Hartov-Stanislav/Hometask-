#pragma once
#include <stdbool.h>

typedef struct PhoneBook PhoneBook;

// Searching name by number, recieves number, size of the string and phone book. Returns found string
char* findName(const char number[], const int size, PhoneBook book[]);

// Searching number by name: recieves name, size of the string and phone book. Returns found string
char* findNumber(const char name[], const int size, PhoneBook book[]);

// Prints all records from the phone book
void printBook(const PhoneBook book[], const int size);

// Saves all records to file
bool saveDataToFile(const int size, const PhoneBook book[], const char file[]);

// Reads phone book from file
bool readPhoneBook(PhoneBook book[], int* amountOfRecords, const char file[]);