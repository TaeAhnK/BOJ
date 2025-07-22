#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    public:
    Graph(int N);
    void AddEdge(int u, int v);
    void Paint();
    void DFS(int index, int paint);
    int NextPaint(int paint);
    vector<vector<int>> adjlist;
    vector<bool> visited;
    vector<int> vertexPaint;
    int N;
    bool flag = true;
};

Graph::Graph(int N) : N(N)
{
    adjlist.resize(N + 1);
    vertexPaint.resize(N + 1, -1);
    visited.resize(N + 1, false);
}

void Graph::AddEdge(int u, int v)
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}

void Graph::Paint()
{
    for (int i = 1; i <= N; i++)
    {
        if (vertexPaint[i] == -1)
        {
            DFS(i, 0);
        }
    }

    if (flag)
    {
        printf("YES\n");
    }
}

void Graph::DFS(int index, int paint)
{
    if (!flag) return; 

    vertexPaint[index] = paint;

    for (int i = 0; i < adjlist[index].size(); i++)
    {
        if (!flag) return;

        if (vertexPaint[adjlist[index][i]] == -1)
            DFS(adjlist[index][i], NextPaint(paint));

        else if (vertexPaint[adjlist[index][i]] == paint)
        {
            flag = false;
            printf("NO\n");
            return;
        }
    }
}

int Graph::NextPaint(int paint)
{
    return paint == 0 ? 1 : 0;
}

int main()
{
    int K, V, E;
    scanf("%d\n", &K);

    for (int k = 0; k < K; k++)
    {
        scanf("%d %d\n", &V, &E);
        Graph g(V);

        for (int e = 0; e < E; e++)
        {
            int u, v;
            scanf("%d %d\n", &u, &v);
            g.AddEdge(u, v);
        }
        g.Paint();
    }

    return 0;
}
