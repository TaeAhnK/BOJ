// BFS Search *2 and *10+1
// Beware of int length
#include <iostream>
#include <queue>

using namespace std;

class AToB
{
public:
    int MinAToB(unsigned long start, unsigned long goal); // Get min A to B
};

typedef struct numOpCnt // struct for BFS
{
    unsigned long num;
    int opcnt;
} numopcnt;

int AToB::MinAToB(unsigned long start, unsigned long goal)
{
    queue<numopcnt> BFSQueue;

    numopcnt temp;

    temp.num = start;
    temp.opcnt = 0;

    BFSQueue.push(temp);

    while (!BFSQueue.empty())
    {
        temp = BFSQueue.front();
        BFSQueue.pop();

        if (temp.num == goal)
        {
            return temp.opcnt + 1;
        }

        if (temp.num < goal)
        {
            numopcnt tempa;
            numopcnt tempb;

            tempa.num = temp.num * 2;
            tempb.num = temp.num * 10 + 1;
            tempa.opcnt = temp.opcnt + 1;
            tempb.opcnt = temp.opcnt + 1;

            BFSQueue.push(tempa);
            BFSQueue.push(tempb);
        }
    }

    return -1;
}

int main()
{
    AToB A2B;
    unsigned long A, B;

    scanf("%d %d\n", &A, &B);

    printf("%d\n", A2B.MinAToB(A, B));

    return 0;
}