#include "Graph.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

bool isCapital(const int Capitals[], const int index, const int countCapitals)
{
	for (int i = 0; i < countCapitals; i++)
	{
		if (Capitals[i] == index)
		{
			return true;
		}
	}
	return false;
}

void mergeLists(List* destination, List* source, int destinationIndex, int sourceIndex)
{
	removeValue(destination, sourceIndex);
	addItem(destination, sourceIndex, INT_MAX);
	removeValue(source, destinationIndex);
	Position current = getFirst(source);
	while (!isEmpty(source))
	{
		int value = getValue(current);
		int length = getLength(current);
		int destinationLength = findValue(destination, value);
		if (destinationLength == -INT_MAX)
		{
			addItem(destination, value, length);
		}
		else if (destinationLength > length && destinationLength != INT_MAX)
		{
			removeValue(destination, value);
			addItem(destination, value, length);
		}
		removeValue(source, value);
		current = getFirst(source);
	}
}

void mergeNodes(Graph* graph, int destination, int source)
{
	if (graph == NULL)
	{
		return;
	}
	mergeLists(getVertex(graph, destination), getVertex(graph, source), destination, source);
}

void printAnswer(Graph* graph, int Capitals[], int countCapitals)
{
	for (int i = 0; i < countCapitals; i++)
	{
		printf("Capital: %i\nCities: ", Capitals[i] + 1);
		int current = getTheValue(graph, Capitals[i]);
		int currentLength = getTheLength(graph, Capitals[i]);
		while (currentLength != -INT_MAX)
		{
			if (currentLength == INT_MAX)
			{
				printf("%i ", current + 1);
			}
			deleteEdge(graph, Capitals[i], current);
			current = getTheValue(graph, Capitals[i]);
			currentLength = getTheLength(graph, Capitals[i]);
		}
		printf("\n");
	}
}

Graph* makeCountries(char* filename, int* countCapitals, int Capitals[])
{
	Graph* graph = readGraph(filename, countCapitals, Capitals);
	if ((*countCapitals) == 0)
	{
		return graph;
	}
	int vertices = getVerticesCount(graph);
	int index = 0;
	int currentCapital = Capitals[index];
	while (vertices > (*countCapitals))
	{
		int minIndex = getTheValue(graph, currentCapital);
		while (minIndex != INT_MAX && (isCapital(Capitals, minIndex, (*countCapitals)) || isVertexIsolated(graph, minIndex)))
		{
			deleteEdge(graph, currentCapital, minIndex);
			minIndex = getTheValue(graph, currentCapital);
		}
		if (minIndex != INT_MAX)
		{
			mergeNodes(graph, currentCapital, minIndex);
			vertices--;
		}
		index = (index + 1) % (*countCapitals);
		currentCapital = Capitals[index];
	}
	return graph;
}

bool test()
{
	FILE* answers = fopen("answer.txt", "r");
	if (answers == NULL)
	{
		return false;
	}
	int countCapitals = 0;
	int Capitals[1000] = { 0 };
	Graph* graph = makeCountries("test.txt", &countCapitals, Capitals);
	bool result = true;
	for (int i = 0; i < countCapitals; i++)
	{
		int current = getTheValue(graph, Capitals[i]);
		int currentLength = getTheLength(graph, Capitals[i]);
		int answer = 0;
		while (currentLength != -INT_MAX)
		{
			if (currentLength == INT_MAX)
			{
				fscanf(answers, "%i", &answer);
				result &= (answer == current + 1);
			}
			deleteEdge(graph, Capitals[i], current);
			current = getTheValue(graph, Capitals[i]);
			currentLength = getTheLength(graph, Capitals[i]);
		}
	}
	fclose(answers);
	deleteGraph(&graph);
	return result;
}

int main()
{
	if (!test())
	{
		printf("Tests failed");
		return 1;
	}
	int k = 0;
	int Capitals[1000] = { 0 };
	Graph* graph = makeCountries("input.txt", &k, Capitals);
	printAnswer(graph, Capitals, k);
	deleteGraph(&graph);
	return 0;
}