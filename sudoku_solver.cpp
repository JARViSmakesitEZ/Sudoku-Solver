#include<bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>>& grid){
    for(int i = 0;i<9;i++){
        cout<<"-------------------------------------"<<endl;
        cout<<"| ";
        for(int j = 0;j<9;j++){
            if(grid[i][j]!=-1){
                cout<<grid[i][j];
            }
            else{
                cout<<" ";
            }
            if((j+1)%3==0){
                cout<<" | ";
            }
            else{
                cout<<" | ";
            }
        }
        cout<<endl;
    }
    cout<<"-------------------------------------"<<endl<<endl<<endl;
}

int isvalid(vector<vector<int>>& board,int i,int j,int num){



        for(int row=0;row<9;row++){
            if(board[row][j]==num){
                return false;
            }
        }


        for(int col=0;col<9;col++){
            if(board[i][col]==num){
                return false;
            }
        }

        int row=i-i%3,col=j-j%3;
        for(int p=row;p<row+3;p++){
            for(int q=col;q<col+3;q++){
                if(board[p][q]==num){
                    return false;
                }
            }
        }

        return true;

    }
    bool solve(vector<vector<int>>& board,int i,int j){
        if(i==9){
            return true;
        }
        if(j==9){
            return solve(board,i+1,0);
        }
        if(board[i][j]!=-1){
            return solve(board,i,j+1);
        }
        for(int num=1;num<=9;num++){
            if(isvalid(board,i,j,num)){
                board[i][j]=num;
                bool status=solve(board,i,j+1);
                if(status==true){
                    return true;
                }
                board[i][j]=-1;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<int>>& board) {
    
        solve(board,0,0);
    }

int main(){
    cout<<"HI LOOSER , I'LL SOLVE THE SUDOKU FOR YOU."<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"ENTER THE BOARD CONFIGURATIONS FOR ME PLEASE:"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"ENTER THE DETAILS ROW-WISE , ENTER THE VALUE IF THE VALUE IS PRESENT , AND IF NOT TYPE -1"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    vector<vector<int>> grid(9,vector<int>(9,-1));
    
    //USER INPUT
    // for(int i = 0;i<9;i++){
    //     cout<<"ROW "<<i+1<<" :"<<endl;
    //     cout<<"------------------------------------------------------------------------------------------"<<endl;
    //     for(int j = 0;j<9;j++){
    //         cin>>grid[i][j];
    //     }
    // }
    
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    
    grid = {{5, 3 ,-1, -1, 7 ,-1 ,-1 ,-1, -1},{6, -1, -1 ,1, 9, 5 ,-1 ,-1, -1},{-1 ,9, 8, -1, -1 ,-1 ,-1 ,6 ,-1},{8, -1 ,-1 ,-1 ,6 ,-1, -1, -1 ,3},{4 ,-1, -1, 8 ,-1, 3, -1 ,-1, 1},{7 ,-1 ,-1 ,-1, 2, -1 ,-1 ,-1 ,6},{-1 ,6, -1, -1, -1 ,-1, 2, 8 ,-1},{-1 ,-1, -1, 4, 1, 9 ,-1, -1, 5},{-1 ,-1, -1 ,-1, 8, -1 ,-1 ,7 ,9}};
    cout<<"HERE IS THE GRID YOU GAVE ME:"<<endl;
    printGrid(grid);
    solve(grid,0,0);
    cout<<"HERE IS THE SOLVED GRID:"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    printGrid(grid);  
    return 0;
}