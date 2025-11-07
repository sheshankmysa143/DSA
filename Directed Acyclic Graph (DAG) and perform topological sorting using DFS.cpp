//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX];
    int visited[MAX];
} Graph;

// Stack for topological order
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// Stack operations
void initStack(Stack* s) { s->top = -1; }
int isEmpty(Stack* s) { return s->top == -1; }
void push(Stack* s, int value) { s->items[++(s->top)] = value; }
int pop(Stack* s) { return s->items[(s->top)--]; }

// Create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge to DAG
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS for topological sort
void topologicalSortDFS(Graph* graph, int v, Stack* stack) {
    graph->visited[v] = 1;

    Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex])
            topologicalSortDFS(graph, adjVertex, stack);
        temp = temp->next;
    }

    push(stack, v);  // push after visiting all descendants
}

// Perform topological sort
void topologicalSort(Graph* graph) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i])
            topologicalSortDFS(graph, i, &stack);
    }

    printf("Topological Order: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}

// Main function
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    // Add edges (example DAG)
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}

