#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NMArray
{
public:
    NMArray(int N, int M);
    void Read();
    void Calc(int i);
    void PrintArray();

private:
    void HorizontalFlip();
    void VerticalFlip();
    void RightTurn();
    void LeftTurn();
    void ClockShift();
    void CounterClockShift();

    int N;
    int M;
    vector<vector<int>> array;
    vector<vector<int>> temp;
};

NMArray::NMArray(int N, int M) : N(N), M(M) 
{
    array = vector<vector<int>>(max(N, M), vector<int>(max(N, M), 0));
    temp = vector<vector<int>>(max(N, M), vector<int>(max(N, M), 0));
}

void NMArray::Read()
{
    int temp;

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
           scanf("%d ", &temp);
           array[n][m] = temp;
        }
        scanf("\n");
    }
}

void NMArray::Calc(int i)
{
    switch(i)
    {
        case 1:
            HorizontalFlip();
            break;
        case 2:
            VerticalFlip();
            break;
        case 3:
            RightTurn();
            break;
        case 4:
            LeftTurn();
            break;
        case 5:
            ClockShift();
            break;
        case 6:
            CounterClockShift();
        default:
            break;
    }
}

void NMArray::HorizontalFlip()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            temp[N - 1 - n][m] = array[n][m];
        }
    }

    swap(array, temp);
}

void NMArray::VerticalFlip()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            temp[n][M - 1 - m] = array[n][m];
        }
    }

    swap(array, temp);
}

void NMArray::RightTurn()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            temp[m][N -1 - n] = array[n][m];
        }
    }
    swap(N, M);
    swap(array, temp);
}

void NMArray::LeftTurn()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            temp[M -1 - m][n] = array[n][m];
        }
    }
    swap(N, M);
    swap(array, temp);
}

void NMArray::ClockShift()
{
    int hn = N/2;
    int hm = M/2;

    for (int n = 0; n < hn; n++)
    {
        for (int m = 0; m < hm; m++)
        {
            temp[n][m + hm] = array[n][m];
        }
    }

    for (int n = 0; n < hn; n++)
    {
        for (int m = hm; m < M; m++)
        {
            temp[n + hn][m] = array[n][m];
        }
    }

    for (int n = hn; n < N; n++)
    {
        for (int m = 0; m < hm; m++)
        {
            temp[n - hn][m] = array[n][m];
        }
    }

    for (int n = hn; n < N; n++)
    {
        for (int m = hm; m < M; m++)
        {
            temp[n][m - hm] = array[n][m];
        }
    }

    swap(array, temp);
}

void NMArray::CounterClockShift()
{
    int hn = N/2;
    int hm = M/2;

    for (int n = 0; n < hn; n++)
    {
        for (int m = 0; m < hm; m++)
        {
            temp[n + hn][m] = array[n][m];
        }
    }

    for (int n = 0; n < hn; n++)
    {
        for (int m = hm; m < M; m++)
        {
            temp[n][m - hm] = array[n][m];
        }
    }

    for (int n = hn; n < N; n++)
    {
        for (int m = 0; m < hm; m++)
        {
            temp[n][m + hm] = array[n][m];
        }
    }

    for (int n = hn; n < N; n++)
    {
        for (int m = hm; m < M; m++)
        {
            temp[n - hn][m] = array[n][m];
        }
    }

    swap(array, temp);
}

void NMArray::PrintArray()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            printf("%d", array[n][m]);
            if (m == M - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

int main()
{
    int N, M, R;

    scanf("%d %d %d\n", &N, &M, &R);

    NMArray nmarray(N, M);

    nmarray.Read();

    for (int r = 0; r < R; r++)
    {
        int temp;
        scanf("%d ", &temp);
        nmarray.Calc(temp);
    }
    nmarray.PrintArray();

    return 0;
}