#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1,  1, 2,  2};
const int dy[8] = { 1, -1,  2, -2, 2, -2, 1, -1};

typedef struct XY
{
    int x;
    int y;
    int cnt;
} XY;

class Graph
{
public:
    Graph(int I);
    void MoveCount(int fx, int fy, int tx, int ty);
    void BFS(int cx, int cy, int tx, int ty);
    bool IsValid(XY xy);
    vector<vector<vector<XY>>> adjlist;
    int I;
    bool flag = false;
};

Graph::Graph(int I) : I(I)
{
    adjlist = vector<vector<vector<XY>>>(I, vector<vector<XY>>(I, vector<XY>()));

    for (int x = 0; x < I; x++)
    {
        for (int y = 0; y < I; y++)
        {
            for (int d = 0; d < 8; d++)
            {
                XY t;
                t.x = dx[d] + x;
                t.y = dy[d] + y;
                t.cnt = 0;

                if (IsValid(t))
                {
                    adjlist[x][y].push_back(t);
                }
            }
        }
    }
}

void Graph::MoveCount(int fx, int fy, int tx, int ty)
{
    BFS(fx, fy, tx, ty);
}

void Graph::BFS(int cx, int cy, int tx, int ty)
{
    queue<XY> q;
    vector<vector<bool>> visited(I, vector<bool>(I, false));

    XY start;
    start.x = cx;
    start.y = cy;
    start.cnt = 0; 

    q.push(start);

    visited[start.x][start.y] = true;

    while(!q.empty())
    {
        XY current = q.front();
        q.pop();

        if (current.x == tx && current.y == ty)
        {
            printf("%d\n", current.cnt);
            return;
        }

        for (int i = 0; i < adjlist[current.x][current.y].size(); i++)
        {
            if (!visited[adjlist[current.x][current.y][i].x][adjlist[current.x][current.y][i].y])
            {
                visited[adjlist[current.x][current.y][i].x][adjlist[current.x][current.y][i].y] = true;
                adjlist[current.x][current.y][i].cnt = current.cnt + 1;
                q.push(adjlist[current.x][current.y][i]);
            }
        }
    }
}

bool Graph::IsValid(XY xy)
{
    return (0 <= xy.x) && (xy.x < I) && (0 <= xy.y) && (xy.y < I);
}

int main()
{
    int T, I, fx, fy, tx, ty;

    scanf("%d\n", &T);

    for (int t = 0; t < T; t++)
    {
        scanf("%d\n", &I);
        Graph chess(I);
        scanf("%d %d\n", &fx, &fy);
        scanf("%d %d\n", &tx, &ty);
        chess.MoveCount(fx, fy, tx, ty);
    }

    return 0;
}