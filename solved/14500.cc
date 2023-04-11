// Brute-force all possible case of rotation and positions
#include <iostream>
#include <algorithm>

using namespace std;

const int NUM_OF_SHAPE = 7;     // Tetromino shape : 7 including symmetry
const int NUM_OF_ROTATE = 4;    // 90 degree rotation
const int BLOCK_HEIGHT = 4;
const int BLOCK_WIDTH = 4;

const char block[NUM_OF_SHAPE][NUM_OF_ROTATE][BLOCK_HEIGHT][BLOCK_WIDTH] ={     // Every Shape of Tetromino 
	{/*[0][][][]					▩▩▩▩*/
		{/*[][0][][]*/
			{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}
		},
		{/*[][1][][]*/
			{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}			
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}			
		},
		{/*[][3][][]*/
			{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}
		}
	},
	{/*[1][][][];					  ▩▩▩*/
		{/*[][0][][]				     ▩*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}
		},
		{/*[][1][][]*/
			{0, 0, 0, 0}, {0, 0 ,1, 1}, {0, 0, 1, 0}, {0, 0, 1, 0}
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}
		},
		{/*[][3][][]*/
			{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}
		}
	},
	{/*[2][][][];					  ▩▩▩*/
		{/*[][0][][]				  ▩*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}
		},
		{/*[][1][][]*/
			{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 0}
		},
		{/*[][3][][]*/
			{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}
		}
	},
	{/*[3][][][];					    ▩▩▩*/
		{   /*[][0][][]				      ▩*/
			{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}
		},
		{/*[][1][][]*/
			{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}
		},
		{/*[][3][][]*/
			{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}
		}
	},
	{/*[4][][][];					  ▩▩*/
		{/*[][0][][]				  ▩▩*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}
		},
		{/*[][1][][]*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}
		},
		{/*[][3][][]*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}
		}
	},
	{/*[5][][][];					  ▩▩*/
		{/*[][0][][]				▩▩*/
			{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}
		},
		{/*[][1][][]*/
			{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}			
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}			
		},
		{/*[][3][][]*/
			{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}			
		}
	},
	{/*[6][][][];				    ▩▩  */
		{/*[][0][][]				  ▩▩*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}
		},
		{/*[][1][][]*/
			{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}
		},
		{/*[][2][][]*/
			{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}
		},
		{/*[][3][][]*/
			{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}
		}
	}
};

class tetromino
{
    public:
		tetromino(int N, int M);    // Init
		~tetromino();               // Destructor
		int maxTetroSum();          // Calculate all possible cases
    private:
		void readMap();             // Read map info
		int tetroSum(int shape, int rotate, int x, int y);  // Caculate score of paticular shape+rotation+position
		bool isPlaceable(int xx, int yy, int x, int y);     // Can be placed in the position
		int** map;      // Map data
		int col;        // Col size of map
		int row;        // Row size of map
};

tetromino::tetromino(int N, int M) :
	row(N),
	col(M)
{
	map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int [M];
	}
	readMap();
}

tetromino::~tetromino()
{
	for (int i = 0; i < row; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

int tetromino::maxTetroSum()
{
    int maxSum;
	for (int s = 0; s < NUM_OF_SHAPE; s++)
	{
		for (int r = 0; r < NUM_OF_ROTATE; r++)
		{
			for (int y = -3; y < row; y++)
			{
				for (int x = -3; x < col; x++)
				{
					maxSum = max(tetroSum(s, r, x, y), maxSum);
				}
			}
		}
	}
	return maxSum;
}

void tetromino::readMap()
{
	int temp;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			scanf("%d ", &temp);
			map[r][c] = temp;
		}
		scanf("\n");
	}
}

int tetromino::tetroSum(int shape, int rotate, int x, int y)
{
	int sum = 0;
	for (int yy = 0; yy < BLOCK_HEIGHT; yy++)
	{
		for (int xx = 0; xx < BLOCK_WIDTH; xx++)
		{
			if (block[shape][rotate][yy][xx])
			{
				if (isPlaceable(xx, yy, x, y))
				{
					sum += map[yy+y][xx+x];
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return sum;
}

bool tetromino::isPlaceable(int xx, int yy, int x, int y)
{
	return !(xx+x < 0 || col <= xx+x || yy+y < 0 || row <= yy+y);
}

int main()
{
	int N, M;
	scanf("%d %d\n", &N, &M);
	tetromino T(N, M);
	printf("%d\n", T.maxTetroSum());
}