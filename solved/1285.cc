#include <iostream>
#include <vector>

using namespace std;

void answer(int N, vector<vector<bool>> S)
{
    int minV = (N * N) + 1;
    vector<vector<bool>> SS;
    for (int mask = 0; mask < (1 << N); mask++)
    {
        SS = S;

        for (int n = 0; n < N; n++)
        {
            if (mask & (1 << n))
            {
                for (int i = 0; i < N; i++)
                {
                    SS[n][i] = !SS[n][i];
                }
            }
        }

        for (int n = 0; n < N; n++)
        {
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                if (SS[i][n]) cnt++;
            }
            if (cnt > N / 2)
            {
                for (int i = 0; i < N; i++)
                {
                    SS[i][n] = !SS[i][n];
                }
            }
        }

        int cnt = 0;
        for (int n = 0; n < N; n++)
        {
            for (int i = 0; i < N; i++)
            {
                if (SS[i][n]) cnt++;
            }
        }

        minV = min(cnt, minV);
    }

    printf("%d\n", minV);
}


int main()
{
    char temp;
    int N;
    vector<vector<bool>> S; 

    scanf("%d\n", &N);

    S = vector(N, vector<bool>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &temp);
            S[i][j] = (temp == 'H' ? true : false);
        }
        scanf("\n");
    }

    answer(N, S);


    return 0;
}