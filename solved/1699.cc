#include <iostream>
#include <vector>

using namespace std;

void SquareTermNum(int N)
{
    vector<int> cache(N + 1, 9999999);
    cache[0] = 0;

    for (int i = 0; i <= N; i++)
    {
        cache[i] = i;
    }

    for (int i = 2; i * i <= N; i++)
    {
        cache[i * i] = 1;
        for (int j = i * i; j <= N; j++)
        {
            cache[j] = min(j / (i * i) + cache[j % (i * i)], cache[j]);
        }
    }
    
    printf("%d", cache[N]);
}


int main()
{
    int N;
    scanf("%d", &N);

    SquareTermNum(N);
    
    return 0;
}