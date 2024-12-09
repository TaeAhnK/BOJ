// cache[i] = min(P[i], cache[i], cache[i-j]+P[i])
#include <iostream>
#include <vector>

#define INF 10001

int main()
{
    int N;
    std::vector<int> P;
    std::vector<int> cache;

    scanf("%d\n", &N);

    cache = std::vector<int>(N+1, INF);

    P.push_back(INF);
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
            cache[i] = std::min(P[i], std::min(cache[i], cache[i - j] + P[j]));
        }
    }
    
    printf("%d\n", cache[N]);

    return 0;
}