#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(int N, vector<int> S)
{
    bool flag = true;
    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] >= S[i + 1])
        {
            flag = false;
        }
    }

    if (flag)
    {
        printf("-1\n");
        return;
    }

    prev_permutation(S.begin(), S.end());

    for (int i = 0; i < N; i++)
    {
        printf("%d ", S[i]);
    }
    printf("\n");


}

int main()
{
    int N;
    vector<int> S;

    scanf("%d\n", &N);

    S = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &S[i]);
    }

    answer(N, S);

    return 0;
}