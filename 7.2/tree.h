#pragma once
#include <stdbool.h>

typedef struct Tree Tree;

// Creates new empty tree
Tree* makeTree(void);

// Builds tree by string, recivies tree and string
void buildTree(Tree* tree, char* string);

// Returns result of expression, recives tree
int getExpressionResult(Tree* tree);

// Deletes all tree, recives tree
void freeTree(Tree * tree);
