#include "Dictionary.h"
#include <string.h>
#include <stdio.h>

#define MAX 100

callMenu()
{
	printf("Commands\n");
	printf("0: quit\n");
	printf("1: add value by key.If key already in the dictionary, value will be replaced\n");
	printf("2: get value by key\n");
	printf("3: check whether key is in the dictionary\n");
	printf("4: remove the key and its value\n");
}

bool test()
{
	Dictionary* dictionary = createDictionary();
	char* value = "adafa";
	addRecord(dictionary, "1", value);
	addRecord(dictionary, "2", value);
	addRecord(dictionary, "3", value);
	addRecord(dictionary, "4", value);
	bool result = true;
	result &= (isContained(dictionary, "1") && isContained(dictionary, "2"));
	result &= (strcmp(findValueByKey(dictionary, "1"), value) == 0 && strcmp(findValueByKey(dictionary, "3"), value) == 0);
	addRecord(dictionary, "9", "aagf");
	result &= strcmp(findValueByKey(dictionary, "9"), "aagf") == 0;
	removeRecord(dictionary, "9");
	removeRecord(dictionary, "1");
	removeRecord(dictionary, "3");
	removeRecord(dictionary, "4");
	removeRecord(dictionary, "2");
	result &= (!isContained(dictionary, "1") && !isContained(dictionary, "2") && !isContained(dictionary, "3") && !isContained(dictionary, "4"));
	freeDictionary(dictionary);
	return result;
}

int main()
{
	if (!test())
	{
		printf("Tests failed");
		return 1;
	}
	Dictionary* dictionary = createDictionary();
	while (true)
	{
		int code = 0;
		char value[MAX] = "";
		char key[MAX] = "";
		callMenu();
		scanf("%d", &code);
		switch (code)
		{
		case 0:
			freeDictionary(dictionary);
			dictionary = NULL;
			return 0;
		case 1:
			printf("Enter key ");
			scanf("%s", &key);
			printf("Enter value ");
			scanf("%s", &value);
			addRecord(dictionary, key, value);
			break;
		case 2:
			printf("Enter key ");
			scanf("%s", &key);
			char* string = findValueByKey(dictionary, key);
			if (string == NULL)
			{
				printf("Key not found\n");
				break;
			}
			printf("Value: %s\n", string);
			break;
		case 3:
			printf("Enter key ");
			scanf("%s", &key);
			if (isContained(dictionary, key))
			{
				printf("Key is in the dictionary\n");
			}
			else
			{
				printf("Key is not in the dictionary\n");
			}
			break;
		case 4:
			printf("Enter key ");
			scanf("%s", &key);
			removeRecord(dictionary, key);
		default:
			break;
		}
	}
	return 0;
}