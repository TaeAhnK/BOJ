// BFS Subin's sister.
// Pop queue, and add location+1,-1,*2 to queue
// Keep popping and adding the location Subin can visit until she find her sister.

#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
    int target;     // Location of Subin
    int depth;      // how many movement Subin made
} node;

class HideSeek {
    private:
        bool visited[100001] = {false};         // Check Visited
        queue<node> q;                          // Queue for BFS
    public:
        HideSeek();
        ~HideSeek();
        void BFS(int N, int K);                 // BFS
        void BFSSearch(int target, int depth);  // Check target, add target+1,-1,*2 to queue
};

HideSeek::HideSeek() {

};

HideSeek::~HideSeek() {

};

void HideSeek::BFS(int N, int K) {
    node temp, popped;
    temp.target = N;
    temp.depth = 0;

    q.push(temp);

    while(q.empty() == false) {
        popped = q.front();
        if (popped.target == K) {
            printf("%d\n", popped.depth);
            return;
        }
        q.pop();
        BFSSearch(popped.target, popped.depth);
    }
};

void HideSeek::BFSSearch (int target, int depth) {
    visited[target] = true;
    if (0 <= target - 1 && target - 1 <= 100000 && visited[target-1] == false) {
        node temp1;
        temp1.target = target - 1;
        temp1.depth = depth + 1;
        q.push(temp1);
    }

    if (0 <= target + 1 && target + 1 <= 100000 && visited[target+1] == false) {
        node temp2;
        temp2.target = target + 1;
        temp2.depth = depth + 1;
        q.push(temp2);
    }

    if (0 <= target * 2 && target * 2 <= 100000 && visited[target*2] == false) {
        node temp3;
        temp3.target = target * 2;
        temp3.depth = depth + 1;
        q.push(temp3);
    }

    return;
};

int main () {
    HideSeek H;
    int N, K;

    scanf("%d %d\n", &N, &K);
    H.BFS(N, K);

    return 0;
}