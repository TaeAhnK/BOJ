// For mininum formular, all numbers behind minus should be added with bracket and plus.
// Slice the input based on sign, and store them as integar in a vector.
// If minus is shown, multifly -1.
// Then, sum the vector

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class fomula
{
    public:
        fomula();               // Init
        ~fomula();              // Destructor
    private:   
        void read();            // Read and parse the input formular
        int calcSum();          // Pop the vector and add all elements
        vector<int> numbers;    // Vector to store the elements
};

fomula::fomula()
{
    read();
    printf("%d\n", calcSum());
}

fomula::~fomula()
{
}

void fomula::read()
{
    char input[51];
    scanf("%s\n", input);
    string form = input;

    int start = 0;
    int end = 0;
    int minusFlag = 1;
    for (int i = 0; i < form.length(); i++)
    {
        if ((int) form[i] == 43)
        {
            end = i - 1;
            numbers.push_back(minusFlag * stoi(form.substr(start, end-start+1)));
            start = i + 1;
        }
        else if ((int) form[i] == 45)
        {
            end = i - 1;
            numbers.push_back(minusFlag * stoi(form.substr(start, end-start+1)));
            start = i + 1;
            minusFlag = -1;
        }
        else if (i == form.length() - 1)
        {
            end = i;
            numbers.push_back(minusFlag * stoi(form.substr(start, end-start+1)));
            start = i + 1;
        }
    }
}

int fomula::calcSum()
{
    int sum = 0;
    while (!numbers.empty())
    {
        sum += numbers.back();
        numbers.pop_back();
    }

    return sum;
}

int main()
{
    fomula f;

    return 0;
}
