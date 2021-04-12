#include "DFA.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 500

bool check(char* string, char* answer, int** table)
{
	char* resultString = DFA(table, string);
	bool result = strcmp(resultString, answer) == 0;
	if (strcmp(resultString, "") != 0)
	{
		free(resultString);
	}
	resultString = NULL;
	return result;
}

bool tests(int** table)
{
	bool result = true;
	result &= check("dsfab", "", table);
	result &= check("/**/", "/**/", table);
	result &= check("/*ef*/", "/*ef*/", table);
	result &= check("*/*/*/", "/*/*/", table);
	result &= check("/*fhios*/ fken /*a*/", "/*fhios*//*a*/", table);
	return result;
}

void clearTable(int** table)
{
	for (int i = 0; i < statesNumber; i++)
	{
		free(table[i]);
	}
	free(table);
	table = NULL;
}

int main()
{
	int** table = readTable();
	if (!tests(table))
	{
		clearTable(table);
		printf("Tests failed");
		return 1;
	}
	printf("Tests succeed\n");

	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		return 1;
	}
	while (!feof(input))
	{
		char string[MAX] = "";
		fgets(string, MAX, input);
		char* answer = DFA(table, string);
		printf("%s\n", answer);
		free(answer);
	}
	fclose(input);
	clearTable(table);
	return 0;
}