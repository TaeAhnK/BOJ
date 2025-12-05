#include <iostream>
#include <vector>

using namespace std;

void answer(int N, vector<int> A)
{
    int maxV = 0;
    vector<vector<int>> cache(2, vector<int>(N, 0));

    cache[0][0] = 1;
    cache[1][N-1] = 1;
    for (int i = 1; i < N; i++)
    {
        cache[0][i] = 1;
        for (int j = i - 1; 0 <= j; j--)
        {
            if (A[j] < A[i])
            {
                cache[0][i] = max(cache[0][i], cache[0][j] + 1);
            }
        }
    }

    for (int i = N - 1; 0 <= i; i--)
    {
        cache[1][i] = 1;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[i])
            {
                cache[1][i] = max(cache[1][i], cache[1][j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        maxV = max(maxV, cache[0][i] + cache[1][i] - 1);
    }

    printf("%d\n", maxV);

}

int main()
{
    int N;
    vector<int> A;

    scanf("%d\n", &N);

    A = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &A[i]);
    }

    answer(N, A);

    return 0;
}