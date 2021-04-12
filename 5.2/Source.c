#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../Stack/Stack/Stack.h"

bool checkBalance(char string[]) {
	StackElement* stack = NULL;
	const int length = strlen(string);
	for (int i = 0; i < length; i++) {
		switch (string[i]) {
		case '(':
		case '{':
		case '[':
			stack = push(stack, string[i]);
			break;
		case ')':
		case '}':
		case ']':
			if (isEmpty(stack))
			{
				freeStack(stack);
				return false;
			}
			char symbol = top(stack);
			stack = deleteTop(stack);
			if ((string[i] == ')' && symbol != '(') || (string[i] == '}' && symbol != '{') || (string[i] == ']' && symbol != '['))
			{
				freeStack(stack);
				return false;
			}
			break;
		}
	}
	const bool balance = isEmpty(stack);
	freeStack(stack);
	return balance;
}

bool tests()
{
	return (checkBalance("({ [] })") && checkBalance("()") && !checkBalance(")"));
}

int main() {
	if (!tests())
	{
		printf("Tests failed");
		return 1;
	}
	printf("Enter the string: ");
	char string[100];
	scanf("%s", string);
	if (!checkBalance(string)) {
		printf("Not balanced\n");
	}
	else {
		printf("Balanced\n");
	}
	return 0;
}