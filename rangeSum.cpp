#include<iostream>
#include<vector>
using std::vector;

class NumMatrix {
    vector<vector<int>> prefix;
    int row;
    int col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        for (int i=0;i<row;i++){
            vector<int> temp;
            for (int j=0;j<col;j++){
                temp.push_back(0);
            }
            prefix.push_back(temp);
        }
    
        int rowSum[row][col];
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (j==0) rowSum[i][j] = matrix[i][j];
                else rowSum[i][j] = rowSum[i][j-1] + matrix[i][j];
            }
        }
        
        int colSum[row][col];
        for (int j=0;j<col;j++){
            for (int i=0;i<row;i++){
                if (i==0) colSum[i][j] = matrix[i][j];
                else colSum[i][j] = colSum[i-1][j] + matrix[i][j];
            }
        }
        
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (i==0&&j==0) prefix[i][j] = matrix[i][j];
                else if (i==0) prefix[i][j] = prefix[i][j-1] + matrix[i][j];
                else if (j==0) prefix[i][j] = prefix[i-1][j] + matrix[i][j]; 
                else prefix[i][j] = prefix[i-1][j-1] + rowSum[i][j]+colSum[i][j]-matrix[i][j];
            }
        }
        for (auto val:prefix){
            for (auto nums : val) std::cout<<nums<<" ";
            std::cout<<std::endl;
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1>0&&col1>0) return prefix[row2][col2] - prefix[row2][col1-1] - prefix[row1-1][col2] + prefix[row1-1][col1-1];
        else if (row1==0&&col1==0) return prefix[row2][col2];
        else if (row1==0) return prefix[row2][col2] - prefix[row2][col1-1];
        else return prefix[row2][col2] - prefix[row1-1][col2]; 
    }
};

int main(){
    vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix* name = new NumMatrix(matrix);
    std::cout<<name->sumRegion(2,1,4,3)<<std::endl;
    std::cout<<name->sumRegion(1,1,2,2)<<std::endl;
    //std::cout<<name->sumRegion(2,1,4,3)<<std::endl;
    std::cout<<name->sumRegion(1,2,2,4)<<std::endl;
    return 0;
}