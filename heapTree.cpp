#include<iostream>

struct Tree {
    int val;
    Tree* left;
    Tree* right;
    Tree* parent;
};

Tree* Create(int val){
    Tree* temp = new Tree;
    temp->left = temp->right = temp->parent = NULL;
    temp->val = val;
    return temp;
}

void insert(Tree*& root, int value, Tree*& current){
    current = Create(value);
    current->parent = root;
}

void heapCreate (Tree*& root, int arr[], int n){
    if (n==0) return;
    if (root==NULL) root = Create(arr[0]);
    if (n==1) return;
    Tree* current = root->left;
    Tree* parent = root;
    for (int i=1;i<n;i++){
        insert(parent,arr[i],current);
    }
}

int main(){

    int arr[] = {10,15,20,5,25,35,30,40,3,27,1,212,79,34,16,54,6};
    Tree* root = NULL;
    int n = sizeof(arr)/sizeof(arr[0]);
    heapCreate(root,arr,n);
    return 0;
}