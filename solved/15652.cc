// Recursively track with DFS
#include <vector>
#include <iostream>

using namespace std;

class NnM
{
    public:
        NnM(int n, int m);
        void PrintSequences();
    private:
        void DFS(int start);
        vector<int> seq;
        int N;
        int M;
};

NnM::NnM(int n, int m)
{
    this->N = n;
    this->M = m;
}

void NnM::PrintSequences()
{
    DFS(1);
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

    for (int i = start; i <= N; i++)
    {
        seq.push_back(i);
        DFS(i);
        seq.pop_back();
    }
}

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);

    NnM nnm(n, m);

    nnm.PrintSequences();

}