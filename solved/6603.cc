#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(int N, vector<int> S)
{
    vector<bool> A (N, false);
    fill(A.begin(), A.begin() + 6, true);

    do
    {
        for (int a = 0; a < N; a++)
        {
            if (A[a] == true)
            {
                printf("%d ", S[a]);
            }
        }
        printf("\n");
    } while (prev_permutation(A.begin(), A.end()));

}


int main()
{
    int N = 1;
    
    do
    {
        vector<int> S;
        scanf("%d ", &N);

        if (N == 0) return 0;

        S = vector<int>(N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d ", &S[i]);
        }

        answer(N, S);
        printf("\n");

    } while (N != 0);
    
    return 0;
}
