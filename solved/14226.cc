#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1050;

typedef struct SC
{
    int S;
    int C;
} XY;

class Graph
{
    public:
    Graph();
    void BFS(int target);
    vector<vector<vector<SC>>> adjlist;
};

Graph::Graph()
{
    adjlist = vector<vector<vector<SC>>>(MAX, vector<vector<SC>>(MAX, vector<SC>()));
    
    for (int s = 0; s < MAX; s++)
    {
        for (int c = 0; c < MAX; c++)
        {
            if (0 <= s && s < MAX) adjlist[s][c].push_back({s, s});
            if (0 <= s+c && s+c < MAX) adjlist[s][c].push_back({s+c, c});
            if (0 <= s-1 && s-1 < MAX) adjlist[s][c].push_back({s-1, c});
        }
    }
}

void Graph::BFS(int target)
{
    queue<SC> q;
    vector<vector<int>> visited(MAX, vector<int>(MAX, -1));

    SC start = {1, 0};

    q.push(start);
    visited[start.S][start.C] = 0;

    while(!q.empty())
    {
        SC current = q.front();
        q.pop();

        if (current.S == target)
        {
            printf("%d\n", visited[current.S][current.C]);
            return;
        }

        for (int i = 0; i < adjlist[current.S][current.C].size(); i++)
        {
            if (visited[adjlist[current.S][current.C][i].S][adjlist[current.S][current.C][i].C] == -1)
            {
                visited[adjlist[current.S][current.C][i].S][adjlist[current.S][current.C][i].C] = visited[current.S][current.C] + 1;
                q.push(adjlist[current.S][current.C][i]);
            }
        }
    }
}


int main()
{
    int S;

    scanf("%d\n", &S);

    Graph emoji;
    emoji.BFS(S);

    return 0;
}