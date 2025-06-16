#include<iostream>
#include<vector>
using std::vector;

bool IsUnusedBox(vector<vector<int>>&sudokuMat, int startCol, int startRow, int n)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(sudokuMat[startRow + i][startCol + j] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsUnusedRow(vector<vector<int>>&sudokuMat, int row, int n)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudokuMat[i][row] == n)
        {
            return false;
        }
    }
    return true;
}

bool IsUnusedCol(vector<vector<int>>&sudokuMat, int col, int n)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudokuMat[col][i] == n)
        {
            return false;
        }
    }
    return true;
}

bool CelSafe(vector<vector<int>>&sudokuMat, int row, int col, int n)
{
    if(IsUnusedBox(sudokuMat, row - row % 3, col - col % 3, n) && IsUnusedCol(sudokuMat, col, n) && IsUnusedRow(sudokuMat, row, n))
    {
        return true;
    }

    else return false;
}

void BlockFill(vector<vector<int>> &sudokuMat, int col, int row)
{
    int n;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            do
            {
                n = rand() % 9 + 1;
            } while (IsUnusedBox(sudokuMat, col, row, n));
            sudokuMat[row + i][col + j] = n;  
        }
    }
}

void FillDiagonal(vector<vector<int>>&sudokuMat)
{
    for(int i = 0; i < 9; i += 3)
    {
        BlockFill(sudokuMat, i, i);
    }
}

bool FillRemaining(vector<vector<int>> &sudokuMat, int i, int j)
{
    if(i == 9)
    {
        return true;
    }

    if(j == 9)
    {
        return FillRemaining(sudokuMat, i + 1, 0);
    }

    if(sudokuMat[i][j] != 0)
    {
        return FillRemaining(sudokuMat, i, j + 1);
    }

    for(int n = 1; n < 9; n++)
    {
        if(CelSafe(sudokuMat, i, j, n))
        {
            sudokuMat[i][j] = n;
            if(FillRemaining(sudokuMat, i, j + 1))
            {
                return true;
            }
            sudokuMat[i][j] = 0;
        }
    }
}

int main()
{

    return 0;
}