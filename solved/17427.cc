#include <iostream>

using namespace std;

int main()
{
    int N;
    long long int sum = 0;

    scanf("%d", &N);

    for (int n = 1; n <= N; n++)
    {
        sum += (N / n) * n;
    }

    printf("%lld", sum);

    return 0;
}