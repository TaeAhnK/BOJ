#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int T;
    scanf("%d\n", &T);

    vector<long long> cache(1000001, 0);

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for (int i = 4; i < 1000001; i++)
    {
        cache[i] = (cache[i-1] + cache[i-2] + cache[i-3]) % 1000000009;
    }

    for (int i = 0; i < T; i++)
    {
        int temp;
        scanf("%d\n", &temp);
        printf("%lld\n", cache[temp]);
    }
}