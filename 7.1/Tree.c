#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "Tree.h"

struct Node {
	int key;
	char* value;
	struct Node* parent;
	struct Node* leftChild;
	struct Node* rightChild;
};

struct Tree {
	struct Node* root;
};

struct Tree* createTree()
{
	struct Tree* newTree = calloc(1, sizeof(struct Tree));
	return newTree;
}

bool isEmpty(struct Tree* tree)
{
	return tree->root == NULL;
}

void insert(int key, char* value, struct Node* node)
{
	if (key == node->key)
	{
		free(node->value);
		node->value = value;
		return;
	}
	if (key < node->key)
	{
		if (node->leftChild == NULL)
		{
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->key = key;
			newNode->value = value;
			newNode->parent = node;
			node->leftChild = newNode;
			return;
		}
		insert(key, value, node->leftChild);
	}
	if (key > node->key)
	{
		if (node->rightChild == NULL)
		{
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->key = key;
			newNode->value = value;
			newNode->parent = node;
			node->rightChild = newNode;
			return;
		}
		insert(key, value, node->rightChild);
	}
}

void addValue(int key, char* value, struct Tree* tree)
{
	char* newValue = calloc(SIZE, (sizeof(char)));
	if (newValue == NULL)
	{
		return;
	}
	strcpy(newValue, value);

	if (isEmpty(tree))
	{
		struct Node* newNode = calloc(1, sizeof(struct Node));
		tree->root = newNode;
		newNode->key = key;
		newNode->value = newValue;
		return;
	}
	insert(key, newValue, tree->root);
}

struct Node* get(struct Node* node, int key)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->key == key)
	{
		return node;
	}
	else if (node->key > key)
	{
		return get(node->leftChild, key);
	}
	else 
	{
		return get(node->rightChild, key);
	}
}

char* getValue(struct Tree* tree, int key)
{
	struct Node* newNode = get(tree->root, key);
	return newNode->value;
}

bool contains(struct Tree* tree, int key)
{
	return get(tree->root, key) != NULL;
}

struct Node* findTheNearestLesserElement(struct Node* node)
{
	struct Node* mostNearest = node->leftChild;
	while (mostNearest->rightChild != NULL)
	{
		mostNearest = mostNearest->rightChild;
	}
	return mostNearest;
}

void deleteNode(struct Tree* tree, struct Node* node, int key)
{
	if (node == NULL)
	{
		return;
	}
	if (key == node->key)
	{
		if (node->leftChild == NULL && node->rightChild == NULL)
		{
			if (node->key < node->parent->key)
			{
				node->parent->leftChild = NULL;
			}
			else
			{
				node->parent->rightChild = NULL;
			}
			free(node->value);
			free(node);
			return;
		}
		if (node->leftChild != NULL && node->rightChild != NULL)
		{
			struct Node* helpingNode = findTheNearestLesserElement(node);
			struct Node* newNode = calloc(1, sizeof(struct Node));
			newNode->value = calloc(SIZE, sizeof(char));
			strcpy(newNode->value, helpingNode->value);
			newNode->key = helpingNode->key;

			deleteNode(tree, helpingNode, helpingNode->key);
			node->key = newNode->key;
			strcpy(node->value, newNode->value);
			free(newNode->value);
			free(newNode);
			return;
		}
		else if (node->rightChild == NULL)
		{
			if (node->parent != NULL)
			{
				if (node->leftChild != NULL)
				{
					node->leftChild->parent = node->parent;
				}
				if (key < node->parent->key)
				{
					node->parent->leftChild = node->leftChild;
				}
				else
				{
					node->parent->rightChild = node->leftChild;
				}
				free(node->value);
				free(node);
			}
			else
			{
				struct Node* newRoot = tree->root->leftChild;
				if (newRoot != NULL)
				{
					newRoot->parent = NULL;
				}
				free(tree->root->value);
				free(tree->root);
				tree->root = newRoot;
			}
		}
		else if (node->leftChild == NULL)
		{
			if (node->parent != NULL)
			{
				if (node->rightChild != NULL)
				{
					node->rightChild->parent = node->parent;
				}
				if (key < node->parent->key)
				{
					node->parent->leftChild = node->rightChild;
				}
				else
				{
					node->parent->rightChild = node->rightChild;
				}
			}
			else
			{
				struct Node* newRoot = NULL;
				newRoot = tree->root->rightChild;
				if (newRoot != NULL)
				{
					newRoot->parent = NULL;
				}
				free(tree->root->value);
				free(tree->root);
				tree->root = newRoot;
			}
		}
	}
	else if (key < node->key)
	{
		deleteNode(tree, node->leftChild, key);
	}
	else
	{
		deleteNode(tree, node->rightChild, key);
	}
}

void deleteRoot(struct Tree* tree)
{
	if (tree->root->rightChild != NULL && tree->root->leftChild != NULL)
	{
		struct Node* helpNode = findTheNearestLesserElement(tree->root);
		char* newValue = calloc(SIZE, sizeof(char));
		strcpy(newValue, helpNode->value);
		tree->root->key = helpNode->key;
		free(tree->root->value);
		tree->root->value = newValue;
		deleteNode(tree, helpNode, helpNode->key);
		return;
	}

	struct Node* newRoot = NULL;
	if (tree->root->rightChild == NULL)
	{
		newRoot = tree->root->leftChild;
	}
	else
	{
		newRoot = tree->root->rightChild;
	}
	if (newRoot != NULL)
	{
		newRoot->parent = NULL;
	}
	free(tree->root->value);
	free(tree->root);
	tree->root = newRoot;
}

void deleteValue(struct Tree* tree, int key)
{
	if (isEmpty(tree))
	{
		return;
	}

	if (tree->root->key == key)
	{
		deleteRoot(tree);
		return;
	}
	deleteNode(tree, tree->root, key);
}

void deleteChildren(struct Node* node)
{
	if (node == NULL)
	{
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);
	free(node->value);
	free(node);
}

void deleteTree(struct Tree* tree)
{
	deleteChildren(tree->root);
	free(tree);
}