#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool search (TreeNode* root, TreeNode* target){
    if (root==NULL) return false;
    if (root==target) return true;
    else return search(root->left,target)||search(root->right,target);
}

TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q){
    if (root->val==p->val||root->val==q->val) return root;
    if (search(root->left,p)&&search(root->left,q)) return lowestCommonAncestor(root->left,p,q);
    else if (search(root->right,p)&&search(root->right,q)) return lowestCommonAncestor(root->right,p,q);
    else return root;
}