// For nth element, the longest increasng array length is 
// (max of longest increasing array length of 0 ~ n-1 that is smaller than nth element) + 1
// Use dynamic programming to calculate the longest increasing array length

#include <iostream>
#include <algorithm>

class Sequence
{
    public:
        Sequence(int N);        // Init
        ~Sequence();            // Destructor
        int LongestIncrease();  // Calculate Longest Increasing Array Length
    private:
        void Read();            // Read Data
        void Print();           // Print for Debugging
        int length;             // Length of Array
        int* data;              // Array
        int* dp;                // DP Chart
};

Sequence::Sequence(int N)
{
    length = N;
    data = new int [N];
    dp = new int [N];

    for (int i = 0; i < length; i++)
    {
        dp[i] = -1;
    }

    Read();
}

Sequence::~Sequence()
{
    delete[] data;
    delete[] dp;
}

int Sequence::LongestIncrease()
{
    int currentLongestIncrease = 1;
    int current;
    dp[0] = 1;

    for (int i = 1; i < length; i++)
    {
        current = 0;
        for (int j = 0; j < i; j++)
        {
            if (data[i] > data[j])
            {
                current = std::max(current, dp[j]);
            }
            dp[i] = current+1;
            currentLongestIncrease = std::max(currentLongestIncrease, dp[i]);
        }
    }   
    //Print();

    return currentLongestIncrease;
}

void Sequence::Read()
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d ", &(data[i]));
    }
}

void Sequence::Print()
{
    printf("Data :\t");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", data[i]);
    }
    
    printf("\nDP :\t");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", dp[i]);
    }
    printf("\n");
}

int main()
{
    int N;

    scanf("%d\n", &N);
    Sequence S(N);
    printf("%d\n", S.LongestIncrease());

    return 0;
}