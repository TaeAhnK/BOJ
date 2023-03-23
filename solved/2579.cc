// Calculate max stair score with recurrence relation f(n) = max(f(n-3)+ stair(n-1) + stair(n), f(n-2) + stair(n)) using dynamic programming.
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Step
{
    public:
        Step(int length);       // Init
        ~Step();                // Destructor
        int Jump(int N);        // Calculate max stair score with recurrence relation f(n) = max(f(n-3)+ stair(n-1) + stair(n), f(n-2) + stair(n))
    private:
        void readStairs();      // Read input
        int* cache;             // Cache for dynamic programming
        int* stairs;            // Stair score 
        int stairLen;           // Length of stairs

};

Step::Step(int length) :
    stairLen(length)
{
    cache = new int [stairLen + 1];
    stairs = new int [stairLen + 1];

    memset(cache, -1, sizeof(int) * (stairLen + 1));
    readStairs();

    cache[0] = 0;
    cache[1] = stairs[1];
    cache[2] = cache[1] + stairs[2];

};

Step::~Step()
{
    delete[] cache;
    delete[] stairs;
};

int Step::Jump(int N)
{
    if (N < 0 || stairLen < N) {
        return -1;
    }

    if (cache[N] == -1)
    {
        cache[N] = max(Jump(N-3) + stairs[N-1], Jump(N-2)) + stairs[N];        
    }

    return cache[N];
};

void Step::readStairs()
{
    for (int i = 1; i < stairLen + 1; i++)
    {
        scanf("%d\n", &(stairs[i]));
    }

    return;
};

int main()
{
    int S;
    scanf("%d\n", &S);

    Step st(S);
    printf("%d\n", st.Jump(S));

    return 0;
}