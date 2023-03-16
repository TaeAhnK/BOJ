// Count length of triangle sides with recurrence relation P(n) = P(n-2) + P(n-3) using dynamic programming.
#include <iostream>
#include <string.h>

class TriSideProgression
{
    public:
        TriSideProgression(int max);    // Init
        ~TriSideProgression();          // Destructor
        long long P(int N);             // Count length of triangle sides
    private:
        void printCache();              // Print for debugging
        long long *cache;               // Cache for dynamic programming
        int maxN;                       // Max N
};

TriSideProgression::TriSideProgression(int max) :
    maxN(max)
{
    cache = new long long [maxN];
    memset(cache, -1, sizeof(long long) * maxN);
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 1;
};

TriSideProgression::~TriSideProgression()
{
    delete[] cache;
};

long long TriSideProgression::P(int N)
{
    if (maxN < N)
    {
        return 0;
    }

    if (cache[N] == -1)
    {
        cache[N] = P(N - 2) + P(N - 3);
    }

    return cache[N];
};

void TriSideProgression::printCache()
{
    for (int i = 0; i < maxN; i++)
    {
        printf("%lld ", cache[i]);
    }
};

int main()
{
    int T, N;
    scanf("%d\n", &T);
    
    TriSideProgression tri(101);

    for (int t = 0; t < T; t++)
    {
        scanf("%d\n", &N);
        printf("%lld\n", tri.P(N));
    }
    return 0;
}
