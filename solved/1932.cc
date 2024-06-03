// Sum backward from bottom to top
// f[index] = max(f[index + currentLength], f[index + currentLength + 1]) + index;

#include <iostream>
#include <vector>

using namespace std;

class IntTriangle
{
public:
    IntTriangle(int N); // Initialize
    void ReadData();    // Read Input
    int MaxRouteSum();  // Get Max Sum
    void PrintData();   // Print for debug
    void PrintCache();  // Print for debug

private:
    int n;             // n : size of triangle
    vector<int> data;  // input data
    vector<int> cache; // cache for dynamic programming
};

IntTriangle::IntTriangle(int N)
{
    this->n = N;
    cache = vector<int>((N * (N + 1)) / 2, -1);
}

void IntTriangle::ReadData()
{
    int input;
    for (int i = 1, index = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++, index++)
        {
            scanf("%d ", &input);
            data.push_back(input);
        }
    }
}

int IntTriangle::MaxRouteSum()
{

    for (int index = ((n * (n + 1)) / 2) - 1, i = n; 0 < i; i--)
    {
        for (int j = i; 0 < j; j--, index--)
        {
            if (i == n)
            {
                cache[index] = data[index];
            }
            else
            {
                cache[index] = max(cache[index + i], cache[index + i + 1]) + data[index];
            }
        }
    }
    return cache[0];
}

void IntTriangle::PrintData()
{
    for (int i = 0; i < (int)data.size(); i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void IntTriangle::PrintCache()
{
    for (int i = 0; i < (int)cache.size(); i++)
    {
        printf("%d ", cache[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d\n", &n);

    IntTriangle it(n);
    it.ReadData();
    printf("%d\n", it.MaxRouteSum());
    return 0;
}