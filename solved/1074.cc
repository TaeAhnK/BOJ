// Divide the field into 4 quadrant and find relative location.
// Recursively repeat this and with relative values, calculate the actual location

#include <iostream>
#include <utility>
#include <cmath>

class Z
{
    public:
        Z(int N);       // Init
        ~Z();           // Destructor
        int Search(int r, int c);                   // Search the number of (r,c)
    private:
        int quadrantDivide(int n, int r, int c);    // Find relative location of (r,c) and return the relative number
        int N;                                      // Size of Field (=2^n)
};

Z::Z(int N) :
    N(N)
{

};

Z::~Z()
{
};

int Z::Search(int r, int c)
{
    return quadrantDivide(N, r, c);
};

int Z::quadrantDivide(int n, int r, int c)
{
    if (n == 0)
    {
        return 0;
    }
    int axis = ((int)pow(2, n)) / 2;
    return ((int) pow(2, 2*n) / 4) * ((r / axis) * 2 + (c / axis)) + quadrantDivide(n - 1, (r % axis), (c % axis));
};

int main()
{
    int N, r, c;
    scanf("%d %d %d\n", &N, &r, &c);

    Z z(N);
    printf("%d\n", z.Search(r, c));

    return 0;
}