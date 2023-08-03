// If a digit is different, distnace increase 2. Else, distance is 0
// Select 3 MBTI and calculate distance by comparing per digit.
// If MBTIs are over 32, the distance is 0 by pigeonhole principle

#include <iostream>

class MBTIS
{
    public:
        MBTIS(int N);       // Init
        ~MBTIS();           // Destructor
        int minDistance();  // Min distance
    private:
        int distance(int indexA, int indexB, int indexC); // Distance of indexA, B, and C
        void printMBTIList();   // Print for debugging
        int MBTINum;            // Number of MBTIs given
        char** MBTIList;        // List of MBTIs given

};

MBTIS::MBTIS(int N)
{
    MBTINum = N;
    MBTIList = new char* [N];
    for (int i = 0; i < N; i++)
    {
        MBTIList[i] = new char [4];
        for (int j = 0; j < 4; j++)
        {
            scanf("%c", &MBTIList[i][j]);
        }
        scanf(" ");
    }
    scanf("\n");
    //printMBTIList();
}

MBTIS::~MBTIS()
{
    for (int i = 0; i < MBTINum; i++)
    {
        delete[] MBTIList[i];
    }

    delete[] MBTIList;
}

int MBTIS::minDistance()
{
    int min = 100001;
    int temp;

    if (MBTINum > 32)
    {
        return 0;
    }

    for (int a = 0; a < MBTINum; a++)
    {
        for (int b = a + 1; b < MBTINum; b++)
        {
            for (int c = b + 1; c < MBTINum; c++)
            {
                temp = distance(a, b, c);
                if (temp < min)
                {
                    min = temp;
                }
            }
        }
    }
    
    return min;
}

int MBTIS::distance(int indexA, int indexB, int indexC)
{
    int dist = 0;
    for (int i = 0; i < 4; i++)
    {
        if (MBTIList[indexA][i] == MBTIList[indexB][i] && MBTIList[indexB][i] == MBTIList[indexC][i])
        {
            continue;
        }
        else
        {
            dist += 2;
        }
    }
    return dist;
}

void MBTIS::printMBTIList()
{
    for (int i = 0; i < MBTINum; i++)
    {
        printf("%s\t", MBTIList[i]);
    }
}

int main()
{
    int T, N;
    scanf("%d\n", &T);
    
    for (int t = 0; t < T; t++)
    {
        scanf("%d\n", &N);
        MBTIS M(N);
        printf("%d\n", M.minDistance());
    }
    return 0;
}
