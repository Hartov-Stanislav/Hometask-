#include "Hash-Table.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int main()
{
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		printf("Can't open file\n");
		return 1;
	}
	HashTable* hashTable = makeHashTable();
	while (!feof(input))
	{
		char word[MAX] = "";
		fscanf(input, "%s", &word);
		addToTheTable(hashTable, word);
	}
	fclose(input);

	printHashTable(hashTable);
	printf("\nLoad factor: %.5f\n", getLoadFactor(hashTable));
	printf("Maximum list length: %i\n", getMaxListLength(hashTable));
	printf("Average list length: %i\n", getAverageListLength(hashTable));

	deleteHashTable(&hashTable);
	return 0;
}