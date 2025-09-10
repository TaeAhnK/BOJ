#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool isValid(int x, int y, int N, int M)
{
    return (0 <= x) && (x < M) && (0 <= y) && (y < N);
}

int ans(int N, int M, vector<vector<int>> grid)
{
    int cnt = 0;

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (grid[n][m] != 0) cnt += 2;

            for (int i = 0; i < 4; i++)
            {
                if (isValid(m+dx[i], n+dy[i], N, M))
                {
                    cnt += max(grid[n][m] - grid[n+dy[i]][m+dx[i]], 0);
                }
                else
                {
                    cnt += grid[n][m];
                }
            }
        }
    }

    return cnt;
}


int main()
{
    int N, M;
    vector<vector<int>> grid;
    scanf("%d %d\n", &N, &M);

    grid = vector<vector<int>>(N, vector<int>(M));

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%d ", &grid[n][m]);
        }
        scanf("\n");
    }

    printf("%d\n", ans(N, M, grid));

    return 0;
}