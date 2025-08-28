#include <iostream>
#include <vector>

using namespace std;


int numLength(long long n)
{
    int cnt = 1;

    while (10 <= n)
    {
        n = n / 10;
        cnt++;
    }

    return cnt;
}

void draw(int i, vector<vector<char>>& grid, int n, int width, int height)
{
    int startw = n * width + n;

    switch(i)
    {
        case 0:
            for (int i = startw + 1; i < startw + width - 1; i++)
            {
                grid[0][i] = '-';
            }
            return;
        case 1:
            for (int i = 1; i < height / 2; i++)
            {
                grid[i][startw] = '|';
            }
            return;
        case 2:
            for (int i = 1; i < height / 2; i++)
            {
                grid[i][startw + width - 1] = '|';
            }
            return;
        case 3:
            for (int i = startw + 1; i < startw + width - 1; i++)
            {
                grid[height / 2][i] = '-';
            }
            return;
        case 4:
            for (int i = (height / 2) + 1; i < height - 1; i++)
            {
                grid[i][startw] = '|';
            }
            return;
        case 5:
            for (int i = (height / 2) + 1; i < height - 1; i++)
            {
                grid[i][startw + width - 1] = '|';
            }
            return;
        case 6:
            for (int i = startw + 1; i < startw + width - 1; i++)
            {
                grid[height - 1][i] = '-';
            }
            return;
    }
}




void draw0(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(1, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(4, grid, n, width, height);
    draw(5, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void draw1(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(2, grid, n, width, height);
    draw(5, grid, n, width, height);
}

void draw2(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(4, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void draw3(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(5, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void draw4(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(1, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(5, grid, n, width, height);
}

void draw5(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(1, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(5, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void draw6(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(1, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(4, grid, n, width, height);
    draw(5, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void draw7(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(5, grid, n, width, height);
}

void draw8(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(1, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(4, grid, n, width, height);
    draw(5, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void draw9(vector<vector<char>>& grid, int n, int width, int height)
{
    draw(0, grid, n, width, height);
    draw(1, grid, n, width, height);
    draw(2, grid, n, width, height);
    draw(3, grid, n, width, height);
    draw(5, grid, n, width, height);
    draw(6, grid, n, width, height);
}

void ans(int s, long long n)
{
    int width = s + 2;
    int height = (2 * s) + 3;
    int leng = numLength(n);
    int totalwidth = width * leng + leng;
    vector<vector<char>> lc(height, vector<char>(totalwidth, ' '));

    int cnt = leng;

    if (n == 0)
    {
        draw0(lc, --cnt, width, height);
        return;
    }

    while (n != 0)
    {
        cnt--;
        switch(n % 10)
        {
            case 0:
                draw0(lc, cnt, width, height);
                break;
            case 1:
                draw1(lc, cnt, width, height);
                break;
            case 2:
                draw2(lc, cnt, width, height);
                break;
            case 3:
                draw3(lc, cnt, width, height);
                break;
            case 4:
                draw4(lc, cnt, width, height);
                break;
            case 5:
                draw5(lc, cnt, width, height);
                break;
            case 6:
                draw6(lc, cnt, width, height);
                break;
            case 7:
                draw7(lc, cnt, width, height);
                break;
            case 8:
                draw8(lc, cnt, width, height);
                break;
            case 9:
                draw9(lc, cnt, width, height);
                break;
        }
        n = n / 10;
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < totalwidth; w++)
        {
            printf("%c", lc[h][w]);
        }
        printf("\n");
    }
}

int main()
{
    int s;
    long long  n;
    scanf("%d %lld", &s, &n);
    ans(s, n);

    return 0;
}