// Put riped tomotoes in a queue.
// Then, pop the queue, checking adjacent tomatoes as riped and adding them to the queue.
// Riped will keep added and popped until every riped are stored and popped.
// After every riped are popped, check the box for unriped, which is and -1 case
// If every tomatoes are riped, print ripeDay of last pop.

#include <iostream>
#include <queue>

using namespace std;

const int dx[8] = {-1, 1,  0, 0};   // Relational (x, y) for checking adjacent tomato
const int dy[8] = { 0, 0, -1, 1};

typedef struct tomato { // Stores location of just-riped tomatoes
    int x;
    int y;
    int ripeDay;
} tomato;

class TomatoBox {
    private:
        int** box;      // Status of Tomato Box
        int row;        // Row of Box
        int col;        // Col of Box
        queue<tomato> tomatoes; // Stores Locations of Tomatoes

    public:
        TomatoBox(int row, int col);                // Init
        ~TomatoBox();                               // Destructor
        void setTomato(int x, int y, int temp);     // Mark Riped/Not Riped/Empty on Box
        int daysPassed();                           // Pop Queue, Marking Adj as Riped.
        void ripeAdj(int x, int y, int ripedDay);   // Change Adjacent Tomatoes into Riped and Add to the Queue
        bool checkAllRiped();                       // Check whether All Tomatoes are Riped
        void printBox();                            // Print Status of Tomato Box
};

TomatoBox::TomatoBox(int row, int col) {
    this->col = col;
    this->row = row;
    box = new int*[row];
    for (int i = 0; i < row; i++) {
        box[i] = new int[col];
    }

    return;
};

TomatoBox::~TomatoBox() {
    for (int i = 0; i < row; i++) {
        delete[] box[i];
    }
    delete[] box;

    return;
};

void TomatoBox::setTomato(int x, int y, int temp) {
    box[x][y] = temp;
    if (temp == 1) {
        tomato tempto;
        tempto.x = x;
        tempto.y = y;
        tempto.ripeDay = 0;
        tomatoes.push(tempto);
    }
    return;
};

int TomatoBox::daysPassed() {
    tomato temp;
    while (tomatoes.empty() == false) {
        temp = tomatoes.front();
        tomatoes.pop();
        ripeAdj(temp.x, temp.y, temp.ripeDay + 1);
    }
    return temp.ripeDay;
};

void TomatoBox::ripeAdj(int x, int y, int ripedDay) {
    tomato temp;
    for (int dir = 0; dir < 4; dir++) {
        if (!(x + dx[dir] < 0 || row <= x + dx[dir] || y + dy[dir] < 0 || col <= y + dy[dir] || box[x + dx[dir]][y + dy[dir]] != 0)) {
            box[x + dx[dir]][y + dy[dir]] = 1;
            temp.x = x + dx[dir];
            temp.y = y + dy[dir];
            temp.ripeDay = ripedDay;
            tomatoes.push(temp);
        }
    }
};

bool TomatoBox::checkAllRiped() {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (box[j][i] == 0) {
                return false;
            }
        }
    }
    return true;
};

void TomatoBox::printBox() {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d\t", box[j][i]);
        }
        printf("\n");
    }
    printf("\n");
};

int main() {
    int M, N, temp, result;

    scanf("%d %d", &M, &N);
    TomatoBox B(M, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &temp);
            B.setTomato(j, i, temp);
        }
    }

    if (B.checkAllRiped() == true) {
        printf("0\n");
        return 0;
    }

    result = B.daysPassed();
    if (B.checkAllRiped() == false) {
        printf("-1\n");
    }
    else {
        printf("%d\n", result);
    }

    return 0;
}