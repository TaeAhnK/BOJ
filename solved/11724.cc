// Create an array that stores infomation whether you visited the node or not
// DFS all unvisited node according to the array
// Check visited during DFS.
// When DFSing nodes according to the array, count the unvisited, 
// which we haven't visited since they are the ones which are not connected and are different graph

#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

typedef struct node {   // Node for Graph Adjacent List
    int vertex;
    node* link;
} node;

class graph {
    private:
        node** adjList; // AdjList to store graph
        bool* visited;  // Visited to check whether you visited the graph during DFS
        int N;          // Number of Vertex
        int M;          // Number of Edge
    public:
        graph(int N, int M);        // Init
        ~graph();                   // Destructor
        void insert(int u, int v);  // Insert Vertex to AdjList
        void DFS(int v);            // Depth First Search Graph
        bool isVisited(int i);      // Return whether you visited the vertex or not
        void print();               // Print AdjList
};

graph::graph(int N, int M) {
    this->N = N;
    this->M = M;

    adjList = new node*[N + 1];
    for (int i = 1; i < N + 1; i++) {
        node* temp = new node;
        temp->vertex = i;
        temp->link = NULL;
        adjList[i] = temp;
    }

    visited = new bool[N + 1];
    memset(visited, 0, N + 1);

    return;
};

graph::~graph() {;
    for (int i = 0; i < N + 1; i++) {
        node* target = adjList[i];
        node* temp = target;
        while (target != NULL) {
            temp = temp->link;
            free(target);
            target = temp;
        }
    }
    delete[] adjList;
    delete[] visited;
    return;
};

void graph::insert(int u, int v) {
    node* temp;
    node* tempu = new node;
    node* tempv = new node;

    tempu->vertex = u;
    tempv->vertex = v;

    tempv->link = adjList[u]->link;
    adjList[u]->link = tempv;

    tempu->link = adjList[v]->link;
    adjList[v]->link = tempu;

    return;
};

void graph::DFS(int v) {
    visited[v] = true;
    for (node* temp = adjList[v]; temp != NULL; temp = temp->link) {
        if (visited[temp->vertex] == false) {
            DFS(temp->vertex);
        }
    }
};

bool graph::isVisited(int i) {
    return visited[i];
};

void graph::print() {
    node* temp;
    for (int i = 1; i < N + 1; i++) {
        temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->link;
        }
        printf("\n");
    }
};

int main() {
    int M, N, u, v, CCom;

    CCom = 0;
    scanf("%d %d\n", &N, &M);
    graph G(N, M);
    for (int i = 0 ; i < M; i++) {
        scanf("%d %d\n", &u, &v);
        G.insert(u, v);
    }

    for (int i = 1; i < N+1; i++) {
        if (G.isVisited(i) == false) {
            G.DFS(i);
            CCom++;
        }
    }
    printf("%d\n", CCom);

    return 0;
}