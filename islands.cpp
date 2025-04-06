#include<iostream>
#include<vector>
#include<set>
using std::vector;
using std::set;

void DFS (vector<vector<char>> grid, bool visited[], int i, int j, int m, int n, int val[],int current){
    if (visited[(n*i)+j]) return;
    val[(n*i)+j] = current;
    visited[(n*i)+j] = true;
    int direction[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    for (int k=0;k<4;k++){
        int iNew = i+direction[k][0];
        int jNew = j +direction[k][1];
        if (iNew<0||iNew>=m||jNew<0||jNew>=n) continue;
        if (grid[iNew][jNew]=='0') continue;
        DFS(grid,visited,iNew,jNew,m,n,val,current);
    }
}

int numIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (m==1&&n==1) return (grid[0][0]=='0') ? 0 : 1;
    bool visited[m*n];
    set<int> colors;
    int val[m*n];
    int current = 1;
    for (int i=0;i<m*n;i++) {
        visited[i] = false;
        val[i] = -1;
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (grid[i][j]=='0') visited[(n*i)+j] = true;
            if (grid[i][j]=='1') {
                DFS(grid,visited,i,j,m,n,val,current);
                current++;
            }
        }
    }
    for (int i=0;i<m*n;i++) {
        if (colors.find(val[i])==colors.end()) colors.insert(val[i]);
    }
    return (colors.find(-1)==colors.end()) ? colors.size() : colors.size()-1;
}

int main(){
    vector<vector<char>> grid = {{'1','1'}};
    std::cout<<numIslands(grid)<<std::endl;
    return 0;
}