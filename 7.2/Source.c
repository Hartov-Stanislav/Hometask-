#include "Tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int checkExpression(char* expression)
{
	Tree* tree = makeTree();
	buildTree(tree, expression);
	int result = getExpressionResult(tree);
	freeTree(tree);
	return result;
}

bool test()
{
	bool result = checkExpression("+ 1 1") == 2;
	result &= checkExpression("* ( + 1 1 ) 2") == 4;
	result &= checkExpression("* (* 1 2 ) 3") == 6;
	return result;
}

int main()
{
	if (!test())
	{
		printf("Tests failed");
		return 1;
	}
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		printf("File not found");
		return 1;
	}
	char expression[1000] = "";
	fgets(expression, 1000, input);
	fclose(input);
	Tree* tree = makeTree();
	buildTree(tree, expression);
	printf("%s = %i", expression, getExpressionResult(tree));
	freeTree(tree);
	return 0;
}