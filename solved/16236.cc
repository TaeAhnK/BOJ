// Find closest fish using special BFS.
// Eat the fish and repeat eating until the shark cannot eat.
// Count the path length and print.

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[4] = {0, -1, 1, 0};    // Direction
const int dy[4] = {-1, 0, 0, 1};

typedef struct XY   // XY to store x and y location of fish or shark
{
    int x;
    int y;
} XY;

class fishtank
{
    public:
        fishtank(int N);                // Init
        ~fishtank();                    // Destructor
        int hunt();                     // Hunt all fish possible and return path length
    private:
        void read();                    // Read map data
        int shortestPath(XY start);     // Find closest fish and the path length using BFS
        bool isValidXY(int x, int y);   // True if (x, y) is valid location of the map
        void initDist();                // Init distance data for BFS
        void printmap();                // Print for debugging map
        void printdist();               // Print for debugging distance
        int** map;                      // Map of fishtank
        int** dist;                     // Distance data for BFS
        int tankSize;                   // Col(=row) of fishtank
        XY sharkXY;                     // Location of the shark
        int sharkSize;                  // Size of the shark
        int sharkGauge;                 // Growth gauge of the shark
};

bool xyComp(XY a, XY b)     // Compare function for BFS order
{
    if (a.y > b.y)
    {
        return true;
    }
    else if (a.y < b.y)
    {
        return false;
    }
    else
    {
        if (a.x > b.x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

fishtank::fishtank(int N) :
    tankSize(N),
    sharkSize(2),
    sharkGauge(0)
{
    map = new int* [N];
    for (int i = 0; i < N; i++)
    {
        map[i] = new int [N];
    }
    
    dist = new int* [tankSize];
    for (int i = 0; i < tankSize; i++)
    {
        dist[i] = new int [tankSize];
    }

    read();
}

fishtank::~fishtank()
{
    for (int i = 0; i < tankSize; i++)
    {
        delete[] map[i];
        delete[] dist[i];
    }
    delete[] map;
    delete[] dist;
}

int fishtank::hunt()
{
    int Path = 0;
    while(1)
    {
        int temp = shortestPath(sharkXY);
        if (temp == -1)
        {
            break;
        }
        else
        {
            Path += temp;
        }
    }
    return Path;
}

void fishtank::read()
{
    for (int row = 0; row < tankSize; row++)
    {
        for (int col = 0; col < tankSize; col++)
        {
            scanf("%d ", &(map[row][col]));
            if (map[row][col] == 9)
            {
                sharkXY.x = col;
                sharkXY.y = row;
                map[row][col] = 0;
            }
        }
        scanf("\n");
    }
}

int fishtank::shortestPath(XY start)
{
    XY popped;
    int queueSize = 1;
    vector<vector<XY>> q(tankSize*tankSize, vector<XY>());
    
    initDist();
    q[0].push_back({start.x, start.y});
    dist[start.y][start.x] = 0;

    for (int i = 0 ; i < tankSize * tankSize; i++)
    {
        sort(q[i].begin(), q[i].end(), xyComp);
        while(q[i].size())
        {
            popped = q[i].back();
            q[i].pop_back();
            if (0 < map[popped.y][popped.x] && map[popped.y][popped.x] < sharkSize)
            {
                sharkXY.x = popped.x;
                sharkXY.y = popped.y;
                map[sharkXY.y][sharkXY.x] = 0;
                sharkGauge++;
                if (sharkGauge >= sharkSize)
                {
                    sharkGauge = 0;
                    sharkSize++;
                }
                //printf("(%d %d)->\n", sharkXY.x, sharkXY.y);
                //printdist();
                return dist[popped.y][popped.x];
            }
            for (int d = 0; d < 4; d++)
            {
                if (isValidXY(popped.x + dx[d], popped.y + dy[d]) && dist[popped.y + dy[d]][popped.x + dx[d]] == -1 && map[popped.y + dy[d]][popped.x + dx[d]] <= sharkSize)
                {
                    dist[popped.y + dy[d]][popped.x + dx[d]] = dist[popped.y][popped.x] + 1;
                    q[dist[popped.y + dy[d]][popped.x + dx[d]]].push_back({popped.x + dx[d], popped.y + dy[d]});
                }
            }
        }
    }
    return -1;
}

bool fishtank::isValidXY(int x, int y)
{
    return !(x < 0 || y < 0 || tankSize <= x || tankSize <= y);
}

void fishtank::initDist()
{
    for (int i = 0; i < tankSize; i++)
    {
        memset(dist[i], -1, sizeof(int) * tankSize);
    }
}

void fishtank::printmap()
{
    for (int y = 0; y < tankSize; y++)
    {
        for (int x = 0; x < tankSize; x++)
        {
            printf("%d\t", map[y][x]);    
        }
        printf("\n");   
    }
    printf("\n");
}

void fishtank::printdist()
{
    for (int y = 0; y < tankSize; y++)
    {
        for (int x = 0; x < tankSize; x++)
        {
            printf("%d\t", dist[y][x]);    
        }
        printf("\n");   
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d\n", &N);
    fishtank F(N);
    printf("%d\n", F.hunt());
}