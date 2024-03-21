// Think of numbers connected as a graph
// 1 - 2 3 4... N
// 2 - 3 4 5... N
// ...
// N - 
// Then, search for nodes with depth of M with DFS.
// Store the nodes into a stack and print them when it has M elements
#include <iostream>
#include <vector>

class graph
{
public:
    graph(int N, int M);
    void combinations();
private:
    void DFS(int index);
    void createAdjList();
    void printStack();
    void printAdjList();

    int M;
    int N;
    std::vector<std::vector<int>> adjList;
    std::vector<int> stack;
};

graph::graph(int N, int M) : 
    N(N), 
    M(M),
    adjList(N + 1)
{
    createAdjList();
};

void graph::combinations()
{
    DFS(0);
}

void graph::DFS(int index)
{
    for (int i = 0; i < adjList[index].size(); i++)
    {
        stack.push_back(adjList[index][i]);
        if (stack.size() == M)
        {
            printStack();
        }
        else
        {
            DFS(adjList[index][i]);
        }
        stack.pop_back();
    }
}

void graph::createAdjList()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = i + 1; j <= N ; j++)
        {
            adjList[i].push_back(j);
        }
    }
}

void graph::printStack()
{
    for (int i = 0; i < M; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void graph::printAdjList()
{
    for (int i = 0; i < adjList.size(); i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            printf("%d ", adjList[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);

    graph G(N, M);
    G.combinations();

}