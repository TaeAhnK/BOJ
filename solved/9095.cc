// Calculate recurrence relation count(n) = count(n-1) + count(n-2) + count(n-3) using dynamic programming.

#include <iostream>
#include <string.h>

class OneTwoThree 
{
    public:
        OneTwoThree(int N);     // Init
        ~OneTwoThree();         // Destructor
        int countCom(int n);    // Calculate recurrence relation, memo the result
    private:
        void printCache();      // Print for debugging
        int* cache;             // Cache for dynamic programming
        int maxLength;          // Max size of input
};

OneTwoThree::OneTwoThree(int N) :
    maxLength(N)
{
    cache = new int [maxLength];
    memset(cache, -1, sizeof(int) * maxLength);
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

};

OneTwoThree::~OneTwoThree()
{
    delete[] cache;
};

int OneTwoThree::countCom(int n)
{
    if (n <= 0 || maxLength < n)
    {
        return 0;
    }

    if (cache[n] == -1)
    {
        cache[n] = countCom(n-1) + countCom(n-2) + countCom(n-3);
    }
    //printCache();
    return cache[n];
}
void OneTwoThree::printCache()
{
    for (int i = 0; i < maxLength; i++)
    {
        printf("%d ", cache[i]);
    }
    printf("\n");
};

int main()
{
    int T, n;
    scanf("%d\n", &T);

    OneTwoThree o(11);

    for (int t = 0; t < T; t++)
    {
        scanf("%d\n", &n);
        printf("%d\n", o.countCom(n));
    }

    return 0;
    
}