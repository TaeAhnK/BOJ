#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> list;
vector<bool> used;
vector<int> st;
int NN, MM;

void DFS(int i)
{
    used[i] = true;
    st.push_back(i);

    if (st.size() < MM)
    {
        for (int i = 1; i <= NN; i++)
        {
            if (!used[i]) DFS(i);
        }
    }
    else
    {
        for (int i : st) printf("%d ", i);
        printf("\n");
    }

    st.pop_back();
    used[i] = false;
}


void answer(int N, int M)
{
    NN = N;
    MM = M;
    list = vector<int>(N + 1);
    used = vector<bool>(N + 1);

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