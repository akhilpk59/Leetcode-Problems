#include<iostream>
#include<vector>
#include<set>
using std::vector;

struct Node {
    int val;
    Node* next;
};

void insert(Node*& head, int val){
    Node* temp = new Node;
    temp->val = val;
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

bool search(int value, Node* head){
    if (head==NULL) return false;
    while (head!=NULL){
        if (value==head->val) return true;
        head = head->next;
    }
    return false;
}

int findJudge(int n, vector<vector<int>>& trust){
    int x = trust.size();
    if (x==0) return -1;
    if (x==1){
        if (n==2) return trust[0][1];
        else return -1;
    } 
    Node* graph[n];
    for (int i=0;i<n;i++){
        Node* head = NULL;
        graph[i] = head;
    }
    for (int i=0;i<x;i++){
        int node = trust[i][0];
        insert(graph[node-1],trust[i][1]);
    }
    vector<int> judge;
    for (int i=0;i<n;i++){
        if (graph[i]==NULL) judge.push_back(i+1);
    }
    if (judge.size()!=1) return -1;
    int value = judge[0];
    for (int i=0;i<n;i++){
        if ((i!=value-1)&&!search(value,graph[i])) return -1;
    }
    return value;
}