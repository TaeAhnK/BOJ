// Store value in both minHeap and maxHeap
// Mark popped data in one side, and pop if the value appears in the other

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class DualPriorityQueue
{
    public:
        DualPriorityQueue();    // Init
        ~DualPriorityQueue();   // Destructor
        void insert(int data);  // Insert data to heaps
        void popMin();          // Pop min value
        void popMax();          // Pop max value
        void printMinMax();     // Print min and max
        void printHeap();       // Print for debugging
    private:
        vector<int> minHeap;    // Min heap
        vector<int> maxHeap;    // Max heap
        map<int, int> mp;       // Map for value check
};

DualPriorityQueue::DualPriorityQueue()
{
}

DualPriorityQueue::~DualPriorityQueue()
{
}

void DualPriorityQueue::insert(int data)
{
    minHeap.push_back(data);
    push_heap(minHeap.begin(), minHeap.end(), greater<>{});
    maxHeap.push_back(data);
    push_heap(maxHeap.begin(), maxHeap.end());
    mp[data]++;
}

void DualPriorityQueue::popMin()
{
    while(!minHeap.empty() && mp[minHeap[0]] == 0)
    {
        pop_heap(minHeap.begin(), minHeap.end(), greater<>{});
        minHeap.pop_back();
    }

    if (!minHeap.empty())
    {
        mp[minHeap[0]]--;
        pop_heap(minHeap.begin(), minHeap.end(), greater<>{});
        minHeap.pop_back();
    }
}

void DualPriorityQueue::popMax()
{
    while(!maxHeap.empty() && mp[maxHeap[0]] == 0)
    {
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
    }

    if (!maxHeap.empty())
    {
        mp[maxHeap[0]]--;
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
    } 
}

void DualPriorityQueue::printMinMax()
{
    while(!minHeap.empty() && mp[minHeap[0]] == 0)
    {
        pop_heap(minHeap.begin(), minHeap.end(), greater<>{});
        minHeap.pop_back();
    }

    while(!maxHeap.empty() && mp[maxHeap[0]] == 0)
    {
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
    }

    if (maxHeap.empty())
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("%d %d\n", maxHeap[0], minHeap[0]);
    }
}

void DualPriorityQueue::printHeap()
{
    printf("\n");
    for (int i = 0; i < minHeap.size(); i++)
    {
        printf("%d ", minHeap[i]);
    }
    printf("\n");

    for (int i = 0; i < maxHeap.size(); i++)
    {
        printf("%d ", maxHeap[i]);
    }
    printf("\n");
    printf("\n");
}

int main()
{
    int T, k, param;
    char cmd;

    scanf("%d\n", &T);
    for (int test = 0; test < T; test++)
    {
        scanf("%d\n", &k);
        DualPriorityQueue Q;
        for (int op = 0; op < k; op++)
        {
            scanf("%c %d\n", &cmd, &param);
            switch (cmd)
            {
                case 'I':
                    Q.insert(param);
                    break;
                case 'D':
                    if (param == 1)
                    {
                        Q.popMax();
                    }
                    else // (param == -1)
                    {
                        Q.popMin();
                    }
                    break;
                
                default:
                    break;
            }
        }
        Q.printMinMax();
    }
}