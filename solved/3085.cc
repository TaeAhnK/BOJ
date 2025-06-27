#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CandyGame(vector<vector<char>> board, int N)
{
    int max = 0;
    int currentCntVertical = 0;
    int currentCntHorizonal = 0;
    char currentVertical = board[0][0];
    char currentHorizontal = board[0][0];

    for (int i = 0; i < N; i++)
    {
        currentVertical = board[i][0];
        currentHorizontal = board[0][i];
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == currentVertical)
            {
                currentCntVertical++;
            }
            else
            {
                max = std::max(currentCntVertical, max);
                currentVertical = board[i][j];
                currentCntVertical = 1;
            }

            if (board[j][i] == currentHorizontal)
            {
                currentCntHorizonal++;
            }
            else
            {
                max = std::max(currentCntHorizonal, max);
                currentHorizontal = board[j][i];
                currentCntHorizonal = 1;
            }
        }
        
        max = std::max(currentCntVertical, max);
        max = std::max(currentCntHorizonal, max);
        currentCntVertical = 0;
        currentCntHorizonal = 0;
    }

    return max;
}


int main()
{
    int N;
    int max = 0;
    char temp;

    scanf("%d\n", &N);

    vector<vector<char>> board(N, vector<char>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &temp);
            board[i][j] = temp;
        }
        scanf("\n");
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            temp = board[i][j];
            board[i][j] = board[i][j+1];
            board[i][j+1] = temp;

            max = std::max(CandyGame(board, N), max);

            temp = board[i][j];
            board[i][j] = board[i][j+1];
            board[i][j+1] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            temp = board[j][i];
            board[j][i] = board[j+1][i];
            board[j+1][i] = temp;

            max = std::max(CandyGame(board, N), max);
            
            temp = board[j][i];
            board[j][i] = board[j+1][i];
            board[j+1][i] = temp;
        }
    }

    printf("%d\n", max);

    return 0;
}