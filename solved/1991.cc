// Create Adjlist-like data structure for a binary tree
// Traverse it inorder/preorder/postorder
#include <iostream>
#include <vector>

using namespace std;

class Adjlist
{
public:
    Adjlist(int N);                 // Constructor
    void InsertNode(char parent, char childl, char childr); // Insert Node to adjlist
    void PrintAdjlist();            // Print for debugging
    void Inorder(int index);
    void Preorder(int index);
    void Postorder(int index);
private:
    char InttoChar(int index);      // 0, 1, 2... -> A, B, C...
    int ChartoInt(char index);      // A, B, C... -> 0, 1, 2...
    int size;                       // Number of nodes
    vector<vector<int>> adjlist;    // Adjlist
};

Adjlist::Adjlist(int N):
    size(N)
{
    adjlist = vector<vector<int>>(size);
}

void Adjlist::InsertNode(char parent, char childl, char childr)
{
    adjlist[ChartoInt(parent)].push_back(ChartoInt(childl));
    adjlist[ChartoInt(parent)].push_back(ChartoInt(childr));
}

void Adjlist::PrintAdjlist()
{
    for (int i = 0; i < size; i++)
    {
        printf("%c : ", InttoChar(i));
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            printf("%c ", InttoChar(adjlist[i][j]));
        }
        printf("\n");
    }
}

void Adjlist::Inorder(int index)
{
    if (index == -1)
    {
        return;
    }
    Inorder(adjlist[index][0]);
    printf("%c", InttoChar(index));
    Inorder(adjlist[index][1]);
}

void Adjlist::Preorder(int index)
{
    if (index == -1)
    {
        return;
    }
    printf("%c", InttoChar(index));
    Preorder(adjlist[index][0]);
    Preorder(adjlist[index][1]);
}

void Adjlist::Postorder(int index)
{
    if (index == -1)
    {
        return;
    }
    Postorder(adjlist[index][0]);
    Postorder(adjlist[index][1]);
    printf("%c", InttoChar(index));
}

char Adjlist::InttoChar(int index)
{
    return (char) (index + 'A');
}

int Adjlist::ChartoInt(char index)
{
    if (index != '.')
    {
        return (int) (index - 'A');
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N;
    char temproot, templ, tempr;

    scanf("%d\n", &N);
    Adjlist tree(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%c %c %c\n", &temproot, &templ, &tempr);
        tree.InsertNode(temproot, templ, tempr);
    }

    tree.Preorder(0);
    printf("\n");
    tree.Inorder(0);
    printf("\n");
    tree.Postorder(0);
    printf("\n");

    return 0;
}