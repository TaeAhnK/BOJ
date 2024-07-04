// Get the sum by partialSum
// = partialChart[x2][y2] - partialChart[x2][y1-1]
//   - partialChart[x1-1][y2] + partialChart[x1-1][y1-1]
#include <iostream>
#include <vector>

using namespace std;

class Chart
{
public:
    Chart(int N);                                   // Constructor
    int PartialSum(int x1, int y1, int x2, int y2); // Get Parital Sum
    void ReadChart();                               // Get Data
    void PrintPartialChart();                       // Print for Debug
private:
    vector<vector<int>> partialChart;               // Cache of Partial Sum
    int _N;                                         // Length N
};

Chart::Chart(int N)
{
    _N = N;
    partialChart = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
}

int Chart::PartialSum(int x1, int y1, int x2, int y2)
{
    return partialChart[x2][y2] - partialChart[x2][y1-1] - partialChart[x1-1][y2] + partialChart[x1-1][y1-1];
}

void Chart::ReadChart()
{
    int temp;
    for (int i = 1; i <= _N; i++)
    {
        for (int j = 1; j <= _N; j++)
        {
            scanf("%d ", &temp);
            partialChart[i][j] = temp + partialChart[i-1][j] + partialChart[i][j-1] - partialChart[i-1][j-1]; 
        }
    }
}

void Chart::PrintPartialChart()
{
    for (int i = 0; i <= _N; i++)
    {
        for (int j = 0; j <= _N; j++)
        {
            printf("%d ", partialChart[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int M, N;
    int x1, y1, x2, y2;
    scanf("%d %d\n", &N, &M);

    Chart c(N);
    c.ReadChart();
    //c.PrintPartialChart();
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
        printf("%d\n", c.PartialSum(x1,y1, x2,y2));
    }

}