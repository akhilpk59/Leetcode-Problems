#include<iostream>
#include<string>
using std::string;

bool check(string answer, string s){
if (answer==s) return true;
int nA = answer.length();
int nS = s.length();
std::cout<<nA<<" "<<nS<<std::endl;
if (nA!=nS) return false;
std::cout<<"we got here"<<std::endl;
for (int i=0;i<nA;i++){
    auto f = s.find(answer[i]);
    if (f==string::npos) return false;
    s.erase(f,1);
}
return true;
}

string convert(string s, int numRows){
    int n = s.length();
    if (numRows==1||numRows>=n) return s;
    int num = (numRows*2) - 2;
    int q = n/num;
    int r = n%num;
    int bCols = numRows - 1;
    int numCols;
    if (q!=0){
    if (r/numRows!=0) numCols = (q*bCols) + (r-numRows) + 1;
    else numCols = (q*bCols) + 1;
    //if (r%numRows==0) numCols--;
    }
    else {
       numCols = 1 + (n-numRows); 
    }
    //int numCols = (q*bCols) + (r/numRows) + 1;
    if (r%numRows==0) numCols--;
    char arr[numRows][numCols];
    for (int i=0;i<numRows;i++){
        for (int j=0;j<numCols;j++){
            arr[i][j] = ' ';
        }
    }
    for (int i=0;i<n;i++){
        int q1 = i/num;
        int r1 = i%num;
        int k = -1;
        int j = -1;
        if (r1>bCols){
          //  int j = (q1*(2*(numRows - 1) - r1))-2;
            j = q1*bCols + (r1-bCols);
            k = 2*bCols - r1;
        } 
        else {
            k = r1;
            j = q1*bCols;
        }
        arr[k][j] = s[i];
    }
    string answer = "";
    int count = 0;
    for (int i=0;i<numRows;i++){
        for (int j=0;j<numCols;j++){
            if ((arr[i][j]<='z'&&arr[i][j]>='a')||(arr[i][j]<='Z'&&arr[i][j]>='A')||arr[i][j]=='.'||arr[i][j]==',') {
                answer+=arr[i][j];
                count++;
                std::cout<<"Count : "<<count<<" arr[i][j] : "<<arr[i][j]<<" "<<i<<" "<<j<<std::endl;
            }
        }
    }
    return answer;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string answer = convert(s,numRows);
    std::cout<<answer<<std::endl;
    std::cout<<std::boolalpha<<check(answer,s)<<std::endl;
    return 0;
}