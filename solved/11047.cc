// Select from biggest coin to 1 according to greedy algorithm

#include <iostream>
#include <vector>

using namespace std;

class coin
{
    public:
        coin();                 // Init
        ~coin();                // Destructor
        int minCoin(int targetMoney);   // Coint coin num with greedy algorithm
    private:
        void readCoinList(int N);       // Read list of coin
        vector<int> coinList;           // List of coin
};

coin::coin()
{
    int N, K;
    scanf("%d %d\n", &N, &K);
    readCoinList(N);
    printf("%d\n", minCoin(K));
}

coin::~coin()
{
}

int coin::minCoin(int targetMoney)
{
    int cnt = 0;
    while (targetMoney > 0)
    {
        if (coinList.back() > targetMoney)
        {
            coinList.pop_back();
        }
        else
        {
            cnt++;
            targetMoney -= coinList.back();
        }
    }
    return cnt;
}

void coin::readCoinList(int N)
{
    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d\n", &temp);
        coinList.push_back(temp);
    }
}

int main()
{
    coin C;

    return 0;
}