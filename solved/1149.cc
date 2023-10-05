// Calculate minimum sum by Dynamic Programming

#include <iostream>
#include <algorithm>

class RGBStreet
{
    public:
        RGBStreet(int N);   // Init
        ~RGBStreet();       // Destructor
        int MinPaint();     // Minimum paint usage
        void Print();       // Print for debugging
    private:
        void Read();        // Read data
        int** street;       // Data
        int** dp;           // DP table for minimum paint usage
        int num;            // The number of house
};

RGBStreet::RGBStreet(int N)
{
    num = N + 1;
    street = new int* [3];
    dp = new int* [3];

    for (int i = 0; i < 3; i++)
    {
        street[i] = new int[num];
        dp[i] = new int[num];
    }
    Read();
}

RGBStreet::~RGBStreet()
{
    for (int i = 0; i < 3; i++)
    {
        delete[] street[i];
        delete[] dp[i];
    }
    delete[] street;
    delete[] dp;
}

int RGBStreet::MinPaint()
{
    dp[0][1] = street[0][1];
    dp[1][1] = street[1][1];
    dp[2][1] = street[2][1];
    
    for (int i = 2; i < num; i++)
    {
        dp[0][i] = std::min(dp[1][i-1], dp[2][i-1]) + street[0][i];
        dp[1][i] = std::min(dp[0][i-1], dp[2][i-1]) + street[1][i];
        dp[2][i] = std::min(dp[0][i-1], dp[1][i-1]) + street[2][i];
    }
    return std::min({dp[0][num-1], dp[1][num-1], dp[2][num-1]});
}

void RGBStreet::Read()
{
    for (int i = 1; i < num; i++)
    {
        scanf("%d %d %d\n", &(street[0][i]), &(street[1][i]), &(street[2][i]));
    }
}

void RGBStreet::Print()
{
    printf("Street\nR\tG\tB\n");
    for (int i = 1; i < num; i++)
    {
        printf("%d\t%d\t%d\n", street[0][i], street[1][i], street[2][i]);
    }
    printf("\nDP\nR\tG\tB\n");
    for (int i = 1; i < num; i++)
    {
        printf("%d\t%d\t%d\n", dp[0][i], dp[1][i], dp[2][i]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    RGBStreet street(N);

    printf("%d\n", street.MinPaint());
    
    return 0;
}