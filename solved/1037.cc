#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int trueDivisor, temp;
    int minTD = 1000001; 
    int maxTD = 0;

    scanf("%d\n", &trueDivisor);

    for (int i = 0; i < trueDivisor; i++)
    {
        scanf("%d ", &temp);
        minTD = min(temp, minTD);
        maxTD = max(temp, maxTD);
    }

    printf("%d", minTD * maxTD);

    return 0;
}