#include<iostream>
#include<vector>
using std::vector;

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
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}

void print(Node* head){
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}

void DFS (Node* list[], int source, bool visited[],int n){
    if (visited[source]) return;
    visited[source] = true;
    Node* head = list[source];
    while (head!=NULL){
        DFS(list,head->val,visited,n);
        head = head->next;
    }
    return;
}

void DFS (vector<vector<int>> edges, int source, int n){
    Node* list[n];
    for (int i=0;i<n;i++){
        Node* head = NULL;
        list[i] = head;
    }
    int m = edges.size();
    for (int i=0;i<m;i++){
        int n1 = edges[i][0];
        int n2 = edges[i][1];
        insert(list[n1],n2);
        insert(list[n2],n1);
    }
    // for (int i=0;i<n;i++) print(list[i]);
    bool visited[n];
    for (int i=0;i<n;i++) visited[i] = false;
    DFS(list,source,visited,n);
    for (int i=0;i<n;i++) std::cout<<std::boolalpha<<visited[i]<<" ";
}


int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{4,5},{3,4}};
    int n;
    std::cin>>n;
    DFS(edges,n,6);
    return 0;
}