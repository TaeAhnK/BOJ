#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    public:
    Graph(int N);
    void AddVertex(int a, int b);
    void CheckCircularRelation();
    
    vector<vector<int>> adjlist;
    int N;

    private:
    void DFS(int index);
    void Reset();
    vector<bool> visited;
    int cnt = 0;
    bool flag = false;
};

Graph::Graph(int N) : N(N)
{
    adjlist.resize(N);
    visited.resize(N, false);
}

void Graph::AddVertex(int a, int b)
{
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
}

void Graph::CheckCircularRelation()
{
    for (int i = 0; i < N; i++)
    {
        Reset();
        DFS(i);
        if (flag == true)
        {
            return;
        }
    }

    printf("0");
}

void Graph::DFS(int index)
{
    if (flag) return;

    visited[index] = true;
    cnt++;

    if (cnt == 5)
    {
        printf("1");
        flag = true;
        return;
    }

    for (int i = 0; i < adjlist[index].size(); i++)
    {
        if (!visited[adjlist[index][i]])
            DFS(adjlist[index][i]);
    }

    cnt--;
    visited[index] = false;
}

void Graph::Reset()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    cnt = 0;
}

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);

    Graph g(N);

    for (int m = 0; m < M; m++)
    {
        int tempA, tempB;
        scanf("%d %d\n", &tempA, &tempB);
        g.AddVertex(tempA, tempB);
    }

    g.CheckCircularRelation();

    return 0;
}
