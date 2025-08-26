#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int Turn(int d)
{
    switch (d)
    {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return 0;
    }
}

int ans(int N, int M, int r, int c, int d, vector<vector<int>> grid)
{
    int answer = 0;
    int x = c;
    int y = r;
    int dd = d;

    while (true)
    {
        if (grid[y][x] == 0) 
        {
            grid[y][x] = 2; 
            answer++;
        }

        bool zerofound = false;
        
        for (int i = 0; i < 4; i++)
        {
            if (grid[y+dy[i]][x+dx[i]] == 0)
            {
                zerofound = true;
                break;
            }
        }

        if (zerofound)
        {
            dd = Turn(dd);

            if (grid[y+dy[dd]][x+dx[dd]] == 0)
            {
                x = x+dx[dd];
                y = y+dy[dd];
            }
        }
        else
        {
            if (grid[y-dy[dd]][x-dx[dd]] != 1)
            {
                x = x-dx[dd];
                y = y-dy[dd];
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}


int main()
{
    int N, M, r, c, d;
    vector<vector<int>> grid;

    scanf("%d %d\n%d %d %d\n", &N, &M, &r, &c, &d);

    grid = vector<vector<int>>(N, vector<int>(M));

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%d ", &grid[n][m]);
        }
        scanf("\n");
    }

    printf("%d\n", ans(N, M, r, c, d, grid));

    return 0;
}