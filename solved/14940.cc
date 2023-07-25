// Use BFS to calculate each node distance

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 0, 1};      // up, down, left, right in map
int dy[4] = {0, 1, -1, 0};

typedef struct XY               // index in map
{
    int x;
    int y;
} XY;

class Map
{
    public:
        Map();                          // Init
        ~Map();                         // Destructor
        void read();                    // Read data
        void printDistance();           // Calculate distance and print
    private:
        void BFS();                     // Caculate distance using BFS
        bool isValid(XY index);         // Check if it is valid x, y location
        XY indexToXY(int x, int y);     // Convert x, y to XY data type
        void printMapData();            // Print for debugging
        void printVisited();            // Print for debugging
        int col;                        // Col of map
        int row;                        // Row of map
        XY startXY;                     // Start index
        int **mapData;                  // Map
        int **distanceData;             // Distance
        bool **isVisited;               // isVisited for BFS
};

Map::Map()
{
}

Map::~Map()
{
    for (int r = 0; r < row; r++)
    {
        delete[] mapData[r];
        delete[] distanceData[r];
        delete[] isVisited[r];
    }

    delete mapData;
    delete distanceData;
    delete isVisited;
}

void Map::read()
{
    scanf("%d %d\n", &row, &col);
    mapData = new int* [row];
    distanceData = new int* [row];
    isVisited = new bool* [row];

    for (int r = 0; r < row; r++)
    {
        mapData[r] = new int [col];
        distanceData[r] = new int [col];
        isVisited[r] = new bool [col];

        memset(distanceData[r], -1, sizeof(int) * col);
        memset(isVisited[r], 0, sizeof(bool) * col);

        for (int c = 0; c < col; c++)
        {
            scanf("%d ", &mapData[r][c]);

            if (mapData[r][c] == 2)
            {
                startXY.x = c;
                startXY.y = r;
            }
            else if (mapData[r][c] == 0)
            {
                distanceData[r][c] = 0;
                isVisited[r][c] = true;
            }
        }
    }
}

void Map::printDistance()
{
    BFS();

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            printf("%d ", distanceData[r][c]);
        }
        printf("\n");
    }
}

void Map::BFS()
{
    queue<XY> q;
    q.push(startXY);
    isVisited[startXY.y][startXY.x] = true;
    distanceData[startXY.y][startXY.x] = 0;

    while(!q.empty())
    {
        XY popped = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            XY near = indexToXY(popped.x + dx[i], popped.y + dy[i]);
            
            if (isValid(near))
            {
                q.push(near);
                isVisited[near.y][near.x] = true;
                distanceData[near.y][near.x] = distanceData[popped.y][popped.x] + 1;
            }
        }
    }
}

bool Map::isValid(XY index)
{
    if (index.x < 0 || col <= index.x || index.y < 0 || row <= index.y)
    {
        return false;
    }

    if (isVisited[index.y][index.x])
    {
        return false;
    }
    
    return true;
}

XY Map::indexToXY(int x, int y)
{
    XY temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

void Map::printMapData()
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            printf("%d ", mapData[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void Map::printVisited()
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            printf("%d ", (int) isVisited[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    Map m;
    m.read();
    m.printDistance();
    return 0;
}