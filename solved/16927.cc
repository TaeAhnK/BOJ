#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class nmarray
{
public:
    nmarray(int N, int M);
    void Read();
    void Turn(int R);
private:
    void PrintLayerList(vector<queue<int>> layerList);
    void PrintArray();
    vector<vector<int>> array;
    vector<queue<int>> layerList;
    int N;
    int M;
};

nmarray::nmarray(int N, int M) : N(N), M(M)
{
    array = vector<vector<int>>(N, vector<int>(M, 0));
    layerList = vector<queue<int>>(min(N, M) / 2, queue<int>());
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

    for (int layer = 0; layer < min(N, M) / 2; layer++)
    {
        for (int m = layer; m < M - layer; m++)
        {
            layerList[layer].push(array[layer][m]);
        }
        
        for (int n = layer + 1; n < N - layer; n++)
        {
            layerList[layer].push(array[n][M - layer - 1]);
        }

        for (int m = M - 2 - layer; 0 < m - layer; m--)
        {
            layerList[layer].push(array[N - layer - 1][m]);
        }

        for (int n = N - 1 - layer; 0 < n - layer; n--)

        {
            layerList[layer].push(array[n][layer]);
        }
    }
}

void nmarray::Turn(int R)
{
    for (int layer = 0; layer < min(N, M) / 2; layer++)
    {
        for (int r = 0; r < R % layerList[layer].size(); r++)
        {
            layerList[layer].push(layerList[layer].front());
            layerList[layer].pop();
        }

        for (int m = layer; m < M - layer; m++)
        {
            array[layer][m] = layerList[layer].front();
            layerList[layer].pop();
        }
        
        for (int n = layer + 1; n < N - layer; n++)
        {
            array[n][M - layer - 1] = layerList[layer].front();
            layerList[layer].pop();
        }

        for (int m = M - 2 - layer; 0 < m - layer; m--)
        {
            array[N - layer - 1][m] = layerList[layer].front();
            layerList[layer].pop();
        }

        for (int n = N - 1 - layer; 0 < n - layer; n--)
        {
            array[n][layer] = layerList[layer].front();
            layerList[layer].pop();
        }
    }

    PrintArray();
}

void nmarray::PrintLayerList(vector<queue<int>> layerList)
{
    for (int i = 0; i < layerList.size(); i++)
    {
        while (!layerList[i].empty())
        {
            printf("%d ", layerList[i].front());
            layerList[i].pop();
        }
        printf("\n");
    }
}

void nmarray::PrintArray()
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

int main()
{
    int N, M, R;

    scanf("%d %d %d\n", &N, &M, &R);

    nmarray nm(N, M);

    nm.Read();
    nm.Turn(R);

    return 0;
}
