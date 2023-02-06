// Consider numbers as nodes of a graph.
// If the numbers can be the result of D, S, L, R, connect the numbers
// BFS the graph until you find the shortest path to the input
// While BFS, store the route in BFSTracker to print the shortest path
// If the path is found, track the route and print it

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct trackNode    // To track BFS Shortest Path
{
    int index;  // Former node index
    char cmd;   // Command used on former node
} trackNode;

class Calculator
{
    public:
        Calculator();                   // Init
        ~Calculator();                  // Destructor
        void BFS(int start, int dest);  // BFS
    protected:
    private:
        void connectDSLR(int n, int index, int cmd);    // Connect index - n
        void resetBFSTracker();                         // Reset BFSTracker to -1
        void BFSPrint(int start, int dest);             // Track the shortest path using stack and it
        int D(int n);   // 2*n
        int S(int n);   // n-1
        int L(int n);   // d2 d3 d4 d1
        int R(int n);   // d4 d1 d2 d3
        int d1(int n);  // X in X000
        int d2(int n);  // X in 0X00
        int d3(int n);  // X in 00X0
        int d4(int n);  // X in 000X

        trackNode* BFSTracker;  // Store BFS route
        queue<int> q;           // Queue for print
};

Calculator::Calculator()
{
    BFSTracker = new trackNode [10000];
    resetBFSTracker();
};

Calculator::~Calculator()
{
    delete[] BFSTracker;
};

void Calculator::BFS(int start, int dest)
{
    int popped;
    BFSTracker[start].cmd = 0;
    q.push(start);

    while (!q.empty())
    {
        popped = q.front();
        q.pop();

        if (popped == dest)
        {
            BFSPrint(start, dest);
            return;
        }
        connectDSLR(D(popped), popped, 'D');
        connectDSLR(S(popped), popped, 'S');
        connectDSLR(L(popped), popped, 'L');
        connectDSLR(R(popped), popped, 'R');   
    }
};

void Calculator::resetBFSTracker()
{
    for (int i = 0; i < 10000; i++)
    {
        BFSTracker[i].cmd = '\0';
        BFSTracker[i].index = -1;
    }

    return;
};

void Calculator::connectDSLR(int n, int index, int cmd)
{
    if (BFSTracker[n].index == -1)
    {
        BFSTracker[n].index = index;
        BFSTracker[n].cmd = cmd;
        q.push(n);
    }

    return;
};

void Calculator::BFSPrint(int start, int dest)
{
    stack<char> s;

    for (int tracker = dest; tracker != start; tracker = BFSTracker[tracker].index)
    {
        s.push(BFSTracker[tracker].cmd);
    }

    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");
    return;
};

int Calculator::D(int n)
{
    return (n * 2) % 10000;
};

int Calculator::S(int n)
{
    return (n + 9999) % 10000;
};

int Calculator::L(int n)
{
    return (d2(n)* 1000) + (d3(n)* 100) +(d4(n)* 10) + (d1(n)) ;
};

int Calculator::R(int n)
{
    return (d4(n)* 1000) + (d1(n)* 100) +(d2(n)* 10) + (d3(n)) ;
};

int Calculator::d1(int n)
{
    return n / 1000;
};

int Calculator::d2(int n)
{
    return (n % 1000) / 100;
};

int Calculator::d3(int n)
{
    return (n % 100) / 10;
};

int Calculator::d4(int n)
{
    return (n % 10);
};

int main()
{
    int T, start, dest;
    scanf("%d\n", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &start, &dest);
        Calculator c;
        c.BFS(start, dest);
    }

    return 0;
}