// Get Max Value Sum by Dynamic Programming :
// cache[0][i] = max(cache[1][i - 1], cache[1][i - 2]) + stickers[0][i];
// cache[1][i] = max(cache[0][i - 1], cache[0][i - 2]) + stickers[0][i];

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stickers
{
public:
    Stickers(int n);      // Init
    void ReadData();      // Read Input
    void MaxValue();      // Get Max Sum
    void PrintStickers(); // Print for Debug
    void PrintCache();    // Print for Debug

private:
    vector<vector<int>> stickers; // Value Data
    vector<vector<int>> cache;    // Cache for DP
    int n;                        // Total n
};

Stickers::Stickers(int n)
{
    this->n = n;
    stickers = vector<vector<int>>(2, vector<int>(n));
    cache = vector<vector<int>>(2, vector<int>(n, -1));
}

void Stickers::ReadData()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &stickers[i][j]);
        }
    }
}

void Stickers::MaxValue()
{
    cache[0][0] = stickers[0][0];
    cache[1][0] = stickers[1][0];

    for (int i = 1; i < n; i++)
    {
        if (cache[0][i] == -1)
        {
            cache[0][i] = max(cache[1][i - 1], cache[1][i - 2]) + stickers[0][i];
        }
        if (cache[1][i] == -1)
        {
            cache[1][i] = max(cache[0][i - 1], cache[0][i - 2]) + stickers[1][i];
        }
    }

    printf("%d\n", max(cache[0][n - 1], cache[1][n - 1]));
}

void Stickers::PrintStickers()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", stickers[i][j]);
        }
        printf("\n");
    }
}

void Stickers::PrintCache()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", cache[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int T, n, input;

    scanf("%d\n", &T);

    for (int t = 0; t < T; t++)
    {
        scanf("%d\n", &input);
        Stickers S(input);
        S.ReadData();
        S.MaxValue();
    }
}