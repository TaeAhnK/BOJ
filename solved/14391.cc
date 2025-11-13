#include <iostream>
#include <vector>

using namespace std;

int index(int x, int y, int M)
{
    return (y * M) + x;
}

int answer(int N, int M, vector<vector<int>> grid)
{
    int maxv = 0;
    int NM = N * M;

    for (int mask = 0; mask < (1<<NM); mask++)
    {
        vector<vector<bool>> used(N, vector<bool>(M, false));
        int sum = 0;
        for (int n = 0; n < N; n++)
        {
            for (int m = M - 1 ; 0 <= m; m--)
            {
                if (!used[n][m] && (mask & (1<<index(m, n, M))))
                {
                    for (int x = m, i = 1; 0 <= x; x--, i *= 10)
                    {
                        if (!used[n][x] && (mask & (1<<index(x, n, M))))
                        {
                            used[n][x] = true;
                            sum += grid[n][x] * i;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        for (int n = N - 1; 0 < n; n--)
        {
            for (int m = 0; m < M; m++)
            {
                if (!used[n][m])
                {
                    for (int y = n, i = 1; 0 <= y; y--, i *= 10)
                    {
                        if (!used[y][m])
                        {
                            used[y][m] = true;
                            sum += grid[y][m] * i;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        maxv = max(maxv, sum);
    }
    return maxv;
}


int main()
{
    char temp;
    int N, M;
    vector<vector<int>> grid;

    scanf("%d %d\n", &N, &M);

    grid = vector(N, vector<int>(M));

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%c ", &temp);
            grid[n][m] = temp - '0';
        }
    }

    printf("%d\n", answer(N, M, grid));

    return 0;
}