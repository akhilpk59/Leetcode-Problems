#include<iostream>
#include<string>
#include<vector>

using namespace std;

string D2S (int n){
    if (n==0) return "0";
    string ans = "";
    while (n!=0){
        char temp = '0' + (n%10);
        ans = temp + ans;
        n/=10;
    }
    return ans;
}
bool repeat(string num){
    int n = num.length();
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (num[i]==num[j]) return true;
        }
    }
    return false;
}

bool match(string num){
    int n = num.length();
    if (n==0) return false;
    if (n==1) {
        if (num!="1") return false;
    }
    if (n==2) {
        for (int i = 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2') return false;
        }
    }
    if (n==3) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3') return false;
        }
    }
    if (n==4) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4') return false;
        }
    }
    if (n==5) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4'&&num[i]!='5') return false;
        }
    }
    if (n==6) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4'&&num[i]!='5'&&num[i]!='6') return false;
        }
    }
    if (n==7) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4'&&num[i]!='5'&&num[i]!='6'&&num[i]!='7') return false;
        }
    }
    if (n==8) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4'&&num[i]!='5'&&num[i]!='6'&&num[i]!='7'&&num[i]!='8') return false;
        }
    }
    if (n==9) {
        for (int i= 0;i<n;i++){
            if (num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4'&&num[i]!='5'&&num[i]!='6'&&num[i]!='7'&&num[i]!='8'&&num[i]!='9') return false;
        }
    }
    return true;
}

int abs(int m, int n){
    return (m>n) ? m-n : n-m;
}

bool num_check (int n){
    string num = D2S(n);
    if (repeat(num)) return false;
    if (!match(num)) return false;
    int l = num.length();
    for (int i=0;i<l;i++){
       for (int j=i+1;j<l;j++){
        if (abs(i,j)==abs(num[i],num[j])) return false;
       }
    }
    return true;
}

int begin (int n){
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 11;
    if (n==3) return 111;
    if (n==4) return 2413;
    if (n==5) return 13524;
    if (n==6) return 246135;
    if (n==7) return 1357246;
    if (n==8) return 11111111;
    if (n==9) return 111111111;
    if (n>9||n<0) return -1;
}
int last (int n){
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 22;
    if (n==3) return 333;
    if (n==4) return 3142;
    if (n==5) return 53142;
    if (n==6) return 531642;
    if (n==7) return 7531642;
    if (n==8) return 88888888;
    if (n==9) return 999999999;
    if (n>9||n<0) return -1;
}

void clean(vector<string>& board){
    int n = board.size();
    for (int i=0;i<n;i++){
        for (int j = 0;j<n;j++){
            board[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> answer;
    if (n>9||n<1) {
        cout<<"The given number is beyond the boundary conditions, hence no result"<<endl;
        return answer;
    }
    if (n==2||n==3) return answer;
    if (n==1) {
        vector<string> board;
        string queen = "Q";
        board.push_back(queen);
        answer.push_back(board);
        return answer;
    }
    vector<string> board;
    string blank = "";
    for (int i=0;i<n;i++){
        blank+='.';
    }
    for (int i=0;i<n;i++){
        board.push_back(blank);
    }
    int start = begin(n);
    int end = last(n);
    vector<int> valid;

    for (int i = start;i<=end;i++){
        if (num_check(i)) valid.push_back(i);
    }
    int l = valid.size();
    cout<<"number of combinations : "<<l<<endl;
    for (int i=0;i<l;i++){
       // cout<<valid[i]<<" ";
        for (int k=n-1;k>=0;k--){
            board[k][(valid[i]%10)-1] = 'Q';
            valid[i]/=10;
        }
        answer.push_back(board);
        clean(board); 
    }
    return answer;
}

int main(){
    int n;
    cin>>n;
    vector<vector<string>> board;
    board = solveNQueens(n);
   // cout<<endl;
    for (auto val : board){
        for (auto str : val){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}