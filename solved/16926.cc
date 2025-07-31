#include <iostream>
#include <vector>

using namespace std;

enum Direction
{
    Up,
    Down,
    Left,
    Right,
    NotSet
};

class nmarray
{
public:
    nmarray(int N, int M);
    void Read();
    void Turn();
    void Print();

private:
    void SetMoveMap();

    vector<vector<int>> array;
    vector<vector<int>> temp;
    vector<vector<Direction>> MoveMap;
    int N;
    int M;
};

nmarray::nmarray(int N, int M) : N(N), M(M)
{
    array = vector<vector<int>>(N, vector<int>(M, 0));
    temp = vector<vector<int>>(N, vector<int>(M, 0));
    MoveMap = vector<vector<Direction>>(N, vector<Direction>(M, NotSet));
    SetMoveMap();
}

void nmarray::Read()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%d ", &array[n][m]);
        }
        scanf("\n");
    }
}

void nmarray::Turn()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            switch(MoveMap[n][m])
            {
                case Up:
                    temp[n - 1][m] = array[n][m];
                    break;
                case Down:
                    temp[n + 1][m] = array[n][m];
                    break;
                case Right:
                    temp[n][m + 1] = array[n][m];
                    break;
                case Left:
                    temp[n][m - 1] = array[n][m];
                    break;
                default:
                    temp[n][m] = array[n][m];
                    break;
            }
        }
    }
    swap(temp, array);
}

void nmarray::Print()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            printf("%d", array[n][m]);
            if (m != M - 1) printf(" ");
        }
        printf("\n");
    }
}

void nmarray::SetMoveMap()
{
    for (int i = 0, j = 0; i < M / 2; i++, j++)
    {
        for (int n = j; n < N - j - 1; n++)
        {
            MoveMap[n][i] = Down;
        }
    }

    for (int i = M - 1, j = 0; i >= M / 2; i--, j++)
    {
        for (int n = j + 1; n < N - j; n++)
        {
            MoveMap[n][i] = Up;
        }
    }

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (MoveMap[n][m] == NotSet && n < N/2) MoveMap[n][m] = Left;
            else if (MoveMap[n][m] == NotSet && n >= N/2) MoveMap[n][m] = Right;
        }
    }
}

int main()
{
    int N, M, R;

    scanf("%d %d %d\n", &N, &M, &R);
    
    nmarray a(N, M);
    a.Read();

    for (int r = 0; r < R; r++)
    {
        a.Turn();
    }
    a.Print();

    return 0;
}