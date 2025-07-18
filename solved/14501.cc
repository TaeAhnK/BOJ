#include <iostream>
#include <vector>

using namespace std;

void MaxProfit(vector<vector<int>> table, int N)
{
    vector<int> cache(N + 2, 0);

    for (int i = N; i >= 1; i--)
    {
        if (table[i][0] + i - 1 > N)
        {
            cache[i] = cache[i + 1];
        }
        else
        {
            cache[i] = max(table[i][1] + cache[i + table[i][0]], cache[i + 1]);
        }
    }


    printf("%d\n", cache[1]);
}

int main()
{
    int N;
    
    scanf("%d\n", &N);

    vector<vector<int>> table(N + 1, vector<int>(2, -1));

    for (int i = 1; i <= N; i++)
    {
        int tempT, tempP;
        scanf("%d %d\n", &tempT, &tempP);
        table[i][0] = tempT;
        table[i][1] = tempP;
    }

    MaxProfit(table, N);

    return 0;
}