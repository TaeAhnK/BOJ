#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<bool> cache(1000001, true);

    cache[0] = false;
    cache[1] = false;

    for (int i = 2; i <= 1000000; i++)
    {
        for (int j = 2; j * i <= 1000000; j++)
        {
            cache[i*j] = false;
        }
    }

    scanf("%d\n", &n);
    while (n != 0)
    {
        bool flag = false;
        for (int i = 3; i <= (n / 2) + 1; i++)
        {
            if (cache[i] == true && cache[n - i] == true)
            {
                printf("%d = %d + %d\n", n, i, n-i);
                flag = true;
                break;
            }
        }

        if (!flag) printf("Goldbach's conjecture is wrong");

        scanf("%d\n", &n);
    }

    return 0;
}