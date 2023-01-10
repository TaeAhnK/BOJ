// Read the graph and find the root for every vertex using FLoyd-Wharshall

const int INF = 10000;      // Set Infinity to 10000. Max value(100) is less than 10,000 

#include <iostream>
#include <algorithm>

using namespace std;

class graph {
    private:
        int vertexNum;              // The number of the Vertex in Graph
        int **table;                // Graph in Table Form
        void FloydWarshall();       // Floyd-Wharshall Algorithm
        bool isConnected(int a);    // Return true when input is not INF (not connected)
    public:
        graph(int vertexNum);       // Init
        ~graph();                   // Destructor
        void read();                // Read the graph
        void printConnected();      // Check connections with FloydWarshall, and print connected as 1, not connected as 0
        void print();               // Print for debugging
};

graph::graph(int vertexNum) {
    this->vertexNum = vertexNum;
    table = new int* [vertexNum];
    for (int i = 0; i < vertexNum; i++){
        table[i] = new int[vertexNum];
        for (int j = 0; j < vertexNum; j++) {
            if (i == j) {
                table[i][j] = 0;
            }
            else {
                table[i][j] = INF;
            }
        }
    }
    return;
}

graph::~graph() {
    for (int i = 0; i < vertexNum; i++) {
        delete[] table[i];
    }
    delete[] table;

    return;
}

void graph::FloydWarshall() {
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            for (int k = 0; k < vertexNum; k++) {
                table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
            }
        }
    }

    return;
};

bool graph::isConnected(int a) {
    if (a == INF) {
        return 0;
    }
    else {
        return 1;
    }
};

void graph::read() {
    int temp;
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            scanf("%d ", &temp);
            if (temp == 0) {
                table[i][j] = INF;
            }
            else {
                table[i][j] = 1;    
            }
        }
    }

    return;
};

void graph::printConnected() {
    FloydWarshall();
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            printf("%d ", isConnected(table[i][j]));
        }
        printf("\n");
    }
};

void graph::print() {
    printf("\t");
    for (int i = 0; i < vertexNum; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < vertexNum; i++) {
        printf("%d\t", i);
        for (int j = 0; j < vertexNum; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    return;
};

int main () {
    int N;
    scanf("%d\n", &N);

    graph G(N);
    G.read();
    G.printConnected();
    return 0;
}