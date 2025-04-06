#include<iostream>
#include<vector>
#include<set>
using std::vector;
using std::set;

void checking (vector<vector<char>> grid, int i, int j, int current, int val[], bool visited[], int m, int n){
    visited[(n*i)+j] = true;
    int original;
    if (val[(n*i)+j]==-1) {
        val[(n*i)+j] = current;
        original = current;
    }
    else original = val[(n*i)+j];
    int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int k=0;k<4;k++){
        int iNew = i + dir[k][0];
        int jNew = j + dir[k][1];
        if (iNew<0||iNew>=m||jNew<0||jNew>=n) continue;
        else if (grid[iNew][jNew]=='0'){
            visited[(n*iNew)+jNew] = true;
            continue;
        }
        else if (visited[(n*iNew)+jNew]) continue;
        else {
            checking (grid,iNew,jNew,original,val,visited,m,n);
        }
    }
}

int numIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (m==1&&n==1) return (grid[0][0]=='0') ? 0 : 1;
    bool visited[m*n];
    int val[m*n];
    for (int i=0;i<m*n;i++){
        visited[i] = false;
        val[i] = -1;
    }
    int current = 0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (grid[i][j]=='0') visited[n*(i)+j] = true;
            else if (visited[n*(i)+j]) continue;
            else {
                checking(grid,i,j,current,val,visited, m, n);
                current++;
            }
        }
    }
    set<int> colors;
    for (int i=0;i<m*n;i++) {
        if (colors.find(val[i])==colors.end()) colors.insert(val[i]);
    }
    return (colors.find(-1)==colors.end()) ? colors.size() : colors.size()-1;
}
int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    std::cout<<numIslands(grid)<<std::endl;
    return 0;
}