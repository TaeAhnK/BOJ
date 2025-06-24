#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, N;
    vector<long long int> cache(1000001, 0);

    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = 1; j * i <= 1000000; j++)
        {
            cache[i*j] += i;
        }
    }

    for (int i = 1; i <= 1000000; i++)
    {
        cache[i] = cache[i-1] + cache[i];
    }

    scanf("%d\n", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d\n", &N);
        printf("%lld\n", cache[N]);
    }

}