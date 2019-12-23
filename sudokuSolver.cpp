#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    void printGrid(int grid[9][9]){
        cout<<"================="<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<< grid[i][j] <<" ";
            }
            cout<<endl;
        }
        cout<<"================="<<endl;
    }

    bool Opt1(int grid[9][9],int row,int col ){
        int x = grid[row][col];
        for(int i=0;i<9;i++){
            if(x == grid[row][i] && i!=col)
                return false;
        }
        return true;
    }

    bool Opt2(int grid[9][9],int row,int col ){
        int x = grid[row][col];
        for(int i=0;i<9;i++){
            if(x == grid[i][col] && i!=row)
                return false;
        }
        return true;
    }

    bool Opt3(int grid[9][9],int row,int col ){
        int x = grid[row][col];
        int cell_x = col/3;
        int cell_y = row/3;
        for(int i=cell_x*3;i/3==cell_x;i++){
            for(int j=cell_y*3;i/3==cell_y;i++){
                if(x == grid[i][j] && i!=row && j!=col)
                    return false;
            }
        }
        return true;
    }

    bool solValid(int grid[9][9],int row,int col){
        if(grid[row][col]!=0){
            if(Opt2(grid,row,col) && Opt1(grid,row,col) && Opt3(grid,row,col) )
                return true;
            return false;
        }
        return true;
    }

    bool FindBlank(int grid[9][9],int& row,int& col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( grid[i][j] == 0){
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }

    void solveHelper(int grid[9][9],int row,int col,int& count,int& calls){
        calls++;
        bool blank = FindBlank(grid,row,col);
        //base case
        //cout<<"row  : "<<row<<endl;
        if(!blank){
            //print the grid(solution)
            count = count+1;
            //printGrid(grid);
        }
        //recurcive case
        else{
            for(int i=1;i<=9;i++){//choice--digits
                //choose
                grid[row][col] = i;
                //printGrid(grid);
                //explore
                if(solValid(grid,row,col))
                    solveHelper(grid,row,col,count,calls);
                //un-choose
                    grid[row][col] = 0;

            }
        }
    }
public:
    int solveSudoku(int grid[9][9] ){
        int count=0,calls=0;
        solveHelper(grid,0,0,count,calls);
        cout<<"COUNT : "<<count<<endl<<"CALLS :"<<calls<<endl;
        return count;
    }
    bool isPSetValid(int grid[9][9]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (!solValid(grid,i,j))
                    return false;
            }
        }
        return true;
    }
};


int main()
{
    int pset[9][9];
    int test1[9][9] = { {3, 1, 6, 5, 0, 8, 4, 9, 2},
                       {5, 2, 9, 1, 3, 4, 7, 6, 0},
                       {4, 8, 7, 6, 0, 9, 5, 3, 1},
                       {0, 6, 3, 4, 1, 5, 9, 8, 7},
                       {9, 7, 4, 8, 6, 3, 1, 0, 5},
                       {0, 5, 1, 7, 9, 2, 6, 4, 3},
                       {1, 3, 8, 9, 0, 7, 2, 5, 6},
                       {6, 9, 2, 0, 5, 1, 8, 7, 4},
                       {7, 4, 5, 2, 8, 6, 3, 9, 9}};
    int test2[9][9]={
        {7,8,0,4,3,0,1,2,0},
        {6,0,0,0,7,5,0,0,9},
        {0,0,0,6,0,1,0,7,8},
        {0,0,7,0,4,0,2,6,0},
        {0,0,1,0,5,0,9,3,0},
        {9,0,4,0,6,0,0,0,5},
        {0,7,0,3,0,0,0,1,2},
        {1,2,0,0,0,7,4,0,0},
        {0,4,9,2,0,6,0,0,7}
    };
    for(int i=0;i<9;i++){
        cout<<"Enter row" << i+1 << "numbers one by one"<<endl;
        for(int j=0;j<9;j++){
            cin >> pset[i][j];
        }
    }
    Solution c;
    if(!c.isPSetValid(pset) )
        cout<<"The given sudoku is invalid,plz check and re-enter"<<endl<<endl;
    else if(c.solveSudoku(pset) == 0)
            cout<<"NO SOLUTION EXISTS."<<endl;
    return 0;
}
