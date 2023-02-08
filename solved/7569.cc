// Put riped tomotoes in a queue.
// Then, pop the queue, checking adjacent tomatoes as riped and adding them to the queue.
// Riped will keep added and popped until every riped are stored and popped.
// After every riped are popped, check the box for unriped, which is -1 case
// If every tomatoes are riped, print ripeDay of last pop.

#include <iostream>
#include <queue>

using namespace std;

const int dx[6] = {1,-1, 0, 0, 0, 0};   // directions of adj tomatoes
const int dy[6] = {0, 0, 1,-1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1,-1};

typedef struct tomato   // data type for queue
{
    int height;         // z of tomato
    int col;            // y of tomato
    int row;            // x of tomato
    int ripedDay;       // riped date of tomato
} tomato;

class TomatoBox
{
    public:
        TomatoBox(int col, int row, int height);    // Init
        ~TomatoBox();                               // Destuctor
        void print();       // print for debugging
        int ripeAll();      // return days it take to ripe all
    protected:
    private:
        void read();                                        // read box data
        int daysPassed();                                   // put riped into queue and ripe adj tomatoes (BFS)
        void ripeAdj(int h, int r, int c, int ripedDay);    // set tomato in adj to riped
        bool isNotRiped(int h, int r, int c);               // check if tomato is valid and not riped yet
        bool checkAllRiped();                               // check if all tomatoes are riped
        int col;            // col of box
        int row;            // row of box
        int height;         // height of box
        int*** box;         // box
        queue<tomato> q;    // queue for BFS
};

TomatoBox::TomatoBox(int col, int row, int height)
{
    this->col = col;
    this->row = row;
    this->height = height;
    box = new int** [height];
    for (int i = 0; i < height; i++)
    {
        box[i] = new int* [row];
        for (int j = 0; j < row; j++)
        {
            box[i][j] = new int[col];
        }
    }

    read();
    //print(); //dbg

    return;
};

TomatoBox::~TomatoBox()
{
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++) {
            delete[] box[h][r];
        }
        delete[] box[h];
    }
    
    delete[] box;

    return;
};

void TomatoBox::print()
{
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                printf("%d ", box[h][r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return;
};

int TomatoBox::ripeAll()
{
    int ripeEndDay;

    if (checkAllRiped())
    {
        return 0;
    }
    
    ripeEndDay = daysPassed();

    if (checkAllRiped())
    {
        return ripeEndDay;
    }

    return -1;
};

void TomatoBox::read()
{
    int t;

    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                scanf("%d ", &t);
                box[h][r][c] = t;
                if (t == 1)
                {
                    tomato tmt;
                    tmt.col = c;
                    tmt.row = r;
                    tmt.height = h;
                    tmt.ripedDay = 1;
                    q.push(tmt);
                }
            }
        }
    }

    return;
};

int TomatoBox::daysPassed()
{
    tomato tmt;

    while (q.empty() == false) {
        tmt = q.front();
        q.pop();
        ripeAdj(tmt.height, tmt.row, tmt.col, tmt.ripedDay + 1);
    }

    return tmt.ripedDay - 1;
};

void TomatoBox::ripeAdj(int h, int r, int c, int day)
{
    tomato tmt;

    for (int dir = 0; dir < 6; dir++)
    {
        if (isNotRiped(h+dz[dir], r+dy[dir], c+dx[dir]))
        {
            box[ h+dz[dir] ][ r+dy[dir] ][ c+dx[dir] ] = 1;
            tmt.col = c+dx[dir];
            tmt.row = r+dy[dir];
            tmt.height = h+dz[dir];
            tmt.ripedDay = day;
            q.push(tmt);
        }
    }

    return;
};

bool TomatoBox::isNotRiped(int h, int r, int c)
{
    if (h < 0 || r < 0 || c < 0 || height <= h || row <= r || col <= c)
    {
        return false;
    }

    if (box[h][r][c] == 0)
    {
        return true;
    }

    return false;
};

bool TomatoBox::checkAllRiped() {
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (box[h][r][c] == 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
};

int main()
{
    int M, N, H;

    scanf("%d %d %d\n", &M, &N, &H);
    
    TomatoBox T(M, N, H);
    printf("%d\n", T.ripeAll());

    return 0;
}