#include <iostream>
#include <stdlib.h>
#include<Windows.h>

using namespace std;


#define Unassigned 0
#define maxRow 9
#define maxCol 9
#define max 9
#define maxGridRow 3
#define maxGridCol 3



bool UnassignedLocations(int array[maxRow][maxCol], int& row, int& col);
bool checkSafe(int array[maxRow][maxCol], int row, int col, int num);
void printSudoku(int array[maxRow][maxCol]);

bool solver(int array[maxRow][maxCol])
{
    int row, col;
    if (!UnassignedLocations(array, row, col))
    {
        return true;
    }


    for (int num = 1; num <= max; num++)
    {
        if (checkSafe(array, row, col, num))
        {
            system("CLS");
            printSudoku(array);
            Sleep(float(0.3));  //vary the value to see the output slower or faster

            array[row][col] = num;

            if (solver(array))
            {
                return true;
            }

            array[row][col] = Unassigned;
        }
    }
    return false;
}

bool UnassignedLocations(int array[maxRow][maxCol], int &row, int &col)
{
    for (row = 0; row < max; row++)
    {
        for (col = 0; col < max; col++)
        {
            if (array[row][col] == Unassigned)
            {
                return true;
            }
        }
    }
    return false;
}

void inputSuduko(int array[maxRow][maxCol])
{
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            cin >> array[i][j];
        }
    }
}

void printSudoku(int array[maxRow][maxCol])
{
    for (int i = 0; i < maxRow ; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            if (j == 3 || j == 6) 
            {
                cout << "|";
            }
            cout << array[i][j]<<" ";
        }
        if (i == 2 || i == 5)
        {
            cout<<endl;
            cout << "-------------------";
        }
        cout << endl;
    }
}

bool gridCheck(int array[maxRow][maxCol] ,int gridStartRow ,int gridStartCol ,int num)
{
    for (int row = 0; row < maxGridRow; row++)
    {
        for (int col = 0; col < maxGridCol; col++)
        {
            if (array[row+gridStartRow][col+gridStartCol] == num)
            {
                return true;
            }
        }
    }
    return false;
}

bool checkInRow(int array[maxRow][maxCol], int row,int num)
{
    for(int col = 0; col < maxRow; col++)
    {
        if(array[row][col]==num)
        {
            return true;
        }
    }
    return false;
}

bool checkInColumn(int array[maxRow][maxCol], int col, int num)
{
    for (int row = 0; row < maxCol; row++)
    {
        if (array[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool checkSafe(int array[maxRow][maxCol],int row ,int col,int num)
{
    return(!checkInRow(array, row, num) && !checkInColumn(array, col, num) && !gridCheck(array, row - row % 3, col - col % 3, num) && array[row][col] == Unassigned);
}

int main()
{
    int array[maxRow][maxCol];
    inputSuduko(array);
    cout << endl << endl;

    cout << "Check Entered Sudoku" << endl;
    printSudoku(array);

    cout << endl << endl;

    if (solver(array) == true)
    {
        cout << endl;
        cout << "Sudoku Solved....." << endl;
    }
    else
    {
        cout << "Unable to solve sudoku";
    }
    system("pause");
}



