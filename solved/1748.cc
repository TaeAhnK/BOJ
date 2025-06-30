#include <iostream>
#include <cmath>

using namespace std;

int GetIntLength(int n)
{
    int cnt = 1;

    while (n / 10 != 0)
    {
        n = n / 10;
        cnt++;
    }

    return cnt;
}

int GetWordLength(int N)
{
    int length = GetIntLength(N);
    int cnt = 0;

    for (int i = 1; i < length; i++)
    {
        cnt += 9 * pow(10, i-1) * i;
    }

    cnt += (N - (pow(10, length - 1)) + 1) * length;

    return cnt;
}

int main()
{
    int N;
    scanf("%d\n", &N);

    printf("%d\n", GetWordLength(N));
    return 0;
}
