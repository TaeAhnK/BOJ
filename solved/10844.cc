// dp, careful using long long
#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000000;

int main()
{
    int N;
    scanf("%d\n", &N);

    vector<vector<long long>> cache(10, vector<long long>(N + 1, 0));

    cache[0][1] = 0;
    cache[1][1] = 1;
    cache[2][1] = 1;
    cache[3][1] = 1;
    cache[4][1] = 1;
    cache[5][1] = 1;
    cache[6][1] = 1;
    cache[7][1] = 1;
    cache[8][1] = 1;
    cache[9][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        cache[0][i] = (cache[1][i - 1]) % mod;
        cache[1][i] = (cache[0][i - 1] + cache[2][i - 1]) % mod;
        cache[2][i] = (cache[1][i - 1] + cache[3][i - 1]) % mod;
        cache[3][i] = (cache[2][i - 1] + cache[4][i - 1]) % mod;
        cache[4][i] = (cache[3][i - 1] + cache[5][i - 1]) % mod;
        cache[5][i] = (cache[4][i - 1] + cache[6][i - 1]) % mod;
        cache[6][i] = (cache[5][i - 1] + cache[7][i - 1]) % mod;
        cache[7][i] = (cache[6][i - 1] + cache[8][i - 1]) % mod;
        cache[8][i] = (cache[7][i - 1] + cache[9][i - 1]) % mod;
        cache[9][i] = (cache[8][i - 1]) % mod;
    }

    printf("%lld\n", (cache[0][N] + cache[1][N] + cache[2][N] + cache[3][N] + cache[4][N] 
        + cache[5][N] + cache[6][N] + cache[7][N] + cache[8][N] + cache[9][N]) % mod);

    return 0;
}