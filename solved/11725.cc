// Traverse the tree (Graph) with DFS.
// While traversing the tree, record parent node.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class AdjList
{
public:
    AdjList(int size);              // Contructor
    ~AdjList();                     // Destructor
    void InsertNode(int a, int  b); // Insert Node to Graph
    void PrintParent();             // DFS and Print Parent
    void PrintAdj();                // Print for Debugging
private:
    void CalcParentNode();          // DFS and Set parentNode
    int size;                       // Size of Node
    vector<vector<int>> adjlist;    // Tree in Adjlist
    vector<int> parentNode;         // Parent Node Record
};

int main()
{
    int N, tempa, tempb;

    scanf("%d\n", &N);

    AdjList adj(N);

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d\n", &tempa, &tempb);
        adj.InsertNode(tempa, tempb);
    }

    adj.PrintParent();

    return 0;
}

AdjList::AdjList(int size)
{
    this->size = size;
    adjlist = vector<vector<int>>(size + 1);
    parentNode = vector<int>(size + 1);
}

AdjList::~AdjList()
{
}

void AdjList::InsertNode(int a , int b)
{
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
}

void AdjList::PrintParent()
{
    CalcParentNode();

    for (int i = 2; i <= size; i++)
    {
        printf("%d\n", parentNode[i]);
    }
}

void AdjList::PrintAdj()
{
    for (int i = 0; i < adjlist.size(); i++)
    {
        if  (!adjlist[i].empty())
        {
            printf("%d : ", i);
            for (int j = 0; j < adjlist[i].size(); j++)
            {
                printf("%d ", adjlist[i][j]);
            }
            printf("\n");
        }
    }
}

void AdjList::CalcParentNode()
{
    queue<int> q;
    vector<bool> visited(size + 1, false);
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adjlist[node].size(); i++)
        {
            if (visited[adjlist[node][i]] == false)
            {
                visited[adjlist[node][i]] = true;
                q.push(adjlist[node][i]);
                parentNode[adjlist[node][i]] = node;
            }
        }
    }
}
