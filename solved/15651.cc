#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
vector<bool> used;
vector<int> st;
int NN, MM;

void DFS(int i)
{
    st.push_back(i);

    if (st.size() < MM)
    {
        for (int i = 1; i <= NN; i++)
        {
            DFS(i);
        }
    }
    else
    {
        for (int i : st) printf("%d ", i);
        printf("\n");
    }

    st.pop_back();
}


void answer(int N, int M)
{
    NN = N;
    MM = M;

    for (int i = 1; i <= N; i++)
    {
        DFS(i);
    }
}

int main()
{
    int N, M;

    scanf("%d %d\n", &N, &M);

    answer(N, M);

    return 0;
}