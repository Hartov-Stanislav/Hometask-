#include "Tests.h"
#include "PhoneBook.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX  50

void callMenu()
{
	printf("0 - exit\n1");
	printf("1 - add record\n");
	printf("2 - print all rocords\n");
	printf("3 - find number by name\n");
	printf("4 - find name by number\n");
	printf("5 - save actual data to the file\n");
}

int main()
{
	if (!tests())
	{
		printf("Tests failed\n");
		return 0;
	}
	printf("Tests succeed\n");
	struct PhoneBook records[50];
	int countRecords = 0;
	if (readInitialDirectory(records, &countRecords, "Phone_Book.txt"))
	{
		return 0;
	}
	callMenu();
	while (true)
	{
		printf("Please enter code\n");
		int code = 0;
		scanf("%i", &code);
		switch (code)
		{
		case 0:
			return 0;
		case 1:
			if (countRecords >= MAX)
			{
				printf("Can't add more than 100 records\n");
				continue;
			}
			printf("Please enter name and phone number ");
			scanf("%s %s", &records[countRecords].name, &records[countRecords].number);
			countRecords++;
			break;
		case 2:
			printRecords(records, countRecords);
			break;
		case 3:
			printf("Enter name ");
			char name[20];
			scanf("%s", &name);
			printf("%s\n", findNumber(name, countRecords, records));
			break;
		case 4:
			printf("Enter number ");
			char number[12];
			scanf("%s", &number);
			printf("%s\n", findName(number, countRecords, records));
			break;
		case 5:
			saveDataToFile(countRecords, records, "Phone_Book.txt");
			break;
		default:
			printf("Incorrect data\n");
			break;
		}
	}
	return 0;
}