#include<iostream>
#include<vector>

using std::vector;

int minPathSum(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (m==1&&n==1) return grid[0][0];
    int arr[m][n];
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    arr[0][0] = grid[0][0];
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (i+1<m){
                int temp = arr[i][j] + grid[i+1][j];
                if (arr[i+1][j]==0||arr[i+1][j]>temp) arr[i+1][j] = temp;
            }
            if (j+1<n){
                int temp = arr[i][j] + grid[i][j+1];
                if (arr[i][j+1]==0||arr[i][j+1]>temp) arr[i][j+1] = temp;
            }
        }
    }
    return arr[m-1][n-1];
}

int main(){
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    std::cout<<minPathSum(grid)<<std::endl;
    return 0;
}