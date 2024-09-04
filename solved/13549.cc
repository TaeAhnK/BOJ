// BFS from N to K
// Search range = 0 ~ 300001 (larger than 100000)
// N can be bigger than K
// First BFS in is not always shortest
// Need to check for remaining queue for the case

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct LocaTime
{
    int location;
    int time;
} LT;

class SBKJ
{
public:
    int MinSearchTime(int N, int);

private:
    vector<int> visited; // Renew value when shorter time has visited
};

int SBKJ::MinSearchTime(int N, int K)
{
    int cnt = 0;
    queue<LT> BFSQueue;
    visited = vector<int>(300001, 300001);

    BFSQueue.push({N, 0});

    while (!BFSQueue.empty())
    {
        cnt++;
        LT temp = BFSQueue.front();
        BFSQueue.pop();

        visited[temp.location] = temp.time;

        if (temp.location == K)
        {
            int ans = temp.time;
            while (!BFSQueue.empty())
            {
                if (BFSQueue.front().location == K)
                {
                    ans = min(ans, BFSQueue.front().time);
                }
                BFSQueue.pop();
            }

            return ans;
        }

        if (temp.location * 2 < 300000 && visited[temp.location * 2] > temp.time)
        {
            BFSQueue.push({temp.location * 2, temp.time});
        }

        if (temp.location + 1 < 300000 && visited[temp.location + 1] > temp.time + 1)
        {
            BFSQueue.push({temp.location + 1, temp.time + 1});
        }

        if (temp.location - 1 < 300000 && visited[temp.location - 1] > temp.time + 1)
        {
            BFSQueue.push({temp.location - 1, temp.time + 1});
        }
    }

    return -1;
}

int main()
{
    SBKJ sbkj;
    int N, K;

    scanf("%d %d\n", &N, &K);

    printf("%d\n", sbkj.MinSearchTime(N, K));

    return 0;
}