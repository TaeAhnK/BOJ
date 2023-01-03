// BFS the maze and return the depth of BFS when the exit is found

#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1,  0}; // directions for moving one block
int dy[4] = { 0, 1, 0, -1};

typedef struct xy {         // xy for BFS
    int x;                  // x in maze
    int y;                  // y in maze
    int step;               // depth of BFS
} xy;

class maze {
    private:
        int N;              // Row
        int M;              // Col
        bool** field;       // Maze. 0 is blocked, 1 is empty
    public:
        maze(int N, int M); // init
        ~maze();            // destructor
        void readMaze();    // read input and generate maze
        int BFS();          // BFS the maze and find shortest path
        void print();       // print maze for debugging
};

maze::maze(int N, int M) {
    this->N = N;
    this->M = M;
    field = new bool*[N];
    for (int i = 0; i < N; i++) {
        field[i] = new bool[M];
    }

    return;
}

maze::~maze() {
    for (int i = 0; i < N; i++) {
        delete[] field[i];
    }
    delete[] field;

    return;
};

void maze::readMaze() {
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &temp);
            field[i][j] = (bool) (temp - '0');
        }
        scanf("\n");
    }
};

int maze::BFS() {
    queue<xy> q;
    xy popped, temp;

    temp.x = 0;
    temp.y = 0;
    temp.step = 0;
    q.push(temp);

    while(q.empty() == false) {
        popped = q.front();
        if (popped.x == M-1 && popped.y == N-1) {
            return popped.step + 1;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            if ((0 <= popped.x + dx[i]) && (popped.x + dx[i] < M) && (0 <= popped.y + dy[i]) && (popped.y + dy[i] < N) && field[popped.y + dy[i]][popped.x + dx[i]] == true) {
                temp.x = popped.x + dx[i];
                temp.y = popped.y + dy[i];
                temp.step = popped.step + 1;
                field[popped.y + dy[i]][popped.x + dx[i]] = false;
                q.push(temp);
            }
        }

    }
};

void maze::print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", (int) field[i][j]);
        }
        printf("\n");
    }
};

int main () {
    int N, M;
    scanf("%d %d\n", &N, &M);
    maze m(N, M);
    m.readMaze();
    printf("%d\n", m.BFS());
    return 0;
}