#include<iostream>
#include<vector>
#include<map>
using std::vector;
using std::map;


void MHT(int i, vector<vector<int>> tree, int n, bool visited[], int value[], map<int,int>& temp, int current = 0){
    if (visited[i]) return;
    visited[i] = true;
    value[i] = current;
    if (temp.find(i)==temp.end()) temp[i] = current;
    for (int j=0;j<n;j++){
        if (tree[i][j]==0) continue;
        if (visited[j]) continue;
        MHT (j,tree,n,visited,value,temp,current+1);
    }    
}

int maxim(map<int,int> temp){
    int maximum = 0;
    for (auto it = temp.begin();it!=temp.end();it++){
        if (it->second>maximum) maximum = it->second;
    }
    return maximum;
}

void reset(bool visited[], int n){
    for (int i=0;i<n;i++) visited[i] = false;
}

void reset(int value[], int n){
    for (int i=0;i<n;i++) value[i] = 0;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
    vector<int> answer;
    if (n==1) {
        answer.push_back(0);
        return answer;
    }
    if (n==2){
        answer.push_back(0);
        answer.push_back(1);
        return answer;
    }
    vector<vector<int>> tree;
    for (int i=0;i<n;i++){
        vector<int> temp;
        for (int j=0;j<n;j++){
            temp.push_back(0);
        }
        tree.push_back(temp);
    }

    int m = edges.size();
    for (int i=0;i<m;i++){
        int x = edges[i][0];
        int y = edges[i][1];
        tree[x][y] = 1;
        tree[y][x] = 1;
    }
    bool visited[n];
    int value[n];
    for (int i=0;i<n;i++) {
        visited[i] = false;
        value[i] = 0;
    }
    map<int,int> store; 
    for (int i=0;i<n;i++){
        map<int,int> temp;
        MHT(i,tree,n,visited,value,temp);
        store[i] = maxim(temp);
        reset(visited,n);    
        reset (value,n);
    }
    int minim = n*2;
    for (auto it = store.begin();it!=store.end();it++){
        if (it->second<minim) minim = it->second;
    }
    for (auto it = store.begin();it!=store.end();it++){
        if (it->second==minim) answer.push_back(it->first);
    }
    return answer;
}

int main(){

    return 0;
}