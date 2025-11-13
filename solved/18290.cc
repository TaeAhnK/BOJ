#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct XY
{
    int x;
    int y;
} XY;


int N, M, K;
int Max = -50000;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<XY> st;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool isValid(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || M <= xx || yy < 0 || N <= yy) continue;
        if (visited[yy][xx]) return false;
    }

    return true;
}

void DFS(XY xy)
{
    visited[xy.y][xy.x] = true;
    st.push_back(xy);

    if (st.size() < K)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (!visited[n][m] && isValid(m, n))
                {
                    DFS({m, n});
                }
            }
        }
    }
    else
    {
        int sum = 0;
        for (XY i : st) sum += grid[i.y][i.x];
        Max = max(Max, sum);
    }

    visited[xy.y][xy.x] = false;
    st.pop_back();
}

void answer()
{
    visited = vector(N, vector<bool>(M, false));

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            DFS({m, n});
        }
    }

    printf("%d\n", Max);
}


int main()
{
    scanf("%d %d %d\n", &N, &M, &K);

    grid = vector<vector<int>>(N, vector<int>(M));

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%d ", &grid[n][m]);
        }
    }

    answer();

    return 0;
}

