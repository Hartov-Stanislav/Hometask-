#define _CRT_SECURE_NO_WARNINGS

#include "PhoneBook.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct PhoneBook {
	char name[25];
	char number[15];
}PhoneBook;

char* findNumber(const char name[], const int size, PhoneBook book[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(name, book[i].name) == 0)
		{
			return book[i].number;
		}
	}
	return "Not found";
}

char* findName(const char number[], const int size, PhoneBook book[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(number, book[i].number) == 0)
		{
			return book[i].name;
		}
	}
	return "Not found";
}

void printBook(const PhoneBook book[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s    %s\n", book[i].name, book[i].number);
	}
}

bool saveDataToFile(const int size, const PhoneBook book[], const char file[])
{
	FILE* phones = fopen(file, "w");
	if (phones == NULL)
	{
		printf("File not found!");
		return true;
	}
	for (int i = 0; i < size; i++)
	{
		fprintf(phones, "%s    %s\n", book[i].name, book[i].number);
	}
	fclose(phones);
	return false;
}

bool readPhoneBook(PhoneBook book[], int* amountOfRecords, const char file[])
{
	FILE* phones = fopen(file, "r");
	if (phones == NULL)
	{
		printf("File not found!");
		return true;
	}
	while (!feof(phones))
	{
		fscanf(phones, "%s %s", &book[*amountOfRecords].name, &book[*amountOfRecords].number);
		(*amountOfRecords)++;
	}
	fclose(phones);
	return false;
}