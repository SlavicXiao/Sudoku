#include<vector>
#include "inputOutput.h"
#include <bits/stdc++.h>
using std::vector;

void PrintMat(vector<vector<int>> mat)
{
    for(int i = 0; i < 9; i++)
    {
        if (i == 0)
        {
            std::cout << "\n---0-1-2---3-4-5---6-7-8--\n";
        }
        
        for(int j = 0; j < 9; j++)
        {
            if(j == 0)
            {
                std::cout << i;
            }
            
            if( j % 3 == 0)
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
            std::cout << "\n--------------------------\n";
        }
        else 
        {
            std::cout << "\n";
        }
    }
}

void ValidInput(int& variable)
{
    std::cin >> variable;
        
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid input, please try again: ";
        std::cin >> variable;
    }
}
