#include <iostream>
#include <vector>

const long long MOD = 1000000000;

using namespace std;

void PartitionSumCount(const int N, const int K)
{
    vector<vector<long long>> cache(N+1, vector<long long>(K+1, 0));

    for (int i = 0; i <= N; i++)
    {
        cache[i][1] = 1;
    }

    for (int k = 0; k <= K; k++)
    {        
        cache[0][k] = 1;
    }

    for (int k = 1; k <= K; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            long long sum = 0;

            for (int j = 0; j <= i; j++)
            {
                sum += cache[j][k-1] % MOD;
            }

            cache[i][k] = sum % MOD;
        }
    }

    printf("%lld\n", cache[N][K]);
}

int main()
{
    int N, K;
    scanf("%d %d\n", &N, &K);

    PartitionSumCount(N, K);

    return 0;
}