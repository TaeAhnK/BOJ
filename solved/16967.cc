#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans(int H, int W, int X, int Y, vector<vector<int>> array)
{
    vector<vector<int>> answer(H, vector<int>(W));

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            array[h + X][w + Y] = array[h + X][w + Y] - array[h][w];
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            answer[h][w] = array[h][w];
        }
    }

    return answer;
}


int main()
{
    int H, W, X, Y;
    vector<vector<int>> array;

    scanf("%d %d %d %d\n", &H, &W, &X, &Y);

    array = vector<vector<int>>(H + X, vector<int>(W + Y));

    for (int h = 0; h < H + X; h++)
    {
        for (int w = 0; w < W + Y; w++)
        {
            scanf("%d ", &array[h][w]);
        }
        scanf("\n");
    }

    vector<vector<int>> answer = ans(H, W, X, Y, array);

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            printf("%d ", answer[h][w]);
        }
        printf("\n");
    }

    return 0;
}