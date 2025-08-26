#include <iostream>
#include <vector>

using namespace std;

typedef struct curve
{
    int x;
    int y;
    int d;
} curve;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int Turn(int i)
{
    switch(i)
    {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 0;
        default:
            return 0;
    }
}


bool isValid(int x, int y)
{
    return (0 <= x) && (x <= 100) && (0 <= y) && (y <= 100);
}

int answer(int N, vector<vector<int>> dragonCurve)
{
    int ans = 0;
    vector<vector<bool>> grid(101, vector<bool>(101, false));

    // Draw Dragon Curve
    for (int n = 0; n < N; n++)
    {
        vector<int> dc;

        dc.push_back(dragonCurve[n][2]);

        for (int g = 0; g < dragonCurve[n][3]; g++)
        {
            int currentl = dc.size();
            
            for (int i = currentl - 1; 0 <= i; i--)
            {
                dc.push_back(Turn(dc[i]));
            }
        }

        int x = dragonCurve[n][0];
        int y = dragonCurve[n][1];
        grid[y][x] = true;
        for (int i = 0; i < dc.size(); i++)
        {
            x = x + dx[dc[i]];
            y = y + dy[dc[i]];

            if (isValid(x, y))
            {
                grid[y][x] = true;
            }
        }
    }

    // Count Square
    for (int y = 0; y < 100; y++)
    {
        for (int x = 0; x < 100; x++)
        {
            if (grid[y][x] && grid[y+1][x] && grid[y][x+1] && grid[y+1][x+1]) ans++;
        }
    }

    return ans;
}



int main()
{
    int N;
    vector<vector<int>> dragonCurve;

    scanf("%d\n", &N);

    dragonCurve = vector<vector<int>>(N, vector<int>(4));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d ", &dragonCurve[i][j]);
        }
        scanf("\n");
    }

    printf("%d\n", answer(N, dragonCurve));

    return 0;
}