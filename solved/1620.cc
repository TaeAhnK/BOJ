// Create 2 input-length arrays that store pokemon as pointer.
// Basically you have pokemon datatype dynamically allocated, and IndexHash/NameHash points the data in their own order
// IndexHash stores pokemon data in IndexHash[index], so you can search by index using IndexHash[index] in O(n)
// NameHash also stores pokemon in input order, and Merge Sort(O(nlogn)) in alphabetical order
// When you search with name, you search using binary search(O(logn)) on sorted array

#include <iostream>
#include <string>

using namespace std;

typedef struct pokemon {
    string name;    // Pokemon Name
    int index;      // Pokemon Index (input order)
    int nameIndex;  // Pokemon Index (alphabetical order)
} pokemon;

class Hash {
    private:
        pokemon** IndexHash;    // Stores in Input Order
        pokemon** NameHash;     // Stores in Alphabetical Order
        pokemon** sorted;       // For Merge Sorting NameHash (Better to use Pointer in Merge Sort but lack of time...)
        int dexNum;             // Length of Pokedex
    public:
        Hash(int N);    // Init
        ~Hash();        // Destructor
        void insert(string name, int index);        // Insert into Pokedex
        void alignNameHash();                       // Sort NameHash
        void mergeSort(int start, int end);         // Merge Sort (Better to use Inheritance)
        void merge(int start, int mid, int end);    // Merge Sort (merge)
        void search(string input);                  // Check Input Type and Search
        void searchByName(string name);             // Binary Search Name (Better to use Inheritance)
        void searchByIndex(int index);              // Search Index
        void printByName();                         // Print for Debugging
        void printByIndex();                        // Print for Debugging
};

Hash::Hash(int N) {
    IndexHash = new pokemon*[N];
    NameHash = new pokemon*[N];
    dexNum = N;
};

Hash::~Hash() {
    delete[] IndexHash;
    delete[] NameHash;
};

void Hash::insert(string name, int index) {
    pokemon* newNode = new pokemon;
    newNode->index = index;
    newNode->name = name;

    IndexHash[index] = newNode;
    NameHash[index] = newNode;
};

void Hash::alignNameHash() {
    sorted = new pokemon*[dexNum];
    sorted[0] = NameHash[0];
    mergeSort(0, dexNum-1);
};

void Hash::mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
};

void Hash::merge(int start, int mid, int end) {
    int i = start;
    int j = mid+1;
    int k = start;

    while (i <= mid && j <= end) {
        if (NameHash[i]->name.compare(NameHash[j]->name) < 1) {
            sorted[k++] = NameHash[i++];
        }
        else {
            sorted[k++] = NameHash[j++];
        }
    }

    if (i > mid) {
        while (j <= end) {
            sorted[k++] = NameHash[j++];
        }
    }
    else {
        while (i <= mid) {
            sorted[k++] = NameHash[i++];
        }
    }

    for (int ii = start; ii <= end; ii++) {
        NameHash[ii] = sorted[ii];
    }
};

void Hash::search(string input) {
    if ((int) (input[0]) < 65) {
        searchByIndex(atoi(input.c_str()));
    }
    else {
        searchByName(input);
    }
};

void Hash::searchByName(string name) {
    int low = 0;
    int high = dexNum - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (NameHash[mid]->name == name){
            cout<<(NameHash[mid]->index) + 1<<'\n';
            return;
        }
        else if (NameHash[mid]->name.compare(name) > -1){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }


    return;
};

void Hash::searchByIndex(int index) {
    cout<<IndexHash[index-1]->name<<'\n';
    return;
};

void Hash::printByIndex() {
    for (int i = 0; i < dexNum; i++) {
        cout<<i<<' '<<IndexHash[i]->name<<'\n';
    }
};

void Hash::printByName() {
    for (int i = 0; i < dexNum; i++) {
        cout<<i<<' '<<NameHash[i]->name<<'\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    string temp;

    cin>>N>>M;
    Hash H(N);

    for (int i = 0; i < N; i++) {
        cin>>temp;
        H.insert(temp, i);
    }
    H.alignNameHash();

    for (int i = 0; i < M; i++) {
        cin>>temp;
        H.search(temp);
    }

    return 0;
}