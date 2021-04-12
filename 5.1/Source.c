#include "../../Stack/Stack/Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

bool getValues(int* a, int* b, StackElement** head)
{
	if (isEmpty(*head))
	{
		return false;
	}
	*a = top(*head);
	*head = deleteTop(*head);
	if (isEmpty(*head))
	{
		return false;
	}
	*b = top(*head);
	*head = deleteTop(*head);
	return true;
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*';
}

bool getAnExpressionValue(char string[], int* result)
{
	StackElement* head = NULL;
	for (int i = 0; string[i] != '\0'; i++)
	{
		int a = 0;
		int b = 0;
		if (isdigit(string[i]))
		{
			head = push(head, string[i] - '0');
			continue;
		}
		if (isOperator(string[i]) && !getValues(&a, &b, &head))
		{
			freeStack(head);
			return true;
		}
		switch (string[i])
		{
		case '+':
			head = push(head, b + a);
			break;
		case '-':
			head = push(head, b - a);
			break;
		case '*':
			head = push(head, b * a);
			break;
		case '/':
			head = push(head, b / a);
			break;
		default:
			break;
		}
	}
	*result = top(head);
	head = deleteTop(head);
	if (!isEmpty(head))
	{
		freeStack(head);
		return true;
	}
	return false;
}

bool test()
{
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		return false;
	}
	bool result = true;
	while (!feof(input))
	{
		char string[MAX] = "";
		fgets(string, MAX, input);
		char answer1[MAX] = "";
		fgets(answer1, MAX, input);
		int answer = 0;
		getAnExpressionValue(string, &answer);
		result &= ((answer1[0] - '0') == answer);
	}
	fclose(input);
	return result;
}

int main()
{
	if (!test())
	{
		printf("tests failed");
		return 1;
	}
	printf("Please enter an expression: ");
	char string[1000] = "";
	gets(string);
	int answer = 0;
	if (getAnExpressionValue(string, &answer))
	{
		printf("Invalid expression");
		return 0;
	}
	printf("The result: %i\n", answer);

	return 0;
}