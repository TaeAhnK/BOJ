// The Last year of Cain Calendar <M:N> is the Greatest Common Divisor of M, N 
// The Actual year of Cain Calendar <x:y> is the common year of {a:a = M * i + x, a <= gcd(M,N), i = 1, 2, 3...}
// and {b:b = M * i + y, b <= gcd(M,N), i = 1, 2, 3...}
// You can find the GCD with the Euclidean Algorithm abd the common year with the Two Pointer Algorithm

#include <iostream>

using namespace std;

class Cain
{
    public:
        Cain(int M, int N);             // Init
        ~Cain();                        // Destructor
        int ActualYear(int x, int y);   // Actual year of <x:y>
    protected:
    private:
        int MaxYearCalc();              // Calculate the actual last year
        int lcm(int a, int b);          // Least Common Multiple
        int gcd(int a, int b);          // Greatest Common Divisor
        int M;                          // M of the last year <M:N>
        int N;                          // N of the last year <M:N>
        int MaxYear;                    // The actual last year of <M:N>
};

Cain::Cain(int M, int N)
{
    this->M = M;
    this->N = N;
    this->MaxYear = MaxYearCalc();
};

Cain::~Cain()
{
};

int Cain::ActualYear(int x, int y)
{
    int xPointer, yPointer, xYear, yYear;
    int actualYear = -1;

    for (xPointer = 0, yPointer = 0; xPointer < MaxYear / x && yPointer < MaxYear / y; )
    {
        xYear = x + (M * xPointer);
        yYear = y + (N * yPointer);
        if (xYear == yYear)
        {
            actualYear = xYear;
            break;
        }
        else if (xYear > yYear)
        {
            yPointer++;
        }
        else // (xYear[xPointer] < yYear[yPointer]) 
        {
            xPointer++;
        }
    }

    return actualYear;
};

int Cain::MaxYearCalc()
{
    return lcm(M, N);
}

int Cain::lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
};

int Cain::gcd(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
};

int main()
{
    int T, M, N, x, y;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d %d %d %d\n", &M, &N, &x, &y);
        Cain C(M, N);
        printf("%d\n", C.ActualYear(x,y));
    }
}