#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include"sudoku.h"
#include"inputOutput.h"
using std::vector;

void Play()
{   
    std::cout << "Sudoku\n\nChoose difficulty:\n\t(1)Easy\n\t(2)Medium\n\t(3)Hard\n\nChoice: ";
    int difficulty,k;

    ValidInput(difficulty);
    switch (difficulty)
    {
        case 1:
            k = 40;
            break;
        
        case 2: 
            k = 50;
            break;
            
        case 3: 
            k = 60;
            break;

        default:
            std::cout << "Invalid input. Try again: ";
            std::cin >> difficulty; 
            break;
    }

    system("cls");

    srand(time(0));

    vector<vector<int>> solvedSudoku = GenerateMat();
    vector<vector<int>> playableSudoku = RemoveDigits(solvedSudoku, k);
    
    PrintMat(playableSudoku);

    int i,j,n;

    while(IsSolved(playableSudoku) == false)
    {
        std::cout << "Choose column: ";
        ValidInput(i);

        std::cout << "Choose row: ";
        ValidInput(j);

        std::cout << "Enter a number: ";
        ValidInput(n);

        if(solvedSudoku[j][i] == n)
        {
            playableSudoku[j][i] = n;
            system("cls");
            PrintMat(playableSudoku);
            
            std::cout << "\n";
        }

        else
        {
            system("cls");
            std::cout << "Wrong guess\n";
            
            PrintMat(playableSudoku);
            std::cout << "\n";
        }
    }

    std::cout << "You win!\n";
    getchar();
}

int main()
{
    Play();
    
    int choice;
    do
    {
        std::cout << "Would you like to play again?\n(1 - yes / other - no)";
        ValidInput(choice);
        if(choice == 1) Play();

    }while(choice == 1);

    return 0;
}