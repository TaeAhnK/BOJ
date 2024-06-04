// Get Matching char set with Dynamic Programming
// f[i][j] = f[i - 1][j - 1] + 1; if same character
// f[i][j] = max(f[i - 1][j], f[i][j - 1]); if not

#include <iostream>
#include <vector>

using namespace std;

class LCS
{
public:
    LCS(string a, string b); // Constructor
    int LCSLen();            // Get LCS Length

private:
    void PrintCache();         // Print for Debugging
    string a;                  // Input a
    string b;                  // Input b
    vector<vector<int>> cache; // cache for dynamic programming
};

LCS::LCS(string a, string b)
{
    this->a = a;
    this->b = b;
    cache = vector<vector<int>>(a.length() + 1, vector<int>(b.length() + 1, 0));
}

int LCS::LCSLen()
{
    int maxV = -1;
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                cache[i][j] = cache[i - 1][j - 1] + 1;
            }
            else
            {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
            maxV = max(cache[i][j], maxV);
        }
    }
    // PrintCache();
    return maxV;
}

void LCS::PrintCache()
{
    printf("  ");
    for (int i = 0; i < a.length(); i++)
    {
        printf("%c ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < cache.size(); i++)
    {
        for (int j = 0; j < cache[i].size(); j++)
        {
            printf("%d ", cache[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    string b;
    cin >> a;
    cin >> b;

    LCS lcs(a, b);

    printf("%d\n", lcs.LCSLen());
    return 0;
}