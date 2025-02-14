// dp, careful on using int and long long
#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000009;
const int maxN = 100000;


int main()
{
    int T, n;
    scanf("%d\n", &T);

    vector<vector<long long>> cache(4, vector<long long>(maxN + 1, 0));

    cache[1][1] = 1;
    cache[2][2] = 1;
    cache[3][3] = 1;
    cache[1][3] = 1;
    cache[2][3] = 1;

    for (int i = 4; i <= maxN; i++)
    {
        if (i - 1 >= 0)
        {
            cache[1][i] = (cache[2][i - 1] + cache[3][i - 1]) % mod;
        }

        if (i - 2 >= 0)
        {
            cache[2][i] = (cache[1][i - 2] + cache[3][i - 2]) % mod;
        }

        if (i - 3 >= 0)
        {
            cache[3][i] = (cache[1][i - 3] + cache[2][i - 3]) % mod;
        }
    }

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        printf("%ld\n", (cache[1][n] + cache[2][n] + cache[3][n]) % mod);
    }

    return 0;
}