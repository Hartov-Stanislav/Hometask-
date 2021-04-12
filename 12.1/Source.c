#include "FSM.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX  500

bool tests()
{
	FILE* test = fopen("Test.txt", "r");
	if (test == NULL)
	{
		return false;
	}
	FILE* answers = fopen("answer.txt", "r");
	if (answers == NULL)
	{
		fclose(test);
		return false;
	}
	bool result = true;
	while (!feof(test))
	{
		char string[MAX] = "";
		int answer = 0;
		fgets(string, MAX, test);
		fscanf(answers, "%i", &answer);
		result &= isRealNumber(string) == answer;
	}
	fclose(test);
	fclose(answers);
	return result;
}

int main()
{
	if (!tests())
	{
		printf("Tests failed");
		return 1;
	}
	printf("Please enter an expression: ");
	char string[MAX] = "";
	gets_s(string, MAX);
	if (isRealNumber(string))
	{
		printf("It's a real number\n");
		return 0;
	}
	printf("It's not a real number\n");
	return 0;
}