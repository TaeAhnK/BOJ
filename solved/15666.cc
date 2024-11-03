// Recursively track with DFS
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class NnM
{
    public:
        NnM(int m);
        void PrintSequences();
        void AddData(int d);
        void DebugPrint();
    private:
        void DFS(int start);
        vector<int> data;
        vector<int> seq;
        int M;
};

NnM::NnM(int m)
{
    this->M = m;
}

void NnM::PrintSequences()
{
    sort(data.begin(), data.end());
    DFS(0);
}

void NnM::AddData(int d)
{
    auto var = find(data.begin(), data.end(), d);
    if (var == data.end())
    {
        data.push_back(d);
    }
}

void NnM::DebugPrint()
{
    for (int i = 0 ; i < data.size(); i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    for (int i = 0 ; i < seq.size(); i++)
    {
        printf("%d ", seq[i]);
    }
    printf("\n");

}

void NnM::DFS(int start)
{
    if (seq.size() == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", seq[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < data.size(); i++)
    {
        seq.push_back(data[i]);
        DFS(i);
        seq.pop_back();
    }
}

int main()
{
    int n, m, temp;
    scanf("%d %d\n", &n, &m);

    NnM nnm(m);

    for (int i = 0 ; i < n; i++)
    {
        scanf("%d ", &temp);
        nnm.AddData(temp);
    }

    nnm.PrintSequences();

}

