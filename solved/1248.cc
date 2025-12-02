#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;
bool found = false;

bool isValid(int n, char c)
{
    if (n < 0 && c == '-') return true;
    if (n == 0 && c == '0') return true;
    if (0 < n && c == '+') return true;
    return false;
}


void DFS(int i, int n, vector<vector<char>> S)
{
    stack.push_back(i);

    if (stack.size() < n)
    {
        for (int ii = -10; ii <= 10; ii++)
        {
            bool flag = true;
            for (int j = 0; j <= stack.size(); j++)
            {
                int sum = 0;
                for (int k = j; k < stack.size(); k++)
                {
                    sum += stack[k];
                }
                if (!isValid(sum + ii, S[j][stack.size()]))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                DFS(ii, n, S);

                if (found)
                {
                    stack.pop_back();
                    return;
                }
            }
        }

    }
    else
    {
        for (int ii = 0; ii < n; ii++)
        {
            printf("%d ", stack[ii]);
        }
        printf("\n");

        found = true;

        stack.pop_back();
        return;
    }

    stack.pop_back();
}



void answer(int n, vector<vector<char>> S)
{
    for (int i = -10; i <= 10; i++)
    {
        if (isValid(i, S[0][0]))
        {
            DFS(i, n, S);
            if (found)
            {
                break;
            }
        }
    }
}


int main()
{
    int n;
    vector<vector<char>> S;

    scanf("%d\n", &n);

    S = vector(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            scanf("%c", &S[i][j]);
        }
    }

    answer(n, S);

}