#include "List.h"
#include "Hash-Table.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

typedef struct HashTable {
	int numberOfEntries;
	int numberOfBuckets;
	List** list;
} HashTable;

double getLoadFactor(HashTable* table)
{
	return (double)table->numberOfEntries / table->numberOfBuckets;
}

int getMaxListLength(HashTable* table)
{
	int maxLength = -1;
	for (int i = 0; i < table->numberOfBuckets; i++)
	{
		maxLength = (maxLength > getListLength(table->list[i]) ? maxLength : getListLength(table->list[i]));
	}
	return maxLength;
}

int getAverageListLength(HashTable* table)
{
	if (table == NULL || table->numberOfEntries == 0)
	{
		return 0;
	}
	int totalLength = 0;
	for (int i = 0; i < table->numberOfBuckets; i++)
	{
		totalLength += getListLength(table->list[i]);
	}
	return (totalLength / (table->numberOfBuckets));
}

void makeListTable(HashTable* table)
{
	table->list = calloc(table->numberOfBuckets, sizeof(List*));
	if (table->list == NULL)
	{
		return;
	}
	for (int i = 0; i < table->numberOfBuckets; i++)
	{
		table->list[i] = makeList();
	}
}

void printHashTable(HashTable* table)
{
	if (table == NULL)
	{
		return;
	}
	for (int i = 0; i < table->numberOfBuckets; i++)
	{
		if (isEmpty(table->list[i]))
		{
			continue;
		}
		Position pointer = getFirst(table->list[i]);
		while (!isEnd(pointer))
		{
			printf("%s - %i\n", getValue(pointer), getFrequency(pointer));
			pointer = nextItem(pointer);
		}
	}
}

HashTable* makeHashTable()
{
	HashTable* hashTable = calloc(1, sizeof(HashTable));
	if (hashTable == NULL)
	{
		return NULL;
	}
	hashTable->numberOfBuckets = MAX;
	makeListTable(hashTable);
	return hashTable;
}

int countHashFunction(char* string, int size)
{
	int hashFunction = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		hashFunction = (hashFunction + string[i]) % size;
	}
	return abs(hashFunction);
}

void addToTheTable(HashTable* table, char* string)
{
	if (addItem(table->list[countHashFunction(string, table->numberOfBuckets)], string))
	{
		table->numberOfEntries++;
	}
}

void deleteHashTable(HashTable** table)
{
	if (*table == NULL)
	{
		return;
	}
	for (int i = 0; i < (*table)->numberOfBuckets; i++)
	{
		freeList(&((*table)->list[i]));
	}
	free((*table)->list);
	free(*table);
}