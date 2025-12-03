#include <iostream>
#include <vector>

using namespace std;

void answer(int n, vector<int> S)
{
    int ans = -1;
    vector<vector<int>> cache(8, vector<int>(n + 1, 0));

    cache[1][1] = S[1];
    cache[1][2] = S[1];
    cache[2][2] = S[2];
    cache[3][2] = S[1] + S[2];

    cache[0][3] = 0;                    // 000
    cache[1][3] = S[3];                 // 001
    cache[2][3] = S[2];                 // 010
    cache[3][3] = S[2] + S[3];          // 011
    cache[4][3] = S[1];                 // 100
    cache[5][3] = S[1] + S[3];          // 101
    cache[6][3] = S[1] + S[2];          // 110
    cache[7][3] = S[1] + S[2] + S[3];   // 111

    for (int i = 4; i <= n; i++)
    {
        cache[0][i] = max(cache[0][i-1], cache[4][i-1]);        // 00
        cache[1][i] = max(cache[0][i-1], cache[4][i-1]) + S[i]; // 00
        cache[2][i] = max(cache[1][i-1], cache[5][i-1]);        // 01
        cache[3][i] = max(cache[1][i-1], cache[5][i-1]) + S[i]; // 01
        cache[4][i] = max(cache[2][i-1], cache[6][i-1]);        // 10
        cache[5][i] = max(cache[2][i-1], cache[6][i-1]) + S[i]; // 10
        cache[6][i] = cache[3][i-1];                        // 11
    }

    for (int i = 0; i < 7; i++)
    {
        ans = max(ans, cache[i][n]);
    }

    printf("%d\n", ans);
}

int main()
{
    int n;
    vector<int> S;

    scanf("%d\n", &n);
    S = vector<int>(n + 1);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d\n", &S[i]);
    }

    answer(n, S);

    return 0;
}