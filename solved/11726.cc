// Count rectangle with recurrence relation count(n) = count(n-1) + count(n-2) using dynamic programming.
#include <iostream>
#include <string.h>

class Tile 
{
    public:
        Tile(int N);            // Init
        ~Tile();                // Destructor
        int countRect(int n);   // Count rectangle with recurrence relation count(n) = count(n-1) + count(n-2) using dynamic programming.
    private:
        void printCache();      // Print for debugging
        int* cache;             // Cache for dynamic programming
        int length;             // Length of tile
};

Tile::Tile(int N) :
    length(N)
{
    cache = new int [length];
    memset(cache, -1, sizeof(int) * length);
    cache[1] = 1;
    cache[2] = 2;
};

Tile::~Tile()
{
    delete[] cache;
};

int Tile::countRect(int n)
{
    if (n <= 0 || length < n)
    {
        return 0;
    }

    if (cache[n] == -1)
    {
        cache[n] = (countRect(n-1) + countRect(n-2)) % 10007;
    }

    return cache[n];
}
void Tile::printCache()
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", cache[i]);
    }
    printf("\n");
};

int main()
{
    int n;
    scanf("%d\n", &n);

    Tile t(n + 1);
    printf("%d\n", t.countRect(n));

    return 0;
}