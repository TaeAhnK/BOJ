// Check if you can use the paper. If can't, divide paper into 4 and recursively
// repeat the check and divide.

#include <iostream>

class paper
{
    public:
        paper(int N);           // Init
        ~paper();               // Destructor
        void printPaperNum();   // Count white/blue paper and print result
    private:
        void read();        // Read data
        int isUsable(int x1, int x2, int y1, int y2);           // 1 if the area is all blue, 0 if white, -1 if cannot use
        void quadrantDivide(int x1, int x2, int y1, int y2);    // If cannot use as paper, divide paper into 4 and recursively repeat
        void printOriginPaper();                                // Print for debugging
        bool **originPaper; // Original Paper
        int N;              // Size of paper
        int blue;           // Number of blue paper
        int white;          // Number of white paper
};

paper::paper(int N) :
    N(N),
    blue(0),
    white(0)
{
    originPaper = new bool* [N];
    for (int i = 0; i < N; i++)
    {
        originPaper[i] = new bool [N];
    }

    read();
    return;
};

paper::~paper()
{
    for (int i = 0; i < N; i++) {
        delete[] originPaper[i];
    }
    delete[] originPaper;

    return;
};

void paper::printPaperNum()
{
    quadrantDivide(0, N, 0, N);
    printf("%d\n%d\n", white, blue);
};

void paper::read()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            scanf("%d ", &originPaper[r][c]);
        }
        scanf("\n");
    }
};

int paper::isUsable(int x1, int x2, int y1, int y2)
{
    for (int y = y1; y < y2; y++)
    {
        for (int x = x1; x < x2; x++)
        {
            if (originPaper[y][x] != originPaper[y1][x1])
            {
                return -1;
            }
        }
    }
    return (int) originPaper[y1][x1];
};

void paper::quadrantDivide(int x1, int x2, int y1, int y2)
{
    switch(isUsable(x1, x2, y1, y2))
    {
        case 1:
            blue++;
            return;
        case 0:
            white++;
            return;
        case -1:
            break;
        default:
            break;
    }

    quadrantDivide(x1, x1 + (x2 - x1)/2, y1, y1 + (y2 - y1)/2);
    quadrantDivide(x1, x1 + (x2 - x1)/2, y1 + (y2 - y1)/2, y2);
    quadrantDivide(x1 + (x2 - x1)/2, x2, y1, y1 + (y2 - y1)/2);
    quadrantDivide(x1 + (x2 - x1)/2, x2, y1 + (y2 - y1)/2, y2);

    return;
};

void paper::printOriginPaper()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            printf("%d ", originPaper[r][c]);
        }
        printf("\n");
    }
};

int main()
{
    int N;
    scanf("%d\n", &N);
    paper P(N);
    P.printPaperNum();

    return 0;
}