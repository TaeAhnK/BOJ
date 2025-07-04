#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void LongestIncreasingSeq(vector<int> A, int N)
{
    vector<int> cache(N, 0);
    vector<int> backtrack(N ,-1);
    int maxindex = -1;

    for (int i = 0; i < N; i++)
    {
        cache[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                cache[i] = max(cache[i], cache[j] + 1);
                backtrack[i] = cache[i] > cache[j] + 1 ? backtrack[i] : j; 
            }
        }
        maxindex = cache[maxindex] > cache[i] ? maxindex : i; 
    }

    stack<int> ans;
    int index = maxindex;

    while (index != -1)
    {
        ans.push(index);
        index = backtrack[index];
    }

    printf("%d\n", cache[maxindex]);
    while (!ans.empty())
    {
        printf("%d ", A[ans.top()]);
        ans.pop();
    }
}


int main()
{
    int N;

    scanf("%d\n", &N);

    vector<int> A(N, 0);

    for (int n = 0; n < N; n++)
    {
        scanf("%d ", &A[n]);
    }

    LongestIncreasingSeq(A, N);

    return 0;
}