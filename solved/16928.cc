// Draw the map as a graph. Snakes and ladder to weight 0, dices to weight 1.
// Then, use Dijkstra Algorithm to find shortest path
#include <iostream>

using namespace std;

const int INF = 1000;       // Max value of the shortest path is 100 (< 1,000)

class dijkstra {
    private:
        int* dist;          // Distance From 1
        bool* visited;      // Visited Vertex
        int** map;          // Adjcent Matrix of the Graph
        int endNum;         // Target Index
        int choose();       // Choose Node to Update (Unvisited Closest Node)
    protected:
    public:
        dijkstra(int endNum);                   // Init
        ~dijkstra();                            // ~Destructor
        void print();                           // Print for Debugging
        void connect(int a, int b, int weight); // Set a Connection 
        int solve(int start, int end);          // Find Shortest Path
};

class SnakeNLadders : protected dijkstra {      // Read Snake&Ladders Map and convert into graph, use Dijkstra
    private:
        bool* snakeladder;                      // Whether the block has a ladder or a snake
    public:
        SnakeNLadders(int ladder, int snake);   // Init
        ~SnakeNLadders();                       // Destructor
        void read();                            // read graph data input
        int shortestPath();                     // use Dijkstra and find the shortest path to 100
};

dijkstra::dijkstra(int endNum) {
    this->endNum = endNum;
    dist = new int [endNum + 1];
    visited = new bool [endNum + 1];
    map = new int* [endNum + 1];

    for (int i = 0; i < endNum + 1; i++) {
        map[i] = new int [endNum + 1];
        visited[i] = false;
        dist[i] = INF;
        for (int j = 0; j < endNum + 1; j++) {
            map[i][j] = INF;
        }
        map[i][i] = 0;
    }

    return;
};

dijkstra::~dijkstra() {
    delete[] dist;
    delete[] visited;
    for (int i = 0; i < endNum + 1; i++) {
        delete[] map[i];
    }
    delete[] map;
};

void dijkstra::connect(int a, int b, int weight) {
    if (map[a][b] > weight) {
        map[a][b] = weight;
    }

    return;
};

int dijkstra::solve(int start, int end) {
    for (int i = 1; i <= endNum; i++) {
        dist[i] = map[start][i];
    }
    visited[start] = true;
    for (int i = 1; i <= endNum - 2; i++) {
        int u = choose();
        visited[u] = true;
        for (int w = 1; w <= endNum; w++) {
            if(!visited[w]) {
                if (dist[u] + map[u][w] < dist[w]) {
                    dist[w] = dist[u] + map[u][w];
                }
            }
        }
    }

    return dist[end];
};

int dijkstra::choose() {
    int min, minpos;
    min = INF;
    minpos = 1;
    for (int i = 1; i <= endNum; i++) {
        if (dist[i] < min && !visited[i]) {
            min = dist[i];
            minpos = i;
        }
    }

    return minpos;
};

void dijkstra::print() {
    for (int i = 1; i <= endNum; i++) {
        for (int j = 1; j <= endNum; j++){
            printf("%d\t", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <=endNum; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return;
};

SnakeNLadders::SnakeNLadders(int ladder, int snake) : dijkstra(100) {
    int u, v;
    snakeladder = new bool [100 + 1]{};

    for (int i = 0; i < ladder + snake; i++) {
        scanf("%d %d\n", &u, &v);
        connect(u, v, 0);
        snakeladder[u] = true;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 6; j++) {
            if (!snakeladder[i] && i + j <= 100) {
                connect(i, i+j, 1);
            }
        }
    }

    return;
};

SnakeNLadders::~SnakeNLadders() {
    delete[] snakeladder;

    return;
};

int SnakeNLadders::shortestPath() {
    return solve(1, 100);
};

int main () {
    int N, M;
    scanf("%d %d\n", &N, &M);

    SnakeNLadders S(N, M);
    printf("%d\n", S.shortestPath());

    return 0;
}