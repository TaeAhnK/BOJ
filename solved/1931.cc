// Sort meeting times into ascending order of endtime.
// Select fastest endtimes without overlapping according to greedy algorithm
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Room {
    public:
        Room(int N);                // Init
        ~Room();                    // Destructor
        int greedyMeetingNum();     // Select fastest endtime meetings
    private:
        void read();                // Read data
        bool doesNotOverlap(pair<int, int> a, pair<int, int> b);    // True if two meetings does not overlap
        void printMeetings();       // Print for debugging
        vector<pair<int, int>> meetings;    // Meeting time data
        int meetingNum;             // Number of total meetings
};

bool endTimeIsFaster(pair<int, int> a, pair<int, int> b);   // Compare function of faster endtime for sort

Room::Room(int N) :
    meetingNum(N)
{
    read();
};

Room::~Room()
{
};

int Room::greedyMeetingNum()
{
    int cnt = 1;
    int lastMeeting = 0;

    sort(meetings.begin(), meetings.end(), endTimeIsFaster);

    for (int i = 1; i < meetingNum; i++)
    {
        if (doesNotOverlap(meetings[lastMeeting], meetings[i]))
        {
            cnt++;
            lastMeeting = i;
        }
    }

    return cnt;
};

void Room::read()
{
    int startt, endt;
    for (int i = 0; i < meetingNum; i++)
    {
        scanf("%d %d\n", &startt, &endt);
        meetings.push_back(make_pair(startt, endt));
    }
};

bool Room::doesNotOverlap(pair<int, int> a, pair<int, int> b)
{
    return (a.second <= b.first || a.first >= b.second);
};

void Room::printMeetings()
{
    for (int i = 0; i < meetingNum; i++)
    {
        printf("%d %d\n", meetings[i].first, meetings[i].second);
    }
};

bool endTimeIsFaster(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
};

int main()
{
    int N;
    scanf("%d\n", &N);

    Room R(N);
    printf("%d\n", R.greedyMeetingNum());

    return 0;
}
