#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int MaxSeqSum(vector<int> A, int n)
{
    vector<int> cache(n, 0);

    cache[0] = A[0];

    for (int i = 1; i < n; i++)
    {
        cache[i] = max(cache[i - 1] + A[i], A[i]);
    }

    return *max_element(cache.begin(), cache.end());
}

int main()
{
    int n;

    scanf("%d\n", &n);

    vector<int> A(n, -2000);

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &A[i]);
    }

    printf("%d\n", MaxSeqSum(A, n));

    return 0;
}