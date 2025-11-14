#include <iostream>
#include <vector>

using namespace std;

long long minV = 9999999999;
long long maxV = -1;

void DFS(int i, int k, vector<bool>& used, vector<int>& stack, vector<char>& arrow)
{
    stack.push_back(i);
    used[i] = true;

    if (stack.size() < k + 1)
    {
        if (arrow[stack.size() - 1] == '<')
        {
            for (int ii = i; ii < 10; ii++)
            {
                if (!used[ii]) DFS(ii, k, used, stack, arrow);
            }
        }
        else // (arrow[stack.size()] == '>')
        {
            for (int ii = 0; ii < i; ii++)
            {
                if (!used[ii]) DFS(ii, k, used, stack, arrow);
            }
        }
    }
    else
    {
        long long v = 0;
        long long t = 1;

        for (int ii = stack.size() - 1 ; 0 <= ii; ii--, t *= 10)
        {
            v += stack[ii] * t;
        }
        
        minV = min(minV, v);
        maxV = max(maxV, v);
    }

    used[i] = false;
    stack.pop_back();
}



void answer(int k, vector<char> arrow)
{
    for (int i = 0; i < 10; i++)
    {
        vector<bool> used(10, false);
        vector<int> stack;

        DFS(i, k, used, stack, arrow);
    }

    printf("%0*lld\n%0*lld\n", k+1, maxV, k+1, minV);
}

int main()
{
    int k;
    vector<char> arrow;

    scanf("%d\n", &k);

    arrow = vector<char>(k);

    for (int i = 0; i < k; i++)
    {
        scanf("%c ", &arrow[i]);
    }

    answer(k, arrow);


    return 0;
}