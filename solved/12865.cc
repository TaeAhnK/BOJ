// Backpack problem
// Use DP to find max weight

#include <iostream>
#include <vector>

using namespace std;

typedef struct item
{
    int value;
    int weight;
} Item;

class Backpack
{
public:
    void ReadItems(int N);
    int GetMaxPackValue(int K);
    void PrintCache();
private:
    vector<vector<int>> cache;
    vector<Item> items;
    int _N;
};

void Backpack::ReadItems(int N)
{
    int tempw, tempv;
    _N = N;
    Item item;
    item.weight = 0;
    item.value = 0;
    items.push_back(item);

    for (int i = 0; i < _N; i++)
    {
        scanf("%d %d\n", &tempw, &tempv);
        Item item;
        item.weight = tempw;
        item.value = tempv;
        items.push_back(item);
    }
}

int Backpack::GetMaxPackValue(int K)
{
    int maxValue = 0;
    cache = vector<vector<int>>(_N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= _N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j < items[i].weight)
            {
                cache[i][j] = cache[i-1][j];
            }
            else
            {
                cache[i][j] = max(cache[i-1][j], cache[i-1][j - items[i].weight] + items[i].value);
            }

            maxValue = max(cache[i][j], maxValue);
        }
    }

    return maxValue;
}

void Backpack::PrintCache()
{
    for (const auto& row : cache)
    {
        for (int elem : row)
        {
            printf("%d ", elem);
        }
        printf("\n");
    }
}

int main()
{
    int N, K;
    Backpack bp;

    scanf("%d %d\n", &N, &K);

    bp.ReadItems(N);
    printf("%d\n", bp.GetMaxPackValue(K));
    //bp.PrintCache();

    return 0;
}