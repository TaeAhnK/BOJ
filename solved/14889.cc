#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer(int N, vector<vector<int>> S)
{
    int MIN = 10000000;
    vector<bool> mask(N, false);
    fill(mask.end() - (N/2), mask.end(), true);

    do 
    {
        int teamTrue = 0;
        int teamFalse = 0;

        for (int i = 0; i < N; i++)
        {
            if (mask[i])
            {
                for (int j = 0; j < N; j++)
                {
                    if (mask[j]) teamTrue += S[i][j];
                }
            }
            else
            {
                for (int j = 0; j < N; j++)
                {
                    if (!mask[j]) teamFalse += S[i][j];
                }
            }
        }

        MIN = min(abs(teamTrue - teamFalse), MIN);

    } while (next_permutation(mask.begin(), mask.end()));

    return MIN;
}


int main()
{
    int N;
    vector<vector<int>> S;

    scanf("%d\n", &N);
    S = vector(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d ", &S[i][j]);
        }
        scanf("\n");
    }

    printf("%d\n", answer(N, S));

    return 0;
}