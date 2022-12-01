#include <iostream>

using namespace std;

class Array {
    private:
        int* sorted;    // For Merge Sort (Better to use Pointer)
        int length;     // Length of Array
    public:
        int* array;     // Array
        Array(int N);   // Init
        ~Array();       // Destuctor
        void mergeSort(int start, int end);         // Merge Sort (Better to use Inheritance)
        void merge(int start, int mid, int end);    // Merge Sort (Better to use Inheritance)
        bool binarySearch(int num);                 // Binary Search (Better to use Inheritance)
        void printArray();                          // Print for Debugging
};

Array::Array(int N) {
    array = new int[N];
    sorted = new int[N];
    length = N;
};

Array::~Array() {
    delete[] array;
};

void Array::mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
};

void Array::merge(int start, int mid, int end) {
    int i = start;
    int j = mid+1;
    int k = start;

    while (i <= mid && j <= end) {
        if (array[i] <= array[j]) {
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

bool Array::binarySearch(int num) {
    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (sorted[mid] == num){
            return true;
        }
        else if (sorted[mid] > num){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return false;
};

void Array::printArray() {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main () {
    int N, M, temp;

    scanf("%d", &N);
    Array a(N);
    for (int i = 0; i < N; i++) {
        scanf("%d ", &a.array[i]);
    }
    a.mergeSort(0, N-1);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        printf("%d\n", a.binarySearch(temp));
    }
    
    return 0;
}