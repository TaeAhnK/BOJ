// Count shortest path from 1 to N with recurrence relation X = min(X*3, X*2, X+1) + 1 using dynamic programming.
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000002;    // INFINITE as Max Length + 2

class X
{
    public:
        X(int N);           // Init
        ~X();               // Destructor
        int Xcalc(int X);   // Count shortest path with recurrence relation X = min(X*3, X*2, X+1) + 1
    private:
        void printCache();  // Print for debugging
        int *cache;         // Cache for dynamic programming
        int N;              // Target
};

X::X(int N) :
    N(N)
{
    cache = new int [N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        cache[i] = INF;
    }
    cache[N] = 0;
};

X::~X()
{
    delete[] cache;
};

int X::Xcalc(int X)
{
    if (N < X)
    {
        return INF;
    }

    if (cache[X] == INF)
    {
        cache[X] = min({Xcalc(X * 3), Xcalc(X * 2), Xcalc(X + 1)}) + 1;
    }

    return cache[X];
};

void X::printCache()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", cache[i]);
    }
};

int main()
{
    int N;
    scanf("%d\n", &N);
    
    X x(N);

    printf("%d\n", x.Xcalc(1));
    
    return 0;
}
