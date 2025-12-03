#include <iostream>
#include <vector>

using namespace std;

void answer(int N)
{
    int ans = 0;
    vector<vector<int>> cache(10, vector<int>(N + 1, 0));

    for (int i = 0; i < 10; i++)
    {
        cache[i][1] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                cache[j][i] += (cache[k][i-1]) % 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        ans += (cache[i][N]) % 10007;
    }

    printf("%d\n", ans % 10007);
}

int main()
{
    int N;

    scanf("%d\n", &N);

    answer(N);

    return 0;
}