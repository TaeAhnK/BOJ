#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum Direction
{
    Clock,
    CounterClock
};

typedef struct GearDir
{
    int gear;
    Direction dir;
} GearDir;


class Gear
{
public:
    void Init();
    void Rotate(Direction dir);
    void Clockwise();
    void CounterClockwise();
    int TopCog() { return Cog[0]; }
    int LeftCog() { return Cog[6]; }
    int RightCog() { return Cog[2]; }
    int Cog[8];

};

void Gear::Init()
{
    char temp;
    for (int i = 0; i < 8; i++)
    {
        scanf("%c", &temp);
        Cog[i] = temp - '0';
    }
    scanf("\n");
}

void Gear::Rotate(Direction dir)
{
    switch (dir)
    {
    case Direction::Clock:
        Clockwise();
        break;
    case Direction::CounterClock:
        CounterClockwise();
    default:
        break;
    }
}

void Gear::Clockwise()
{
    int temp = Cog[7];

    for (int i = 6; 0 <= i; i--)
    {
        Cog[i + 1] = Cog[i];
    }

    Cog[0] = temp;
}

void Gear::CounterClockwise()
{
    int temp = Cog[0];

    for (int i = 1; i < 8; i++)
    {
        Cog[i - 1] = Cog[i];
    }

    Cog[7] = temp;
}

class Gears
{
public:
    Gears(int N);
    void Rotate(Direction dir, int Gear);
    const Direction OppoDir(Direction dir);
    static const Direction Dir(int dir);
    void PrintS();

    vector<Gear> gears;
private:
    vector<vector<int>> adjlist;
    queue<GearDir> RotateQueue;
    queue<GearDir> SearchQueue;
    vector<bool> visited;
    int N;
};

Gears::Gears(int N) : N(N)
{
    gears = vector<Gear>(N + 1);
    visited = vector<bool>(N+1, false);

    adjlist = vector<vector<int>>(N + 1, vector<int>(2, 0));
    for (int i = 1; i <= N; i++)
    {
        if (i - 1 >= 1) adjlist[i][0] = i - 1;
        if (i + 1 <= N) adjlist[i][1] = i + 1;
        gears[i].Init();
    }
}

void Gears::Rotate(Direction dir, int Gear)
{
    RotateQueue = queue<GearDir>();
    RotateQueue.push({Gear, dir});

    SearchQueue = queue<GearDir>();
    SearchQueue.push({Gear, dir});

    visited.assign(N + 1, false);

    while (!SearchQueue.empty())
    {
        GearDir temp = SearchQueue.front();
        SearchQueue.pop();
        visited[temp.gear] = true;

        if (!visited[adjlist[temp.gear][0]] && 
            gears[temp.gear].LeftCog() != gears[adjlist[temp.gear][0]].RightCog())
        {
            SearchQueue.push({adjlist[temp.gear][0], OppoDir(temp.dir)});
            RotateQueue.push({adjlist[temp.gear][0], OppoDir(temp.dir)});
        }

        if (!visited[adjlist[temp.gear][1]] &&
            gears[temp.gear].RightCog() != gears[adjlist[temp.gear][1]].LeftCog())
        {
            SearchQueue.push({adjlist[temp.gear][1], OppoDir(temp.dir)});
            RotateQueue.push({adjlist[temp.gear][1], OppoDir(temp.dir)});
        }
    }

    while (!RotateQueue.empty())
    {
        GearDir temp = RotateQueue.front();
        RotateQueue.pop();

        gears[temp.gear].Rotate(temp.dir);
    }
}

const Direction Gears::OppoDir(Direction dir)
{
    if (dir == Direction::Clock) return Direction::CounterClock;
    else return Direction::Clock;
}

const Direction Gears::Dir(int dir)
{
    if (dir == 1) return Direction::Clock;
    else return Direction::CounterClock;
}

void Gears::PrintS()
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (gears[i].TopCog() == 1) cnt++;

        // for (int j = 0; j < 8; j++)
        // {
        //     printf("%d", gears[i].Cog[j]);
        // }
        // printf("\n");
    }

    printf("%d\n", cnt);
}

int main()
{
    int T, K, num, dir;

    scanf("%d\n", &T);

    Gears G(T);

    scanf("%d\n", &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d\n", &num, &dir);
        G.Rotate(Gears::Dir(dir), num);
    }

    G.PrintS();

    return 0;
}