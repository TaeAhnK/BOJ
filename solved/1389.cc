// Use Floyd-Warshall Algorithm to calculate min-distance between people.
// Add the distances and print the person with smallest Kevin Bacon Number

#define INF 10000;      // Set Infinity to 10000. Max value(5,000) is less than 10,000 

#include <iostream>
#include <algorithm>

using namespace std;

class KevinBacon {
    private:
        int **table;                // Table for Floyd-Warshall
        int peopleNum;              // The Number of People
        int relationNum;            // The Number of Relations between People
        void FloydWarshall();       // Floy-Wharshall
    public:
        KevinBacon(int peopleNum);  // Init
        ~KevinBacon();              // Destructor
        void read(int relationNum); // Read Relation Data
        int minKevin();             // Calculate min-Kevin Bacon Numbered Person
        void print();               // Print table for Debugging
};

KevinBacon::KevinBacon(int peopleNum) {
    this->peopleNum = peopleNum;
    table = new int* [peopleNum + 1];
    for (int i = 0; i < peopleNum + 1; i++){
        table[i] = new int[peopleNum + 1];
        for (int j = 0; j < peopleNum + 1; j++) {
            if (i == j) {
                table[i][j] = 0;
            }
            else {
                table[i][j] = INF;
            }
        }
    }

    return;
};

KevinBacon::~KevinBacon() {
    for (int i = 0; i < peopleNum + 1; i++) {
        delete[] table[i];
    }
    delete[] table;

    return;
};

void KevinBacon::FloydWarshall() {
    for (int i = 1; i < peopleNum + 1; i++) {
        for (int j = 1; j < peopleNum + 1; j++) {
            for (int k = 1; k < peopleNum + 1; k++) {
                table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
            }
        }
    }

    return;
};

void KevinBacon::read(int relationNum) {
    int a, b;
    this->relationNum = relationNum;
    for (int i = 0; i < relationNum; i++) {
        scanf("%d %d\n", &a, &b);
        table[a][b] = 1;
        table[b][a] = 1;
    }

    return;
};

int KevinBacon::minKevin() {
    int cur, min, minP;
    min = INF;
    FloydWarshall();
    for (int i = 1; i < peopleNum + 1; i++) {
        cur = 0;
        for (int j = 1; j <peopleNum + 1; j++) {
            cur += table[i][j];
        }
        if (cur < min) {
            minP = i;
            min = cur;
        }
    }
    return minP;
}

void KevinBacon::print() {
    printf("\t");
    for (int i = 1; i < peopleNum + 1; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 1; i < peopleNum + 1; i++) {
        printf("%d\t", i);
        for (int j = 1; j < peopleNum + 1; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    return;
};

int main () {
    int N, M;
    scanf("%d %d\n", &N, &M);

    KevinBacon K(N);
    K.read(M);
    printf("%d\n", K.minKevin());
    
    return 0;
}