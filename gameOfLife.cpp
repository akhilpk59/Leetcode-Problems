#include<iostream>
#include<vector>
using std::vector;

void modify (vector<vector<int>> board, int i, int j, int m, int n, bool& state){
    int neighbours[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};

    if (board[i][j]==1){
        int count = 0;
        for (int k=0;k<8;k++){
            int iNew = i+neighbours[k][0];
            int jNew = j+neighbours[k][1];
            if (iNew>=m||jNew>=n||iNew<0||jNew<0) continue;
            if (board[iNew][jNew]==1) count++; 
        }
        if (count!=2&&count!=3) state = false;
        else state = true;
    }
    else {
        int count = 0;
        for (int k=0;k<8;k++){
            int iNew = i+neighbours[k][0];
            int jNew = j+neighbours[k][1];
            if (iNew>=m||jNew>=n||iNew<0||jNew<0) continue;
            if (board[iNew][jNew]==1) count++; 
        }
        if (count!=3) state = false;
        else state = true;
    }
}

void gameOfLife (vector<vector<int>>& board){
    int m = board.size();
    int n = board[0].size();
    if (m==n&&m==1) {
        board[0][0] = 0;
    }
    bool flag[m][n];
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            flag[i][j] = false;
        }
    }

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            modify(board,i,j,m,n,flag[i][j]);
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (flag[i][j]) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
}