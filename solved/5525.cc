// Use KMP algorithm and find P in the string S

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IOI
{
    public:
        IOI();              // Init
        ~IOI();             // Destructor
        int KMP();          // KMP Algorithm. Finds IOI inside string
    private:
        void fail();        // Set failure function (Works only with P)
        void printStrings();// Print for debugging
        int N;              // P is made if N+1 Is and N Os
        int SLength;        // Length of S
        string S;           // We should find P in S
        string P;           // P is consecutive I and O
        vector<int> failure;// Failure table that stores suffix/prefix info for KMP
        
};

IOI::IOI() :
    P("I")
{
    char temp[1000001];
    scanf("%d\n", &N);
    scanf("%d\n", &SLength);
    scanf("%s\n", temp);
    S = temp;

    for (int i = 0; i < N; i++)
    {
        P.append("OI");
    }
    failure.assign(2*N+1, -1);
    fail();
}

IOI::~IOI()
{
}

int IOI::KMP()
{
    int cnt = 0;
    for (int i = 0, j = 0; i < SLength; i++)
    {
        while (j > 0 && S[i] != P[j])
        {
            j = failure[j - 1];
        }

        if (S[i] == P[j])
        {
            if (j == 2 * N)
            {
                cnt++;
                j = failure[j];
            }
            else
            {
                j++;
            }
        }
    }
    return cnt;
}

void IOI::fail()
{
    failure[0] = 0;
    failure[1] = 0;

    for (int i = 2; i < N * 2 + 1; i++)
    {
        failure[i] = i - 1;
    }
}

void IOI::printStrings()
{
    for (int i = 0; i < (2 * N) + 1; i++)
    {
        printf("%c", P[i]);
    }

    printf("\n");
    for (int i = 0; i < SLength; i++)
    {
        printf("%c", S[i]);
    }
    printf("\n");
}

int main()
{
    IOI i;
    printf("%d\n", i.KMP());

    return 0;
}