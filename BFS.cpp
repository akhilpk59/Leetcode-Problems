#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

struct Node {
    int val;
    Node* next;
};

void insert(Node*& head, int val){
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;

    if (head==NULL) {
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}

void BFS(Node* list[], queue<Node*>& q, bool visited[], int n, int start, int color[]){
    if (list[start]==NULL) {
        color[start] = start;
        visited[start] = true;
        return;
    }
    q.push(list[start]);
    visited[start] = true;
    if (color[start]==-1) color[start] = start;  
    Node* temp = q.front();
    while (!q.empty()){
        if (temp==NULL) temp = list[q.front()->val];
        while (temp!=NULL){
            if (!visited[temp->val]) {
                q.push(temp);
                visited[temp->val] = true;
                color[temp->val] = color[start];
            }
            temp = temp->next;
        }
        q.pop();
    }
}

void BFS (vector<vector<int>> edges, int n){
    Node* list[n];
    bool visited[n];
    int color[n];
    for (int i=0;i<n;i++) {
        list[i] = NULL;
        visited[i] = false;
        color[i] = -1;
    }
    int m = edges.size();

    for (int i=0;i<m;i++){
        int x = edges[i][0];
        int y = edges[i][1];
        insert(list[x],y);
        insert(list[y],x);
    }
    
    queue<Node*> q;
    for (int i=0;i<n;i++) BFS (list,q,visited,n,i,color);
    for (int i=0;i<n;i++) std::cout<<std::boolalpha<<visited[i]<<" "<<color[i]<<std::endl;
    std::cout<<std::endl;
}

int main(){
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{0,4},{5,6},{7,8},{9,10},{8,10},{6,4},{9,2}};
    int n;
    std::cin>>n;
    BFS (edges,n);
    return 0;
}