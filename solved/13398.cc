#include <iostream>
#include <vector>

using namespace std;

void answer(int n, vector<int> S)
{
    int maxV = S[0]; 
    vector<vector<int>> cache(2, vector<int>(n + 1, 0));

    cache[0][0] = S[0];
    cache[1][n-1] = S[n-1];

    if (n == 1)
    {
        printf("%d", S[0]);
        return;
    }

    if (n == 2)
    {
        printf("%d ", max(S[0], max(S[1], S[0] + S[1])));
        return;
    }

    for (int i = 1; i < n; i++)
    {
        cache[0][i] = max(cache[0][i-1] + S[i], S[i]);
    }

    for (int i = n - 2; 0 <= i; i--)
    {
        cache[1][i] = max(cache[1][i+1] + S[i], S[i]);
    }
    
    for (int i = 1; i < n - 1; i++)
    {
        maxV = max(maxV, cache[0][i-1] + cache[1][i+1]);
        maxV = max(maxV, cache[0][i] + cache[1][i] - S[i]);
    }
    maxV = max(maxV, S[n-1]);

    printf("%d\n", maxV);
}

int main()
{
    int n;
    vector<int> S;

    scanf("%d\n", &n);

    S = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &S[i]);
    }

    answer(n, S);

    return 0;
}
