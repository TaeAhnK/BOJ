#include <iostream>
#include <vector>

using namespace std;

int answer(int N, int S, vector<int> list)
{
    int cnt = 0;

    for (int m = 1; m < (1<<N); m++)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (m & (1<<i))
            {
                sum += list[i];
            }
        }
        if (sum == S) 
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int N, S;
    vector<int> list;

    scanf("%d %d\n", &N, &S);

    list = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &list[i]);
    }

    printf("%d\n", answer(N, S, list));

    return 0;
}