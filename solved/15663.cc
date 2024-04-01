// Permutation nPr
// if r + 1 ~ n gets reversed, the next permutation is update of 0 ~ r,
// which makes the Permutation of nPr
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, temp;
    vector<int> v;

    scanf("%d %d\n", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    do
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        reverse(v.begin() + M,  v.end());
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}