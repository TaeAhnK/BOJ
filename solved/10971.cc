#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(int N, vector<vector<int>> W)
{
    int minV = 90000001;
    vector<int> S;

    for (int i = 0; i < N; i++)
    {
        S.push_back(i);
    }

    do
    {
        int sum = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (W[S[i]][S[i+1]] == 0)
            {
                sum += 90000001;
            }
            else
            {
                sum += W[S[i]][S[i+1]];
            }
        }

        if (W[S[N-1]][S[0]] == 0)
        {
            sum += 90000001;
        }
        else
        {
            sum += W[S[N-1]][S[0]];
        }

        minV = min(sum, minV);
    } while (next_permutation(S.begin(), S.end()));
    
    printf("%d\n", minV);
}

int main()
{
    int N;
    vector<vector<int>> W;

    scanf("%d\n", &N);

    W = vector(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d ", &W[i][j]);
        }
    }

    answer(N, W);
}