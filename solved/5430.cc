// The AC Array does not change on command
// It only changes how it prints the result
// On R, change the Front - head, or tail
// On D, delete the Front by increasing headIndex or decreasing tailIndex
// If the length goes below 0, print error

#include <iostream>
#include <string.h>

using namespace std;

class AC {
    public:
        AC(int len);    // Init
        ~AC();          // Desturctor
        void D();       // Delete Front Element by increasing headIndex or decreasing tailIndex
        void R();       // Rotate the Array by changing the Front Flag - head, or tail
        void print();   // Print Array - From head to tail, tail to head, or error if length is -1
    protected:
    private:
        int* array;         // Stores input
        int length;         // Current length of array
        int headIndex;      // Current head index
        int tailIndex;      // Current tail index
        bool headIsFront;   // True if head is Front, false if tail is front
        bool isError;       // True if length is below 0
};

AC::AC(int len)
{
    int i;
    array = new int [len];
    length = len;
    headIndex = 0;
    tailIndex = length - 1;
    headIsFront = true;
    isError = false;

    scanf("[");
    for (i = 0; i < length - 1; i++)
    {
        scanf("%d,", &array[i]);
    }
    scanf("%d", &array[i]);
    scanf("]\n");

    return;
};

AC::~AC()
{
    delete[] array;
};

void AC::D()
{
    if (--length < 0) 
    {
        isError = true;
    }

    if (headIsFront == true)
    {
        headIndex++;
    }
    else
    {
        tailIndex--;
    }

    return;
};

void AC::R()
{
    headIsFront = !(headIsFront);

    return;
};

void AC::print()
{
    if (isError)
    {
        printf("error\n");
    }
    else if (length == 0)
    {
        printf("[]\n");
    }
    else if (headIsFront)
    {
        printf("[");
        for (int i = headIndex; i < tailIndex; i++)
        {
            printf("%d,", array[i]);
        }
        printf("%d]\n", array[tailIndex]);
    }
    else
    {
        printf("[");
        for (int i = tailIndex; headIndex < i; i--)
        {
            printf("%d,", array[i]);
        }
        printf("%d]\n", array[headIndex]);   
    }

    return;
};

int main()
{
    int T, n, strlen;
    char cmd[700000];

    scanf("%d\n", &T);

    for (int i = 0; i < T; i++)
    {
        memset(&cmd, '\0', 700000);
        scanf("%s\n", cmd);
        scanf("%d\n", &n);
        AC a(n);
        for (int j = 0; cmd[j] != '\0'; j++)
        {
            if (cmd[j] == 'D')
            {
                a.D();
            }
            else if (cmd[j] == 'R')
            {
                a.R();
            }
        }
        a.print();
    }
}