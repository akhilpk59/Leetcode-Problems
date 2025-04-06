#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using std::vector;
using std::pair;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
};

vector<pair<Node*, int>> traverse(Node* root){
    std::queue<pair<Node*, int>> q;
    pair<Node*, int> temp;
    vector<pair<Node*, int>> answer;
    int level = 0;
    temp.first = root;
    temp.second = level;
    q.push(temp);
    while (!q.empty()){
        temp = q.front();
        answer.push_back(temp);
        Node* current = temp.first;
        level = temp.second;
        if (current->left!=NULL){
            pair<Node*, int> check;
            check.first = current->left;
            check.second = level + 1;
            q.push(check);
        }
        if (current->right!=NULL){
            pair<Node*, int> check;
            check.first = current->right;
            check.second = level + 1;
            q.push(check);
        }
        q.pop();
    }
    return answer;
}

Node* connect(Node*& root){

    if (root==NULL) return root;
    if (root->left==NULL&&root->right==NULL) return root;

    vector<pair<Node*, int>> answer = traverse(root);
    int n = answer.size();
    for (int i=0;i<n;i++){
        pair<Node*, int> temp = answer[i];
        int current = temp.second;
        if (i==0||i==n-1) continue;
        pair<Node*, int> tempNext = answer[i+1];
        int next = tempNext.second;
        if (current==next) temp.first->next = tempNext.first;
        else continue;
    }
    return root;
}