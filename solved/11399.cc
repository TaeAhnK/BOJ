// The smallest sum of waiting time is when people are waiting in ascending order
// Sort the waiting time and calculate the sum

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ATM
{
    public:
        ATM(int len);               // Init
        ~ATM();                     // Destructor
        int greedyTimeSum();        // Calculate Min Waiting Time Sum according to greedy algorithm
    private:
        void read();                // Read the waiting time input
        void printWaitingList();    // Print for debugging
        vector<int> waitingList;    // Waiting time of each person
        int peopleNum;              // The number of people
};

ATM::ATM(int len) :
    peopleNum(len)
{
    read();
};

ATM::~ATM()
{
    waitingList.clear();
};

int ATM::greedyTimeSum()
{
    int personWaitingTime = 0;
    int totalWaitingTime = 0;
    sort(waitingList.begin(), waitingList.end());

    for (int i = 0; i < peopleNum; i++)
    {
        personWaitingTime += waitingList[i];
        totalWaitingTime += personWaitingTime;
    }

    return totalWaitingTime;
};

void ATM::read()
{
    int temp;
    for (int i = 0; i < peopleNum; i++)
    {
        scanf("%d ", &temp);
        waitingList.push_back(temp);
    }
};

void ATM::printWaitingList()
{
    vector<int>::iterator iter;
    for(iter = waitingList.begin(); iter!= waitingList.end(); iter++)
    {
        printf("%d ", *iter);
    }
    printf("\n");
};

int main()
{
    int N;
    scanf("%d\n", &N);
    ATM a(N);
    printf("%d\n", a.greedyTimeSum());
    
    return 0;
}