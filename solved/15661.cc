#include <iostream>
#include <vector>

using namespace std;

int answer(int N, vector<vector<int>> S)
{
    int minV = 1000000;

    for (int mask = 1; mask < (1 << N) - 1; mask++)
    {
        int team0 = 0;
        int team1 = 0;

        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                for (int j = 0; j < N; j++)
                {
                    if (mask & (1 << j)) team1 += S[i][j];
                }
            }
            else
            {
                for (int j = 0; j < N; j++)
                {
                    if (!(mask & (1 << j))) team0 += S[i][j];
                }
            }
            
        }

        minV = min(minV, abs(team0 - team1));
    }

    return minV;
}



int main()
{
    int N;
    vector<vector<int>> S;

    scanf("%d\n", &N);

    S = vector(N, vector<int>(N));

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