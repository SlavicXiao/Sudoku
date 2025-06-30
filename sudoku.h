#pragma once

#include "sudoku.h"
#include<vector>
#include <bits/stdc++.h>
using std::vector;

bool IsUnusedBox(vector<vector<int>>&sudokuMat, int startRow, int startCol, int n);

bool IsUnusedRow(vector<vector<int>>&sudokuMat, int i, int n);

bool IsUnusedCol(vector<vector<int>>&sudokuMat, int j, int n);

bool CelSafe(vector<vector<int>>&sudokuMat, int i, int j, int n);

void BlockFill(vector<vector<int>> &sudokuMat, int row, int col);

void FillDiagonal(vector<vector<int>> &sudokuMat);

bool FillRemaining(vector<vector<int>> &grid, int i, int j);

vector<vector<int>> GenerateMat();

vector<vector<int>> RemoveDigits(vector<vector<int>> mat, int k);



