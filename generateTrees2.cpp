#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool equate (TreeNode* T1, TreeNode* T2){
    if (T1==NULL&&T2==NULL) return true;
    else if (T1==NULL||T2==NULL) return false;
    if (T1->val!=T2->val) return false;
    return equate(T1->left,T2->left)&&equate(T1->right,T2->right);
}

int numTrees(int n){
    if (n==1) return 1;
    
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<numTrees(n)<<std::endl;
    return 0;
}