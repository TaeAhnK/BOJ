#include <iostream>
#include <vector>

using namespace std;

int answer(int N, vector<bool> current, vector<bool> target)
{
    int cnt0 = 0;
    vector<bool> source = current;

    for (int i = 1; i < N; i++)
    {
        if (source[i - 1] != target[i - 1])
        {
            source[i - 1] = !source[i - 1];
            source[i] = !source[i];
            if (i + 1 < N) source[i + 1] = !source[i + 1];
            cnt0++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (source[i] != target[i]) 
        {
            cnt0 = -1;
            break;
        }
    }

    int cnt1 = 1;
    source = current;
    source[0] = !source[0];
    source[1] = !source[1];

    for (int i = 1; i < N; i++)
    {
        if (source[i - 1] != target[i - 1])
        {
            source[i - 1] = !source[i - 1];
            source[i] = !source[i];
            if (i + 1 < N) source[i + 1] = !source[i + 1];
            cnt1++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (source[i] != target[i]) 
        {
            cnt1 = -1;
            break;
        }
    }

    if (cnt0 != -1 && cnt1 != -1) return min(cnt0, cnt1);
    else if (cnt0 == -1) return cnt1;
    else return cnt0;
}

int main()
{
    int N;
    vector<bool> current;
    vector<bool> target;

    scanf("%d\n", &N);

    current = vector<bool>(N);
    target = vector<bool>(N);

    for (int n = 0; n < N; n++)
    {
        char temp;
        scanf("%c", &temp);
        current[n] = (temp == '0' ? false : true);
    }
    scanf("\n");

    for (int n = 0; n < N; n++)
    {
        char temp;
        scanf("%c", &temp);
        target[n] = (temp == '0' ? false : true);
    }

    printf("%d\n", answer(N, current, target));

    return 0;
}

