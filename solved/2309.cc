#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> dwarfs;
    vector<bool> select(9, true);

    for (int i = 0; i < 9; i++)
    {
        int temp; 
        scanf("%d\n", &temp);
        dwarfs.push_back(temp);
    }
    sort(dwarfs.begin(), dwarfs.end());

    fill(select.begin(), select.begin() + 2, false);
    
    do
    {
        int sum = 0;
        for (int i = 0; i < 9; i++)
        {
            if (select[i]) sum += dwarfs[i];
        }
        
        if (sum == 100)
        {
            for (int i = 0; i < 9; i++)
            {
                if (select[i]) printf("%d\n", dwarfs[i]);                
            }
            break;
        }
    } while (next_permutation(select.begin(), select.end()));
}