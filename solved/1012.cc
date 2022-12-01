// Create field using 2D Array. 0 as empty field, -1 as cabbage.
// For every -1, check up/down/right/left field for cabbage. If there is one, check again recursively.  
// On checking, change cabbage into count number. Everytime you encounter new cabbage group, +1 count.

#include <iostream>

using namespace std;

class Field {
    private:
        int** f;    // Cabbage Field
        int row;    // row M
        int col;    // col N
        int cabNum; // Number of Cabbages

    public:
        Field(int M, int N, int K); // Init
        ~Field();                   // Destuctor
        void plant(int x, int y);   // Check Cabbage on Field as -1
        void checkConnected();      // Count Connected Cabbages
        void check(int x, int y, int count);    // Recursive Connection Checker
        void printField();          // Print Field for Debugging

};

const int dx[8] = {-1, 1,  0, 0};   // Relational (x, y) for checking adjacent cabbage
const int dy[8] = { 0, 0, -1, 1};

Field::Field(int M, int N, int K) {
    f = new int*[M];
    for (int i = 0; i < M; i++) {
        f[i] = new int[N];
    }
    row = M;
    col = N;
    cabNum = K;

    return;
};

Field::~Field() {
    for (int i = 0; i < row; i++) {
        delete[] f[i];
    }
    delete[] f;

    return;
};

void Field::plant(int x, int y) {
    f[x][y] = -1;
    return;
};

void Field::checkConnected() {
    int count = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (f[j][i] == -1) {
                check(j, i, ++count);
            }
        }
    }
    printf("%d\n", count);

    return;
};

void Field::check(int x, int y, int count) {
    if (x < 0 || row <= x || y < 0 || col <= y) {
        return;
    }
    if (f[x][y] == -1) {
        f[x][y] = count;
        for (int dir = 0; dir < 4; dir++) {
            check(x + dx[dir], y + dy[dir], count);
        }
    }

    return;
};

void Field::printField() {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d\t", f[j][i]);
        }
        printf("\n");
    }
    printf("\n\n");

    return;
}

int main() {
    int T, M, N, K, x, y;

    scanf("%d\n", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d %d\n", &M, &N, &K);
        Field ff(M, N, K);
        for (int i = 0; i < K; i++) {
            scanf("%d %d\n", &x, &y);
            ff.plant(x, y);
        }
        ff.checkConnected();
    }

    return 0;
}