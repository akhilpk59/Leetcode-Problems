#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool count_check (vector<string> board, int n){
    int count = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (board[i][j]=='Q') count++;
        }
    }
    return (count==n);
}

bool q_exist(int i, int j, vector<string> Queens){
    int count = 0;
    int n = Queens.size();
    for (int k=0;k<n;k++){
        if (Queens[i][k]=='Q') count++;
    }
    for (int k=0;k<n;k++){
        if (Queens[k][j]=='Q') count++;
    }
    for (int k=1;k<n;k++){
        if ((i-k)<0||(j+k)>(n-1)) break;
        if (Queens[i-k][j+k]=='Q') count++;
    }
    for (int k=1;k<n;k++){
        if ((i-k)<0||(j-k)<0) break;
        if (Queens[i-k][j-k]=='Q') count++;
    }
    for (int k=1;k<n;k++){
        if ((i+k)>(n-1)||(j+k)>(n-1)) break;
        if (Queens[i+k][j+k]=='Q') count++;
    }
    for (int k=1;k<n;k++){
        if ((i+k)>(n-1)||(j-k)<0) break;
        if (Queens[i+k][j-k]=='Q') count++;
    }
    //if (count==0) cout<<"i : "<<i<<" j : "<<j<<endl;
    return (count!=0);
}

void clean_up(vector<string>& board){
    int n = board.size();
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            board[i][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens (int n){
    vector<vector<string>> answer;
    vector<string> board;
    string blank = "";
    for (int i=0;i<n;i++){
        blank+='.';
    }
    for (int i=0;i<n;i++){
        board.push_back(blank);
    }
    for (int k=0;k<n;k++){
        board[0][k] = 'Q';
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]=='Q') continue;
                else if (!q_exist(i,j,board)) {
                    board[i][j]='Q';
                    continue;
                }
            }
        }
        if (count_check(board,n)) answer.push_back(board);
        clean_up(board);
    }

    return answer;
}

int main(){
    int n;
    cin>>n;
    vector<vector<string>> answer = solveNQueens(n);
    for (auto val : answer){
        for (auto str : val){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}