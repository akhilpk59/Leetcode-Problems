#include<iostream>
#include<vector>
#include<queue>
#include<set>

using std::vector;
using std::queue;
using std::set;

void BFS (vector<vector<char>> grid, int i, int j, int current, bool visited[], int val[], int m, int n){
    visited[(n*i)+j] = true;
    if (val[(n*i)+j]==-1) val[(n*i)+j] = current;
    queue<int> x;
    queue<int> y;
    int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    x.push(i);
    y.push(j);
    while (!x.empty()){
        int iC = x.front();
        int jC = y.front();
        for (int k=0;k<4;k++){
            int iNew = iC + dir[k][0];
            int jNew = jC + dir[k][1];
            if (iNew<0||iNew>=m||jNew<0||jNew>=n) continue;
            else if (grid[iNew][jNew]=='0') continue;
            else if (visited[(n*iNew)+jNew]) continue;
            else {
                x.push(iNew);
                y.push(jNew);
                visited[(n*iNew)+jNew] = true;
                val[(n*iNew)+jNew] = val[(n*iC)+jC];
            }
        }
        x.pop();
        y.pop();
    }
}

int numIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (m==1&&n==1) return (grid[0][0]=='0') ? 0 : 1;
    bool visited[m*n];
    int val[m*n];
    for (int i=0;i<m*n;i++){
        visited[i]= false;
        val[i] = -1;
    }
    
    int current = 1;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (grid[i][j]=='0'){
                visited[(n*i)+j] = true;
                continue;
            }
            else if (visited[(n*i)+j]) continue;
            else {
                BFS(grid,i,j,current,visited,val, m, n);
                current++;
            }
        }
    }
    set<int> colors;
    for (int i=0;i<m*n;i++){
        if (colors.find(val[i])==colors.end()) colors.insert(val[i]);
    }
    return (colors.find(-1)==colors.end()) ? colors.size() : colors.size() - 1;
}

int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    std::cout<<numIslands(grid)<<std::endl;
    return 0;
}