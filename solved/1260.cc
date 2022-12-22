// Store Graph Data in Adjacent List. The List have to store nodes in ascending order.
// Then, DFS/BFS the graph

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

typedef struct node {   // Node for Graph Adjacent List
    int vertex;
    node* link;
} node;

class graph {
    private:
        node** adjList;         // AdjList to store graph
        bool* visited;          // Visited to check whether you visited the graph during DFS
        int N;                  // Number of Vertex
        int M;                  // Number of Edge
        void resetVisited();    // Set all visited to False

    public:
        graph(int N, int M);        // Init
        ~graph();                   // Destructor
        void insert(int u, int v);  // Insert Vertex to AdjList
        void DFS(int v);            // Depth First Search Graph
        void BFS(int v);            // Breath First Search Graph
        void print();               // Print AdjList
};

graph::graph(int N, int M) {
    this->N = N;
    this->M = M;

    adjList = new node*[N + 1];
    for (int i = 1; i < N + 1; i++) {
        adjList[i] = NULL;
    }

    visited = new bool[N + 1];
    resetVisited();

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

    if (adjList[u] == NULL || tempv->vertex < adjList[u]->vertex) {
        tempv->link = adjList[u];
        adjList[u] = tempv;
    }
    else {
        for (temp = adjList[u]; temp->link != NULL && !(temp->vertex < tempv->vertex && tempv->vertex < temp->link->vertex); temp = temp->link) {

        }
        tempv->link = temp->link;
        temp->link = tempv;
    }

    if (adjList[v] == NULL || tempu->vertex < adjList[v]->vertex) {
        tempu->link = adjList[v];
        adjList[v] = tempu;
    }
    else {
        for (temp = adjList[v]; temp->link != NULL && !(temp->vertex < tempu->vertex && tempu->vertex < temp->link->vertex); temp = temp->link) {

        }
        tempu->link = temp->link;
        temp->link = tempu;
    }

    return;
};

void graph::DFS(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (node* temp = adjList[v]; temp != NULL; temp = temp->link) {
        if (visited[temp->vertex] == false) {
            DFS(temp->vertex);
        }
    }
};

void graph::BFS(int v) {
    queue<int> q;
    int popped;
    resetVisited();
    
    printf("%d ", v);
    visited[v] = true;
    q.push(v);

    while (q.empty() == false) {
        popped = q.front();
        q.pop();
        for (node* temp = adjList[popped]; temp; temp = temp->link) {
            if (visited[temp->vertex] == false) {
                printf("%d ", temp->vertex);
                q.push(temp->vertex);
                visited[temp->vertex] = true;
            }
        }
    }
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

void graph::resetVisited() {
    memset(visited, 0, N + 1);
}

int main () {
    int N, M, V, u, v;
    scanf("%d %d %d\n", &N, &M, &V);
    graph g(N, M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d\n", &u, &v);
        g.insert(u, v);
    }

    g.DFS(V);
    printf("\n");
    g.BFS(V);

    return 0;
}