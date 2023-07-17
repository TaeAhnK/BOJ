// Read all opinions and sort them. Get sum and avg of trimmed avg range

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class BOJLevel
{
    public:
        BOJLevel();         // Init
        ~BOJLevel();        // Destructor
        void read();        // Read opinions
        int level();        // Calculate level
    protected:
    private:
        int opNum;          // The number of opinions
        vector<int> op;     // Opinions
        float trimmedPer;   // Trimmed Average Percentage (30% / 2)
        void print();       // Print for debugging
};

BOJLevel::BOJLevel() :
    trimmedPer(0.15f)
{
};

BOJLevel::~BOJLevel()
{

};

void BOJLevel::read()
{
    int temp;

    scanf("%d\n", &opNum);
    for (int i = 0; i < opNum; i++)
    {
        scanf("%d\n", &temp);
        op.push_back(temp);
    }

    sort(op.begin(), op.end());
    //print();
};

int BOJLevel::level()
{
    if (opNum == 0)
    {
        return 0;
    }

    int notCounted = round(opNum * trimmedPer);
    int sum = 0;
    for (int i = notCounted; i < opNum-notCounted; i++)
    {
        sum += op[i];
    }

    return round( (float) sum / (float) (opNum-(notCounted*2)));
};

void BOJLevel::print()
{
    for (int i = 0; i < opNum; i++)
    {
        printf("%d ", op[i]);
    }
    printf("\n");
};

int main()
{
    BOJLevel BOJQ;
    BOJQ.read();
    printf("%d\n", BOJQ.level());
    return 0;
}
