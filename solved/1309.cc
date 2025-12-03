#include <iostream>
#include <vector>

using namespace std;

void answer(int N)
{
    vector<vector<int>> cache (3, vector<int>(N+1, 0));

    // 0 -> 00 / 1 -> 01 / 2 -> 10
    cache[0][1] = 1;
    cache[1][1] = 1;
    cache[2][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        cache[0][i] = (cache[0][i-1] + cache[1][i-1] + cache[2][i-1]) % 9901;
        cache[1][i] = (cache[0][i-1] + cache[2][i-1]) % 9901;
        cache[2][i] = (cache[0][i-1] + cache[1][i-1]) % 9901;
    }

    printf("%d\n", (cache[0][N] + cache[1][N] + cache[2][N]) % 9901);
}

int main()
{
    int N;

    scanf("%d\n", &N);

    answer(N);

    return 0;
}