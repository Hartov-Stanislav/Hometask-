#pragma once
#include "List.h"
#include <stdbool.h>

typedef struct Graph Graph;

// Returns head value of i-th list, recieves graph and index
int getTheValue(Graph* graph, int i);

// Returns vertex list by index, recieves graph and index
List* getVertex(Graph* graph, int index);

// Returns head length of i-th list, recieves graph and index
int getTheLength(Graph* graph, int i);

// Returns 'true' if vertex has no neighbours, recieves graph and index
bool isVertexIsolated(Graph* graph, int index);

// Returns number of graph vertices, recieves graph
int getVerticesCount(Graph* graph);

// Reads graph and capitals from file, recieves file
Graph* readGraph(const char* filename, int* k, int* capitals);

// Deletes edge between index and value, recieves graph, number of first city and number of second city and 
void deleteEdge(Graph* graph, int source, int destination);

// Deletes graph, recieves graph
void deleteGraph(Graph** graph);