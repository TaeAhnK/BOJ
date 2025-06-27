#include <iostream>

using namespace std;

int main()
{
    int E, S, M;
    int Es = 0, Ss = 0, Ms = 0;
    int Cnt = 0;

    scanf("%d %d %d\n", &E, &S, &M);

    while (true)
    {
        Es++;
        Ss++;
        Ms++;
        Cnt++;

        if (Es > 15) Es = Es % 15;
        if (Ss > 28) Ss = Ss % 28;
        if (Ms > 19) Ms = Ms % 19;

        if (Es == E && Ss == S && Ms == M)
        {
            printf("%d\n", Cnt);
            break;
        }
    }

    return 0;
}