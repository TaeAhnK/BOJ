// DP[i] = DP[i], DP[i-j] + P[j]

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<int> P;
    std::vector<int> cache;

    scanf("%d\n", &N);

    cache = std::vector<int>(N+1, 0);

    P.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d ", &temp);
        P.push_back(temp);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cache[i] = std::max(cache[i], cache[i - j] + P[j]);
        }
    }

    printf("%d\n", cache[N]);

    return 0;
}