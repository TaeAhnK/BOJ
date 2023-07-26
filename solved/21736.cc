// BFS Search for every person connected and count

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 0, 1};      // Direction left, right, up, down
int dy[4] = {0, 1, -1, 0};

typedef struct XY                   // Index x, y
{
    int x;
    int y;
} XY;

class Campus
{
    public:
        Campus();               // Init
        ~Campus();              // Destructor
        void read();            // Read Data
        void printFriendNum();  // Calc the number of friends and print
    private:
        int col;                // Col of Campus
        int row;                // Row of Campus
        XY Doyeon;              // Location of Doyeon
        char **map;             // Map data
        bool **isVisited;       // Visited location for BFS
        int BFSFriend();        // BFS search for friends
        bool isValid(XY index); // Check whether the index is valid
        XY indexToXY(int x, int y); // Convert x, y location to XY
        void printMap();            // Print for Debugging
        void printVisited();        // Print for Debugging
};

Campus::Campus()
{
}

Campus::~Campus()
{
    for (int r = 0; r < row; r++)
    {
        delete[] map[r];
        delete[] isVisited[r];
    }
    delete[] map;
    delete[] isVisited;
}

void Campus::read()
{
    scanf("%d %d\n", &row, &col);
    
    map = new char* [row];
    isVisited = new bool* [row];
    for (int r = 0; r < row; r++)
    {
        map[r] = new char [col];
        isVisited[r] = new bool [col];

        for (int c = 0; c < col; c++)
        {
            scanf("%c", &(map[r][c]));
            if (map[r][c] == 'I')
            {
                Doyeon.x = c;
                Doyeon.y = r;
            }
        }
        scanf("\n");
        memset(isVisited[r], 0, sizeof(bool) * col);
    }

    //printMap();
    //printVisited();
}

void Campus::printFriendNum()
{
    int num = BFSFriend();

    if (num == 0)
    {
        printf("TT\n");
    }
    else
    {
        printf("%d\n", num);
    }
}

int Campus::BFSFriend()
{
    queue<XY> q;
    int friendNum = 0;
    XY popped;
    XY temp;

    q.push(Doyeon);
    isVisited[Doyeon.y][Doyeon.x] = true;

    while (!q.empty())
    {
        popped = q.front();
        q.pop();

        if (map[popped.y][popped.x] == 'P')
        {
            friendNum++;
        }

        for (int i = 0; i < 4; i++)
        {
            temp = indexToXY(popped.x + dx[i], popped.y + dy[i]);
            if (isValid(temp))
            {
                q.push(temp);
                isVisited[temp.y][temp.x] = true;
            }
        }
    }

    return friendNum;
}

bool Campus::isValid(XY index)
{
    if (index.x < 0 || col <= index.x || index.y < 0 || row <= index.y)
    {
        return false;
    }

    else if (map[index.y][index.x] == 'X' || isVisited[index.y][index.x])
    {
        return false;
    }

    return true;
}

XY Campus::indexToXY(int x, int y)
{
    XY temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

void Campus::printMap()
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            printf("%c", map[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void Campus::printVisited()
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            printf("%d", (int) isVisited[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    Campus c;
    c.read();
    c.printFriendNum();

    return 0;
}