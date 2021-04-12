#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// is this symbol *,/,+,-
bool isOperator(char operator)
{
	return operator == '+' || operator == '-' || operator == '*' || operator == '/';
}

// adds symbol in answer string
void addSymbolInString(char string[], int* index, const char symbol)
{
	string[(*index)] = symbol;
	(*index)++;
	string[*index] = ' ';
	(*index)++;
}

// main function
bool infixToPostfix(char answer[], const char string[])
{
	StackElement* head = NULL;
	int index = 0;
	for (int i = 0; string[i] != '\0' && string[i] != '\n'; i++)
	{
		if (isdigit(string[i]))
		{
			addSymbolInString(answer, &index, string[i]);
		}
		else if (string[i] == '(')
		{
			head = push(head, '(');
			if (head == NULL)
			{
				free(head);
				strcpy(answer, "Error");
				return true;
			}
		}
		else if (string[i] == '*' || string[i] == '/')
		{
			while (head != NULL && (top(head) == '*' || top(head) == '/'))
			{
				addSymbolInString(answer, &index, top(head));
				head = deleteTop(head);
			}
			head = push(head, string[i]);
			if (head == NULL)
			{
				free(head);
				strcpy(answer, "Error");
				return true;
			}
		}
		else if (string[i] == '+' || string[i] == '-')
		{
			while (head != NULL && isOperator(top(head)))
			{
				addSymbolInString(answer, &index, top(head));
				head = deleteTop(head);
			}
			head = push(head, string[i]);
			if (head == NULL)
			{
				free(head);
				strcpy(answer, "Error");
				return true;
			}
		}
		else if (string[i] == ')')
		{
			while (top(head) != '(')
			{
				if (head == NULL)
				{
					freeStack(head);
					strcpy(answer, "Invalid expression");
					return true;
				}
				addSymbolInString(answer, &index, top(head));
				head = deleteTop(head);
			}
			head = deleteTop(head);;
		}
		else if (string[i] != ' ')
		{
			freeStack(&head);
			strcpy(answer, "Invalid expression");
			return true;
		}
	}
	while (head != NULL)
	{
		char token = top(head);
		head = deleteTop(head);
		if (token == '(')
		{
			freeStack(head);
			strcpy(answer, "Error");
			return true;
		}
		addSymbolInString(answer, &index, token);
	}
	freeStack(head);
	return false;
}

// function for tests, which compares 2 strings
bool checkEquality(const char string1[], const char string2[])
{
	size_t length1 = strlen(string1);
	size_t length2 = strlen(string2);
	if (string1[length1 - 1] == '\n')
	{
		length1--;
	}
	if (string2[length2 - 1] == '\n')
	{
		length2--;
	}
	if (length1 != length2)
	{
		return false;
	}
	for (int i = 0; string2[i] != '\n' && string2[i] != '\0'; i++)
	{
		if (string1[i] != string2[i])
		{
			return false;
		}
	}
	return true;
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
		char answer[MAX] = "";
		infixToPostfix(answer, string);
		result &= checkEquality(answer1, answer);
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
	printf("Please enter an expression\n");
	char string[MAX] = "";
	gets(string);
	char answer[MAX] = "";
	if (infixToPostfix(answer, string))
	{
		printf("%s", answer);
		return 1;
	}
	printf("Answer is %s", answer);
	return 0;
}