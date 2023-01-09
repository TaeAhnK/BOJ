// Make a heap with a new type of standard (abs).

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class absHeap {
    private:
        int length;                     // Total Length of Heap
        int curLength;                  // Current Length of Heap
        int* heap;                      // Heap
        bool isSmaller(int a, int b);   // Check if a's abs is smaller than b
    public:
        absHeap(int length);            // Init
        ~absHeap();                     // Destructor
        void insert(int x);             // Insert x into heap
        int pop();                      // Pop smallest value in the heap
        void print();                   // Print for Debugging
};

absHeap::absHeap(int length) {
    this->length = length;
    this->heap = new int[length + 1];
    this->curLength = 0;
    return;
};

absHeap::~absHeap() {
    delete[] heap;

    return;
};

bool absHeap::isSmaller(int a, int b) {
    if (abs(a) < abs(b)) {
        return true;
    }
    if (abs(a) == abs(b) && a < b) {
        return true;
    }

    return false;
}

void absHeap::insert(int x) {
    int i = ++curLength;
    while ((i != 1) && (isSmaller(x, heap[i/2]))) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = x;
};

int absHeap::pop() {
    if (curLength == 0) {
        return 0;
    }
    else {
        int item = heap[1];
        int temp =  heap[curLength--];
        int temp2;
        int parent = 1;
        int child = 2;

        while(child <= curLength) {
            if ((child < curLength) && isSmaller(heap[child+1], heap[child])) {
                child++;
            }
            if (isSmaller(temp, heap[child])) {
                break;
            }
            temp2 = heap[parent];
            heap[parent] = heap[child];
            heap[child] = temp2;
            parent = child;
            child *= 2;
        }
        heap[parent] = temp;
        return item;
    }
};

void absHeap::print() {
    printf("Length: %d\n", curLength);
    for (int i = 0; i < curLength+5; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return;
};

int main () {
    int N, x;
    scanf("%d\n", &N);
    absHeap h(N);

    for (int i = 0; i < N; i++) {
        scanf("%d\n", &x);
        if (x == 0) {
            printf("%d\n", h.pop());
        }
        else {
            h.insert(x);
        }
    }
    return 0;
}