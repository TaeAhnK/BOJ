// Basic Minimum Heap using array

#include <iostream>

using namespace std;

class minHeap {
    private:
        int* heap;                  // Heap (array)
        int elementNum;             // Number of Inputs
    public:
        minHeap(int N);             // Init
        ~minHeap();                 // Destuctor
        void insert(int x);         // Insert
        int pop();                  // Pop Root of Heap and return the popped
        void print();               // Print for Debugging
};

minHeap::minHeap(int N) {
    heap = new int[N+1];
    elementNum = 0;

    return;
};

minHeap::~minHeap() {
    delete[] heap;
};

void minHeap::insert(int x) {
    int i = ++elementNum;
    while ((i != 1) && (x < heap[i/2])) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = x;
};

int minHeap::pop() {
    if (elementNum == 0) {
        return 0;
    }
    else{
        int item = heap[1];
        int temp =  heap[elementNum--];
        int parent = 1;
        int child = 2;

        while(child <= elementNum) {
            if ((child < elementNum) && (heap[child] > heap[child+1])) {
                child++;
            }
            if (temp <= heap[child]) {
                break;
            }
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = temp;
        return item;
    }
};

void minHeap::print() {
    printf("\n");
    for (int i = 0; i < elementNum+1; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return;
};

int main() {
    int N, input;

    scanf("%d\n", &N);
    minHeap H(N);

    for (int i = 0; i < N; i++) {
        scanf("%d\n", &input);
        if (input == 0) {           // Pop on 0
            printf("%d\n", H.pop());
        }
        else {                      // Insert on others
            H.insert(input);
        }
    }

    return 0;
}