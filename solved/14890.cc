#include <iostream>
#include <vector>

using namespace std;

class map
{
public:
    map(int N, int L);
    int SearchPath();
private:
    bool IsValid(int x, int y);
    vector<vector<int>> array;
    vector<vector<bool>> slope;
    int N;
    int L;
};

map::map(int N, int L) : N(N), L(L)
{
    array = vector<vector<int>>(N, vector<int>(N));
    slope = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d ", &array[i][j]);
        }
        scanf("\n");
    }
}

int map::SearchPath()
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        bool flag = true;
        int current = array[i][0];
        for (int j = 0; j < N; j++)
        {
            if (array[i][j] == current) 
            {
                continue;
            }
            else if (current - array[i][j] == 1)
            {
                int lcurrent = array[i][j];
                bool lflag = true;
                for (int l = 0; l < L; l++)
                {
                    if (!IsValid(i, j+l) || array[i][j + l] != lcurrent|| slope[i][j + l])
                    {
                        lflag = false;
                        break;
                    }
                    else
                    {
                        slope[i][j+l] = true;
                    }
                }

                if (lflag)
                {
                    current = array[i][j];
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (array[i][j] - current == 1)
            {
                int lcurrent = current;
                bool lflag = true;
                for (int l = 1; l <= L ; l++)
                {
                    if (!IsValid(i, j - l) || array[i][j - l] != lcurrent || slope[i][j - l])
                    {
                        lflag = false;
                        break;
                    }
                    else
                    {
                        slope[i][j-l] = true;
                    }
                }

                if (lflag)
                {
                    current = array[i][j];
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (flag) 
        {
            cnt++;
        }
    }

    slope.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        bool flag = true;
        int current = array[0][i];
        for (int j = 0; j < N; j++)
        {
            if (array[j][i] == current) continue;
            else if (current - array[j][i] == 1)
            {
                int lcurrent = array[j][i];
                bool lflag = true;
                for (int l = 0; l < L; l++)
                {
                    if (!IsValid(j + l, i) || array[j + l][i] != lcurrent || slope[j + l][i])
                    {
                        lflag = false;
                        break;
                    }
                    else
                    {
                        slope[j + l][i] = true;
                    }
                }

                if (lflag)
                {
                    current = array[j][i];
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (array[j][i] - current == 1)
            {
                int lcurrent = current;
                bool lflag = true;
                for (int l = 1; l <= L; l++)
                {
                    if (!IsValid(j - l, i) || array[j - l][i] != lcurrent || slope[j - l][i])
                    {
                        lflag = false;
                        break;
                    }
                    else
                    {
                        slope[j - l][i] = true;
                    }
                }

                if (lflag)
                {
                    current = array[j][i];
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag) 
        {
            cnt++;
        }
    }


    return cnt;
}

bool map::IsValid(int x, int y)
{
    return (0 <= x) && (x < N) && (0 <= y) && (y < N);
}

int main()
{
    int N, L;

    scanf("%d %d\n", &N, &L);

    map m(N, L);

    printf("%d\n", m.SearchPath());

    return 0;
}