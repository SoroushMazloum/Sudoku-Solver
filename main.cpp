#include <iostream>
#define _MAX 9
using namespace std;

int Sudoku [9] [9] = 
{
   {5, 3, 0, 0, 7, 0, 0, 0, 0},
   {6, 0, 0, 1, 9, 5, 0, 0, 0},
   {0, 9, 8, 0, 0, 0, 0, 6, 0},
   {8, 0, 0, 0, 6, 0, 0, 0, 3},
   {4, 0, 0, 8, 0, 3, 0, 0, 1},
   {7, 0, 0, 0, 2, 0, 0, 0, 6},
   {0, 6, 0, 0, 0, 0, 2, 8, 0},
   {0, 0, 0, 4, 1, 9, 0, 0, 5},
   {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

bool IsSafe(int Row, int Col, int Number)
{
    for(int R = 0 ; R < _MAX ; R++)
    {
        if(Sudoku [R] [Col] == Number)
            return false;
    }
    for(int C = 0 ; C < _MAX ; C++)
    {
        if(Sudoku [Row] [C] == Number)
            return false;
    }
    int rowStart = Row - Row % 3;
    int colStart = Col - Col % 3;
    for (int R = 0; R < 3; R++)
    {
        for (int C = 0; C < 3; C++)
        {
            if (Sudoku [R + rowStart] [C + colStart] == Number)
                return false;
        }   
    }
    return true;
}

bool HasEmpty(int &Row, int &Col)
{
    for(Row = 0 ; Row < _MAX ; Row++)
    {
        for(Col = 0 ; Col < _MAX ; Col++)
        {
            if(Sudoku [Row] [Col] == 0)
                return true;
        }
    }
    return false;
}

bool Solver()
{
    int R, C;
    if(!HasEmpty(R, C))
        return true;
    for(int Num = 1 ; Num <= _MAX ; Num++)
    {
        if(IsSafe(R, C, Num))
        {
            Sudoku [R] [C] = Num;
            if(Solver())
                return true;
            Sudoku [R] [C] = 0;
        }
    }
    return false;
}

void Printer(){
    for (int Row = 0; Row < _MAX; Row++)
    {
        for (int Col = 0; Col < _MAX; Col++)
        {
           if(Col == 3 || Col == 6)
              cout << "  |  ";
           cout << Sudoku [Row] [Col] <<" ";
        }
        if(Row == 2 || Row == 5)
        {
            cout << endl;
            for(int i = 0; i<_MAX; i++)
            cout << "---";
        }
      cout << endl;
   }
}

int main()
{
    if(Solver())
        Printer();
    else
        cout<<"No solution :( "<<endl;
}
