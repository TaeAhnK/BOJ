// Find min click case between
// 1. Go to number that is bigger than target & is clickable
// 2. Go to number that is smaller than target & is clickable
// 3. Only use + or - button

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1000000;

class remote
{
    public:
        remote();               // Init
        ~remote();              // Destructor
        int minClick();         // Minum click to reach target
    private:
        void read();                // Read data
        int overNum(int start);     // Find number that is bigger than target & is clickable
        int underNum(int start);    // Find to number that is smaller than target & is clickable
        int digitCount(int num);    // Count digit of num
        bool canClick(int num);     // Check if the number can be reached only with pressing num buttons
        bool isNotBroken[10];       // True if button is not broken, false if it is
        int target;                 // Target channel
};

remote::remote()
{
    read();
}

remote::~remote()
{
}

int remote::minClick()
{
    int over = overNum(target);
    int under = underNum(target);

    return min({over-target+digitCount(over), target-under+digitCount(under), abs(target-100)});
}

void remote::read()
{
    int brokenNums;
    int brokenNum;

    memset(isNotBroken, 1, sizeof(bool)*10);
    scanf("%d\n", &target);
    scanf("%d\n", &brokenNums);

    for (int i = 0; i < brokenNums; i++)
    {
        scanf("%d ", &brokenNum);
        isNotBroken[brokenNum] = false;
    }
}

int remote::overNum(int start)
{
    int temp = start;

    if (start > INF)
    {
        return INF;
    }
    if (!canClick(start))
    {
        temp = overNum(start+1);
    }

    return temp;
}

int remote::underNum(int start)
{
    int temp = start;
    if (start < 0)
    {
        return -INF;
    }
    if (!canClick(start))
    {
        temp = underNum(start-1);
    }

    return temp;
}

int remote::digitCount(int num)
{
    int cnt = 0;
    do {
        num /= 10;
        cnt++;
    } while(num!=0);

    return cnt;
}

bool remote::canClick(int num)
{
    do {
        if (!isNotBroken[num % 10])
        {
            return false;
        }
        num /= 10;
    } while(num!=0);

    return true;
}

int main()
{
    remote R;
    printf("%d\n", R.minClick());
    
    return 0;
}