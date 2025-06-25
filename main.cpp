#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using std::vector;

bool IsUnusedBox(vector<vector<int>>&sudokuMat, int startRow, int startCol, int n)
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

bool IsUnusedRow(vector<vector<int>>&sudokuMat, int i, int n)
{
    for(int k = 0; k < 9; k++)
    {
        if(sudokuMat[i][k] == n)
        {
            return false;
        }
    }
    return true;
}

bool IsUnusedCol(vector<vector<int>>&sudokuMat, int j, int n)
{
    for(int k = 0; k < 9; k++)
    {
        if(sudokuMat[k][j] == n)
        {
            return false;
        }
    }
    return true;
}

bool CelSafe(vector<vector<int>>&sudokuMat, int i, int j, int n)
{
    if(IsUnusedBox(sudokuMat, i - i % 3, j - j % 3, n) && IsUnusedCol(sudokuMat, j, n) && IsUnusedRow(sudokuMat, i, n))
    {
        return true;
    }

    else return false;
}

void BlockFill(vector<vector<int>> &sudokuMat, int row, int col)
{
    int n;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            do
            {
                n = (rand() % 9) + 1;
            } while (!IsUnusedBox(sudokuMat, row, col, n));
            sudokuMat[row + i][col + j] = n;  
        }
    }
}

void FillDiagonal(vector<vector<int>> &sudokuMat)
{
    for(int i = 0; i < 9; i += 3)
    {
        BlockFill(sudokuMat, i, i);
    }
}

bool FillRemaining(vector<vector<int>> &grid, int i, int j) {
    
    if (i == 9) 
    {
        return true;
    }

    if (j == 9)
    {
        return FillRemaining(grid, i + 1, 0);
    }

    if (grid[i][j] != 0)
    {
        return FillRemaining(grid, i, j + 1);
    }
    
    for (int n = 1; n <= 9; n++) 
    {
        if (CelSafe(grid, i, j, n))
        {
            grid[i][j] = n;
            if (FillRemaining(grid, i, j + 1))
            {
                return true;
            }
            grid[i][j] = 0; 
        }
    }
    
    return false;
}

void PrintMat(vector<vector<int>> mat)
{
    for(int i = 0; i < 9; i++)
    {
        if (i == 0)
        {
            std::cout << "\n-------------------------\n";
        }
        for(int j = 0; j < 9; j++)
        {
            if(j == 0 || j % 3 ==0)
            {
                std::cout << "| ";
            }
            std::cout << mat[i][j] << " ";
            if(j == 8)
            {
                std::cout << "| ";
            } 
        }
        
        if(i == 2 || i == 5 || i == 8)
        {
            std::cout << "\n-------------------------\n";
        }
        else 
        {
            std::cout << "\n";
        }
    }
}

vector<vector<int>> GenerateMat()
{

    vector<vector<int>> Mat(9, vector<int>(9,0));
    FillDiagonal(Mat);
    FillRemaining(Mat,0,0);
    return Mat;
}

vector<vector<int>> RemoveDigits(vector<vector<int>> mat, int k)
{
    while(k > 0)
    {
        int cell = rand() % 81;
        int i = cell / 9;
        int j = cell % 9;

        if(mat[i][j] != 0)
        {
            mat[i][j] = 0;
            k--;
        }
    }

    return mat;
}

int main()
{
    srand(time(0));

    vector<vector<int>> sudoku = GenerateMat();
    vector<vector<int>> playableSudoku = RemoveDigits(sudoku, 20);
    PrintMat(playableSudoku);
    
    return 0;
}