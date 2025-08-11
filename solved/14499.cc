#include <iostream>
#include <vector>

using namespace std;

class dicemap
{
public:
    dicemap(int N, int M, int x, int y);
    void ReadMap();
    void Roll(int dir);
private:
    bool IsValid(int x, int y);
    int dice[7] = {0, 0, 0, 0, 0, 0, 0};
    int temp[7] = {0, 0, 0, 0, 0, 0, 0};
    int dx[5] = {0, 1, -1, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};
    vector<vector<int>> map;
    int cx;
    int cy;
    int N;
    int M;
};

dicemap::dicemap(int N, int M, int x, int y) : N(N), M(M), cx(x), cy(y)
{
    map = vector<vector<int>>(N, vector<int>(M));
    ReadMap();
}

void dicemap::ReadMap()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%d ", &map[n][m]);
        }
        scanf("\n");
    }
}

void dicemap::Roll(int dir)
{
    if (!IsValid(dx[dir]+ cx, dy[dir] + cy)) return;

    cx = cx + dx[dir];
    cy = cy + dy[dir];

    switch(dir)
    {
        case 1:
            temp[4] = dice[1];
            temp[2] = dice[2];
            temp[1] = dice[3];
            temp[6] = dice[4];
            temp[5] = dice[5];
            temp[3] = dice[6];
            break;
        case 2:
            temp[3] = dice[1];
            temp[2] = dice[2];
            temp[6] = dice[3];
            temp[1] = dice[4];
            temp[5] = dice[5];
            temp[4] = dice[6];
            break;
        case 3:
            temp[5] = dice[1];
            temp[1] = dice[2];
            temp[3] = dice[3];
            temp[4] = dice[4];
            temp[6] = dice[5];
            temp[2] = dice[6];
            break;
        case 4:
            temp[2] = dice[1];
            temp[6] = dice[2];
            temp[3] = dice[3];
            temp[4] = dice[4];
            temp[1] = dice[5];
            temp[5] = dice[6];
            break;
    }

    swap(temp, dice);

    if (map[cy][cx] == 0) map[cy][cx] = dice[6];
    else 
    {
        dice[6] = map[cy][cx];
        map[cy][cx] = 0;
    }
    printf("%d\n", dice[1]);
}

bool dicemap::IsValid(int x, int y)
{
    return (0 <= x) && (x < M) && (0 <= y) && (y < N);
}


int main()
{
    int N, M, K, r, c, temp;

    scanf("%d %d %d %d %d\n", &N, &M, &r, &c, &K);

    dicemap dm(N, M, c, r);

    for (int k = 0; k < K; k++)
    {
        scanf("%d ", &temp);
        dm.Roll(temp);
    }

    return 0;
}