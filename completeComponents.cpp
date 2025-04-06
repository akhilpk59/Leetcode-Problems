#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<map>
using std::vector;
using std::pair;
using std::set;
using std::map;

struct Node {
    int val;
    Node* next;
};

void insert(Node*& head, int val){
    Node* temp = new Node;
    temp->val =val;
    temp->next = NULL;

    if (head==NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}

void DFS (Node* list[],bool visited[],int n, int i, int j, vector<pair<int,int>>& color){
    if (visited[i]) return;
    visited[i]= true;
    pair<int,int> temp;
    temp.first = i;
    temp.second = j;
    color.push_back(temp);
    Node* head = list[i];
    while (head!=NULL){
        DFS(list,visited,n,head->val,j,color);
        head = head->next;
    }
}

bool search(Node* list[],int i, int j){
    Node* head = list[i];
    while (head!=NULL){
        if (head->val==j) return true;
        head = head->next;
    }
    return false;
}

bool check (set<int> vertices, Node* list[]){
    if (vertices.size()==1) return true;
    
    for (auto it = vertices.begin();it!=vertices.end();it++){
        for (auto itr = vertices.begin();itr!=vertices.end();itr++){
            if (*it==*itr) continue;
            if (!search(list,*it,*itr)) return false;
        }
    }
    return true;
}

int countCompleteComponents (int n, vector<vector<int>>& edges){
    if (n==1) return 1;
    int m = edges.size();
    Node* list[n];
    bool visited[n];
    for (int i=0;i<n;i++){
        Node* head = NULL;
        list[i] = head;
        visited[i] = false;
    }
    for (int i=0;i<n;i++) std::cout<<visited[i]<<" ";
    std::cout<<std::endl;
    for (int i=0;i<m;i++){
        insert(list[edges[i][0]],edges[i][1]);
        insert(list[edges[i][1]],edges[i][0]);
    }
    vector<pair<int,int>> color;
    for (int i=0;i<n;i++){
        DFS(list,visited,n,i,i,color);
    }
    for (int i=0;i<n;i++) std::cout<<visited[i]<<" ";
    std::cout<<std::endl;
    set<int> colors;
    for (auto val : color){
        std::cout<<"Node : "<<val.first<<", and color : "<<val.second<<std::endl;
        colors.insert(val.second);
    }
    map<set<int>,int> link;
    for (auto it = colors.begin();it!=colors.end();it++){
        int colour = *it;
        set<int> vertices;
        for (auto val : color){
            if (val.second==colour) vertices.insert(val.first);
        }
        link[vertices] = colour;
    }
    int count = 0;
    for (auto it = link.begin();it!=link.end();it++){
        if (check(it->first,list)) count++;
    }
    return count;
}

int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    std::cout<<countCompleteComponents(6,edges)<<std::endl;
    return 0;
}