#pragma once
#include <stdbool.h>

typedef struct Dictionary Dictionary;

// Create new empty dictionary
Dictionary* createDictionary(void);

// Add them to the dictionary. If it's already exists, changes value, recieves dictionary, key and value
void addRecord(Dictionary* dictionary, char* key, char* value);

// Returns value by key, recieves dictionary and key
char* findValueByKey(Dictionary* dictionary, const char* key);

// Returns 'true' if key is in dictionary, otherwise 'false', recieve dictionary and key
bool isContained(Dictionary* dictionary, const char* key);

// Deletes record by key, recieves dictionary and key
void removeRecord(Dictionary* dictionary, const char* key);

// Removes all dictionary, recieves dictionary
void freeDictionary(Dictionary* dictionary);