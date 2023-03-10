// Divide the screen into 4 quadrant and check if all part is same
// If all black, print 1, white print 0, if not divide screen into 4 and recursively repeat

#include <iostream>

class Screen
{
    public:
        Screen(int N);      // Init
        ~Screen();          // Destructor
        void printScreen(); // Print compressed screen data
    private:
        void read();                // Read screen data
        int isCompressible(int x1, int x2, int y1, int y2);     // 1 if can be compressed into black, 0 of white, -1 if can't
        void quadrantDivide(int x1, int x2, int y1, int y2);    // Check if compressible, divide into 4 and repeat if cannot
        void printOriginScreen();   // Print for debugging
        bool **originScreen;        // Screen data
        int N;                      // Size of screen
};

Screen::Screen(int N) :
    N(N)
{
    originScreen = new bool* [N];
    for (int i = 0; i < N; i++)
    {
        originScreen[i] = new bool [N];
    }

    read();
    //printOriginScreen();
    return;
};

Screen::~Screen()
{
    for (int i = 0; i < N; i++) {
        delete[] originScreen[i];
    }
    delete[] originScreen;

    return;
};

void Screen::printScreen()
{
    quadrantDivide(0, N, 0, N);
    printf("\n");
};

void Screen::read()
{
    char temp;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            scanf("%c", &temp);
            originScreen[r][c] = (int) (temp - '0');
        }
        scanf("\n");
    }
};

int Screen::isCompressible(int x1, int x2, int y1, int y2)
{
    for (int y = y1; y < y2; y++)
    {
        for (int x = x1; x < x2; x++)
        {
            if (originScreen[y][x] != originScreen[y1][x1])
            {
                return -1;
            }
        }
    }
    return (int) originScreen[y1][x1];
};

void Screen::quadrantDivide(int x1, int x2, int y1, int y2)
{
    switch(isCompressible(x1, x2, y1, y2))
    {
        case 1:
            printf("1");
            return;
        case 0:
            printf("0");
            return;
        case -1:
            break;
        default:
            break;
    }
    printf("(");
    quadrantDivide(x1, x1 + (x2 - x1)/2, y1, y1 + (y2 - y1)/2);
    quadrantDivide(x1 + (x2 - x1)/2, x2, y1, y1 + (y2 - y1)/2);
    quadrantDivide(x1, x1 + (x2 - x1)/2, y1 + (y2 - y1)/2, y2);
    quadrantDivide(x1 + (x2 - x1)/2, x2, y1 + (y2 - y1)/2, y2);
    printf(")");
    return;
};

void Screen::printOriginScreen()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            printf("%d ", originScreen[r][c]);
        }
        printf("\n");
    }
};

int main()
{
    int N;
    scanf("%d\n", &N);
    Screen P(N);
    P.printScreen();

    return 0;
}