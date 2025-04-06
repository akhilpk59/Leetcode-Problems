#include<iostream>
#include<vector>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void inorder(TreeNode* root, vector<int>& answer){
    if (root==NULL) return;
    inorder(root->left, answer);
    answer.push_back(root->val);
    inorder(root->right,answer);
}

int kthSmallest (TreeNode* root, int k){
    vector<int> answer;
    inorder(root,answer);
    return answer[k-1];
}