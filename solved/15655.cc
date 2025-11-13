#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
vector<bool> used;
vector<int> st;
int N, M;

void DFS(int i)
{
    st.push_back(i);
    used[i] = true;

    if (st.size() < M)
    {
        for (int ii = i; ii < N; ii++)
        {
            if (!used[ii]) DFS(ii);
        }
    }
    else
    {
        for (int i : st) printf("%d ", list[i]);
        printf("\n");
    }

    used[i] = false;
    st.pop_back();
}


void answer()
{
    used = vector<bool>(N, false);
    
    sort(list.begin(), list.end());

    for (int i = 0; i < N; i++)
    {
        DFS(i);
    }
}

int main()
{
    scanf("%d %d\n", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d ", &temp);
        list.push_back(temp);
    }

    answer();

    return 0;
}