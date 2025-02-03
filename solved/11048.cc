// Simple DP
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;

    scanf("%d %d\n", &N, &M);

    vector<vector<int>> maze(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> cache(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d ", &maze[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cache[i][j] = max({cache[i-1][j], cache[i][j-1], cache[i-1][j-1]}) + maze[i][j];
        }
    }

    printf("%d", cache[N][M]);

    return 0; 
}