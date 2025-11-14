#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void DFS(int i, int L, int C, const vector<char>& list, vector<int>& stack)
{
    stack.push_back(i);

    if (stack.size() < L)
    {
        for (int ii = i + 1; ii < C; ii++)
        {
            DFS(ii, L, C, list, stack);
        }
    }
    else
    {
        int aeiou = 0;
        int bcdf = 0;

        for (int ii = 0; ii < L; ii++)
        {
            if (list[stack[ii]] == 'a' || list[stack[ii]] == 'e' || list[stack[ii]] == 'i' || 
                list[stack[ii]] == 'o' || list[stack[ii]] == 'u')
                aeiou++;
            else
                bcdf++;
        }

        if (aeiou >= 1 && bcdf >= 2)
        {
            for (int ii = 0; ii < L; ii++)
            {
                printf("%c", list[stack[ii]]);
            }
            printf("\n");
        }
    }

    stack.pop_back();
}


void answer(int L, int C, vector<char> list)
{
    vector<int> stack;

    sort(list.begin(), list.end());

    for (int i = 0; i < C; i++)
    {
        DFS(i, L, C, list, stack);
    }
}

int main()
{
    int L, C;
    vector<char> list;

    scanf("%d %d\n", &L, &C);

    list = vector<char>(C);

    for (int i = 0; i < C; i++)
    {
        scanf("%c ", &list[i]);
    }


    answer(L, C, list);

    return 0;
}