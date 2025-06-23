#include <iostream>

using namespace std;

int GetOne(int n)
{
    int cnt = 1;
    int nx = 1;

    while (nx % n != 0)
    {
        nx = (nx * 10 + 1) % n;
        cnt++;
    }

    return cnt;
}

int main()
{
    int n;
    
    while (scanf("%d\n", &n) != EOF)
    {
        printf("%d\n", GetOne(n));
    }

    return 0;
}

