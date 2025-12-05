#include <iostream>
#include <vector>

using namespace std;

void answer(int N, vector<int> A)
{
    int maxV = 0;
    vector<int> cache(N, 0);

    cache[0] = A[0];

    for (int i = 1; i < N; i++)
    {
        cache[i] = A[i];
        for (int j = i - 1; 0 <= j; j--)
        {
            if (A[j] < A[i])
            {
                cache[i] = max(cache[i], cache[j] + A[i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        maxV = max(maxV, cache[i]);
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