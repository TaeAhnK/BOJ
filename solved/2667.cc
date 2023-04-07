// Consider complex as a graph. Count the number of graphs in the map using DFS
// Count the depth of DFS and push it to a vector to remember the house numbers
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[4] = {-1,  0, 0, 1};   // Directions
const int dy[4] = { 0, -1, 1, 0};

class Complex
{
    public:
        Complex(int N);         // Init       
        ~Complex();             // Destructor
        int countGraphs();      // Count the number of graphs
        void printHouseNums();  // Sort the house numbers and print
    private:
        void readMap();         // Read data
        int graphIndex(int x, int y);       // Returns index of graph of map(x, y)
        bool isValidIndex(int x, int y);    // True if (x, y) is valid location
        void connectAdjlist();              // Create Adjacent List
        void DFS(int start);                // Depth First Search of connected graph
        void printAdjList();                // Print for debugging
        vector<int> Map;                // Map data
        vector<vector<int>> adjList;    // Adjlist of Map 
        vector<int> houseNums;          // houseNumbers of a Complex
        int size;       // Size of col(=row) of map
        int houseNum;   // HouseNumber count
        bool* visited;  // Visited for DFS
};

Complex::Complex(int N) :
    Map(N*N),
    adjList(N*N, vector<int>()),
    size(N),
    houseNum(0)
{
    visited = new bool [N*N];
    memset(visited, 0, sizeof(bool)*N*N);
    readMap();
}

Complex::~Complex()
{
    delete[] visited;
}

void Complex::readMap()
{
    char temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%c", &temp);
            Map[graphIndex(j, i)] = (int) (temp - '0');
        }
        scanf("\n");
    }
    connectAdjlist();
}

int Complex::graphIndex(int x, int y)
{
    return y * size + x;
}

bool Complex::isValidIndex(int x, int y)
{
    return !(x < 0 || y < 0 || size <= x || size <= y);
}

void Complex::connectAdjlist()
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (Map[graphIndex(x, y)] == 1)
            {
                for (int d = 0; d < 4; d++)
                {
                    if (isValidIndex(x+dx[d], y+dy[d]) && Map[graphIndex(x+dx[d], y+dy[d])] == 1)
                    {
                        adjList[graphIndex(x, y)].push_back(graphIndex(x+dx[d], y+dy[d]));
                    } 
                }
            }
        }
    }

}

int Complex::countGraphs()
{
    int cnt = 0;

    for (int i = 0; i < size*size; i++)
    {
        if (!visited[i] && Map[i] == 1)
        {
            DFS(i);
            cnt++;
            houseNums.push_back(houseNum);
            houseNum = 0;
        }
    }
    return cnt;
}

void Complex::printHouseNums()
{
    sort(houseNums.begin(), houseNums.end());
    for (int i = 0; i < houseNums.size(); i++)
    {
        printf("%d\n", houseNums[i]);
    }
}

void Complex::DFS(int start)
{
    houseNum++;
    visited[start] = true;
    for (int i = 0; i < adjList[start].size(); i++)
    {
        if (visited[adjList[start][i]] == false)
        {
            DFS(adjList[start][i]);
        }
    }

}

void Complex::printAdjList()
{
    for (int i = 0; i < size * size; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < adjList[i].size(); j++)
        {
            printf("%d ", adjList[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int N;
    scanf("%d\n", &N);
    Complex C(N);
    printf("%d\n", C.countGraphs());
    C.printHouseNums();
    return 0;
}