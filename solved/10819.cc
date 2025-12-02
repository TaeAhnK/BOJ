#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(int N, vector<int> A)
{
    int maxV = -1;
    sort(A.begin(), A.end());

    do
    {
        int sum = 0;
        for (int i = 0 ; i < N - 1; i++)
        {
            sum += abs(A[i] - A[i + 1]);
        }
        maxV = max(sum, maxV);
    } while (next_permutation(A.begin(), A.end()));

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