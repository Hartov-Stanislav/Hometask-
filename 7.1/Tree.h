#pragma once
#define SIZE 101

struct Tree;

// Creates tree
struct Tree* createTree();

// Checks, that tree is empty
bool isEmpty(struct Tree* tree);

// Adds element in tree by key, recivies key, value and tree
void addValue(int key, char* value, struct Tree* tree);

// Gets value by key, recivies key and tree
char* getValue(struct Tree* tree, int key);

// Checks, that element with those key in tree, recivies key and tree
bool contains(struct Tree* tree, int key);

// Deletes root, recivies tree
void deleteRoot(struct Tree* tree);

// Deletes value by key,recivies key and tree
void deleteValue(struct Tree* tree, int key);

// Deletes all tree
void deleteTree(struct Tree* tree);