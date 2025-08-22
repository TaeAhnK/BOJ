#include <iostream>
#include <vector>

using namespace std;

class matrix
{
public:
    matrix(int N, int M);
    void Flip(int sy, int sx);
    int MinFlip();
    bool IsValid(int sy, int sx);
private:
    void Print();
    int N;
    int M;
    vector<vector<int>> data;
    vector<vector<int>> target;
};

matrix::matrix(int N, int M) : N(N), M(M)
{
    data = vector<vector<int>>(N, vector<int>(M));
    target = vector<vector<int>>(N, vector<int>(M));
    
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            char temp;
            scanf("%c", &temp);
            data[n][m] = temp - '0';
        }
        scanf("\n");
    }

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            char temp;
            scanf("%c", &temp);
            target[n][m] = temp - '0';
        }
        scanf("\n");
    }
}

void matrix::Flip(int sy, int sx)
{
    for (int n = sy; n < sy + 3; n++)
    {
        for (int m = sx; m < sx + 3; m++)
        {
            if (data[n][m] == 1) data[n][m] = 0;
            else if (data[n][m] == 0) data[n][m] = 1;
        }        
    }
}

int matrix::MinFlip()
{
    int cnt = 0;

    for (int n = 0; n < N - 2; n++)
    {
        for (int m = 0; m < M - 2; m++)
        {
            if (data[n][m] != target[n][m] && IsValid(n, m))
            {
                Flip(n, m);
                cnt++;
            }
        }   
    }


    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (data[n][m] != target[n][m]) return -1;
        }   
    }

    return cnt;
}

bool matrix::IsValid(int sy, int sx)
{
    return (0 <= sx && sx < M && 0 <= sy && sy < N);
}


void matrix::Print()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            printf("%d", data[n][m]);
        }
        printf("\n");
    }
    printf("\n");

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            printf("%d", target[n][m]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int N, M;

    scanf("%d %d\n", &N, &M);

    matrix m(N, M);
    printf("%d\n", m.MinFlip());

}