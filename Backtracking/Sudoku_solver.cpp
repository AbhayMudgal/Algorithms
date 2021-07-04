#include<bits/stdc++.h>
using namespace std;
#define N 9

void print(int grid[N][N]){
  //prints the sudoku grid
  for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num){

//checking row for repeating values
  for (int x = 0; x<N; x++){
    if (grid[row][x] == num)
      return false;
  }
//checking column for repeating values
  for (int y = 0; y<N; y++){
    if (grid[y][col] == num)
      return false;
  }

//checking 3x3 subarray for repeating values
  for (int x = 3*(row/3); x<3*(row/3 + 1); x++){
    for (int y = 3*(col/3); y<3*(col/3 + 1); y++){
      if(x == row && y== col)
        continue;
      if(grid[x][y] == num)
        return false;
    }
  }
  return true;
}

bool solveSudoku(int grid[N][N], int row, int col){
  if (row == N-1 && col == N)
    return true;

  if (col == N){
    row++;
    col = 0;
  }

  if(grid[row][col] > 0){
    return solveSudoku(grid, row, col+1);
  }

  for (int i = 1; i<=N; i++){
    if (isSafe(grid, row, col, i)){
      grid[row][col] = i;
      if (solveSudoku(grid, row, col+1))
        return true;
    }
    grid[row][col] = 0;
  }
  return false;
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;

    return 0;
}
