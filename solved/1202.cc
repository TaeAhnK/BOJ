#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Jwl
{
    long long int M;
    long long int V;
} Jwl;

struct Cmp
{
    bool operator()(const Jwl& a, const Jwl& b) const
    {
        return a.M < b.M;
    }
};

struct CmpV
{
    bool operator()(const Jwl& a, const Jwl& b) const
    {
        return a.V < b.V;
    }
};

void answer(int N, int K, vector<int> Bags, vector<Jwl> Jwls)
{
    priority_queue<Jwl, vector<Jwl>, CmpV> pq;
    int index = 0;
    long long valueSum = 0;
    
    sort(Bags.begin(), Bags.end());
    sort(Jwls.begin(), Jwls.end(), Cmp());

    for (int i = 0; i < Bags.size(); i++)
    {
        for (; index < Jwls.size(); index++)
        {
            if (Jwls[index].M <= Bags[i])
            {
                pq.push(Jwls[index]);
            }
            else
            {
                break;
            }
        }

        if (!pq.empty())
        {
            valueSum += pq.top().V;
            pq.pop();
        }
    }

    printf("%lld\n", valueSum);
}


int main()
{
    int N, K, tempM, tempV, tempB;
    vector<int> Bags;
    vector<Jwl> Jwls;

    scanf("%d %d\n", &N, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld\n", &tempM, &tempV);
        Jwls.push_back({tempM, tempV});
    }

    for (int i = 0; i < K; i++)
    {
        scanf("%d\n", &tempB);
        Bags.push_back(tempB);
    }

    answer(N, K, Bags, Jwls);

    return 0;
}