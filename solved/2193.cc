// simple dp, but careful using int and long
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d\n", &N);

    vector<vector<long>> cache(N + 1, vector<long>(2, 0));

    cache[1][0] = 0;
    cache[1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        cache[i][0] = cache[i-1][0] + cache[i-1][1];
        cache[i][1] = cache[i-1][0];
    }

    printf("%ld\n", cache[N][0] + cache[N][1]);

    return 0;
}