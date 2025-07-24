#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,1,-1,0};

typedef struct XY
{
    int x;
    int y;
} XY;

class Graph
{
public:
    Graph(int N, int M);
    void BFS();
    bool IsValid(int x, int y);
    vector<vector<int>> data;
    int N, M;
};

Graph::Graph(int N, int M) : N(N), M(M)
{
    data = vector<vector<int>>(N+1, vector<int>(M+1));

    for (int m = 1; m <= M; m++)
    {
        for (int n = 1; n <= N; n++)
        {
            char temp;
            scanf("%c", &temp);
            data[n][m] = temp - '0';
        }
        scanf("\n");
    }

    // for (int m = 1; m <= M; m++)
    // {
    //     for (int n = 1; n <= N; n++)
    //     {
    //         printf("%d", data[n][m]);
    //     }
    //     printf("\n");
    // }
}

void Graph::BFS()
{
    queue<XY> q;
    vector<vector<int>> visited(N + 1, vector<int>(M + 1, 9999999));

    q.push({1, 1});
    visited[1][1] = 0;

    while (!q.empty())
    {
        XY current = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int x = current.x + dx[d];
            int y = current.y + dy[d];
            if (IsValid(x, y))
            {
                if (visited[y][x] > visited[current.y][current.x] + data[y][x])
                {
                    visited[y][x] = visited[current.y][current.x] + data[y][x];
                    q.push({x, y});
                }
            }
        }
    }

    // for (int m = 1; m <= M; m++)
    // {
    //     for (int n = 1; n <= N; n++)
    //     {
    //         printf("%d", visited[n][m]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", visited[N][M]);
}

bool Graph::IsValid(int x, int y)
{
    return (0 < x && x <= M && 0 < y && y <= N);
}

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);

    Graph maze(N, M);
    maze.BFS();
    return 0;
}