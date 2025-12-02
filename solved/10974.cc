#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(int N)
{
    vector<int> S;

    for (int i = 1; i <= N; i++)
    {
        S.push_back(i);
    }

    do 
    {
        for (int i = 0; i < N; i++)
        {
            printf("%d ", S[i]);
        }
        printf("\n");
    } while (next_permutation(S.begin(), S.end()));
}

int main()
{
    int N;

    scanf("%d\n", &N);

    answer(N);

    return 0;
}