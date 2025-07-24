#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 1000001;

class Graph
{
public:
    Graph();
    void BFS(int start, int target);
    vector<vector<int>> adjlist;
};

Graph::Graph()
{
    adjlist.resize(MAX + 1, vector<int>());

    for (int i = 0; i <= MAX; i++)
    {
        if (0 <= i-1 && i-1 <= MAX) adjlist[i].push_back(i-1);
        if (0 <= i+1 && i+1 <= MAX) adjlist[i].push_back(i+1);
        if (0 <= i*2 && i*2 <= MAX) adjlist[i].push_back(i*2);
    }
}

void Graph::BFS(int start, int target)
{
    queue<int> q;
    vector<int> visited(MAX, -1);

    q.push(start);
    visited[start] = start;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        if (target == current)
        {
            stack<int> backtrack;
            
            int temp = current;
            while (temp != start)
            {
                backtrack.push(temp);
                temp = visited[temp];
            }
            backtrack.push(start);
            printf("%d\n", backtrack.size() -1 );

            while(!backtrack.empty())
            {
                printf("%d ", backtrack.top());
                backtrack.pop();
            }
            return;
        }

        for (int i = 0; i < adjlist[current].size(); i++)
        {
            if (visited[adjlist[current][i]] == -1)
            {
                visited[adjlist[current][i]] = current;
                q.push(adjlist[current][i]);
            }
        }
    }
}

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    Graph HnS;
    HnS.BFS(N, K);

    return 0;
}