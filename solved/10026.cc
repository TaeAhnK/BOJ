// Create 2 graphs - actual image graph and image with all Gs to R
// Count connected components using DFS

#include <iostream>

using namespace std;

const int dx[8] = {-1, 0, 0, 1,-1,-1, 1, 1};    // Directions for DFS
const int dy[8] = { 0, 1,-1, 0, 1,-1, 1,-1};    // Directions for DFS

template <typename T>
class Graph2DArray          // Graph in 2DArray Form
{
    private:
        int col;            // Col of 2DArray Graph
        int row;            // Row of 2DArray Graph
        T** graph;          // Graph data in 2DArray
        bool** visited;     // Visited for DFS
        void DFS(int row, int col);                 // Depth First Search of Graph
        void resetvisited();                        // Set visited to false
        bool isNotVisited(int i, int j, T current); // Condition for DFS
    protected:
    public:
        Graph2DArray(int col, int row);         // Init
        ~Graph2DArray();                        // Destuctor
        int connectedComponents();              // Calc connectedComponents using DFS
        void setgraph(int i, int j, T value);   // Write Graph data
        void printVisited();                    // Print visited for debugging
        T graphValue(int i , int j);            // Return value of graph[i][j]
};

class Image     // Image class
{
    private:
        int col;    // Col of Image
        int row;    // Row of Image
        Graph2DArray<char> actualImage;     // Actual Image Data
        Graph2DArray<char> RGWeeknessImage; // Image Data with Rs in G
    protected:
    public:
        Image(int col, int row);    // Init
        ~Image();                   // Destuctor
        void read();                // Read Input and Write Data
        void connectedArea();       // Calc connected areas
        void printImages();         // Print stored Image for debugging
};

template <typename T>
Graph2DArray<T>::Graph2DArray(int col, int row)
{
    this->col = col;
    this->row = row;
    graph = new T* [row];
    visited = new bool* [row];
    for (int i = 0; i < row; i++)
    {
        graph[i] = new T [col];
        visited[i] = new bool [col];
    }

    return;
};

template <typename T>
Graph2DArray<T>::~Graph2DArray()
{
    for (int i = 0; i < row; i++) {
        delete[] graph[i];
        delete[] visited[i];
    }
    delete[] graph;
    delete[] visited;

    return;
};

template <typename T>
void Graph2DArray<T>::DFS(int row, int col)
{
    if (visited[row][col] == true)
    {
        return;
    }

    visited[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        if (isNotVisited(row + dy[i], col + dx[i], graph[row][col]) == true)
        {
            DFS(row + dy[i], col + dx[i]);
        }
    }

    return;
};

template <typename T>
void Graph2DArray<T>::resetvisited(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            visited[i][j] = false;
        }
    }

    return;
};

template <typename T>
bool Graph2DArray<T>::isNotVisited(int i, int j, T current){
    if (i < 0 || j < 0 || row <= i || col <= j || visited[i][j])
    {
        return false;
    }
    if (current == graph[i][j])
    {
        return true;
    }
    return false;
};

template <typename T>
void Graph2DArray<T>::setgraph(int i, int j, T value)
{
    graph[i][j] = value;

    return;
};

template <typename T>
T Graph2DArray<T>::graphValue(int i, int j)
{
    return graph[i][j];
};

template <typename T>
int Graph2DArray<T>::connectedComponents()
{
    resetvisited();
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {
            if (visited[i][j] == false)
            {
                DFS(i, j);
                cnt++;
            }
        }
    }

    return cnt;
};

template <typename T>
void Graph2DArray<T>::printVisited(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d", (int) visited[i][j]);
        }
        printf("\n");
    }

    return;
};

Image::Image(int col, int row) : actualImage(col, row) , RGWeeknessImage(col, row)
{
    this->col = col;
    this->row = row;
    read();
    return;
};

Image::~Image()
{
    return;
};

void Image::read()
{
    char temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%c", &temp);
            actualImage.setgraph(i, j, temp);
            if (temp == 'G')
            {
                RGWeeknessImage.setgraph(i, j, 'R');
            }
            else
            {
                RGWeeknessImage.setgraph(i, j, temp);
            }
        }
        scanf("\n");
    }

    return;
};

void Image::connectedArea()
{
    printf("%d %d\n", actualImage.connectedComponents(), RGWeeknessImage.connectedComponents());

    return;
};

void Image::printImages()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c", actualImage.graphValue(i, j));
        }
        printf("\n");
    }
    printf("\n");

        for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c", RGWeeknessImage.graphValue(i, j));
        }
        printf("\n");
    }
    printf("\n");

    return;
};

int main()
{
    int N;
    scanf("%d\n", &N);

    Image img(N, N);
    img.connectedArea();
    
    return 0;
}