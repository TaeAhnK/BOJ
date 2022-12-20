// Store Values in a node, and make 2 Pointer Array points the nodes in original and sorted order
// Value contains the index of the node in 2 different arrays
// After getting original index, merge sort the nodes. Then calculate sorted order.

#include <iostream>

using namespace std;

typedef struct node {   // node for input
    int value;
    int orgIndex;       // input order
    int sortedIndex;    // sorted order
} node;

class CorCom {
    private:
        int N;          // Length of input
        node** array;   // Array for Merge Sorted Value
        node** arraycp; // Array for Original Value
        node** sorted;  // Memory for merge sort
        void mergeSort(int start, int end);         // Merge Sort
        void merge(int start, int mid, int end);    // Merge for Merge Sort
    public:
        CorCom(int N);                      // Init
        ~CorCom();                          // Destructor
        void Insert(int input, int index);  // Insert values to array
        void Sort();                        // Sort the array
        void Print();                       // Print answer
};

CorCom::CorCom(int N) {
    this->N = N;
    array = new node*[N];
    arraycp = new node*[N];
    sorted = new node*[N];
};

CorCom::~CorCom() {

};

void CorCom::Insert(int input, int index) {
    node* temp = new node;

    temp->value = input;
    temp->orgIndex = index;

    array[index] = temp;
    arraycp[index] = temp;
    
    return;
};

void CorCom::Sort() {
    int index = 0;
    mergeSort(0, N-1);
    for (int i = 0; i < N; i++) {
        if (0 < i && (array[i-1])->value == (array[i])->value) {
            index--;
        }
        array[i]->sortedIndex = index++;
    }
}

void CorCom::mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
};

void CorCom::merge(int start, int mid, int end) {
    int i = start;
    int j = mid+1;
    int k = start;

    while (i <= mid && j <= end) {
        if (array[i]->value <= array[j]->value) {
            sorted[k++] = array[i++];
        }
        else {
            sorted[k++] = array[j++];
        }
    }

    if (i > mid) {
        while (j <= end) {
            sorted[k++] = array[j++];
        }
    }
    else {
        while (i <= mid) {    
            sorted[k++] = array[i++];
        }
    }

    for (int ii = start; ii <= end; ii++) {
        array[ii] = sorted[ii];
    }
};

void CorCom::Print() {
    for (int i = 0; i < N; i++) {
        printf("%d ", arraycp[i]->sortedIndex);
    }
    printf("\n");
};

int main () {
    int N, input;

    scanf("%d", &N);
    CorCom C(N);

    for (int i = 0; i < N; i++) {
        scanf("%d ", &input);
        C.Insert(input, i);
    }

    C.Sort();
    C.Print();
    
    return 0;
}