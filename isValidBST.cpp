#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

    int max_val_root_left(TreeNode* root){
        TreeNode* temp = root->left;
        while (temp->right!=NULL) temp = temp->right;
        return temp->val;
    }

    int min_val_root_right(TreeNode* root){
        TreeNode* temp = root->right;
        while (temp->left!=NULL) temp = temp->left;
        return temp->val;
    }

bool isValidBST(TreeNode* root){
    if (root==NULL) return true;
    if (root->left==NULL&&root->right==NULL) return true;
    if (root->left==NULL) {
        if (min_val_root_right(root)>root->val) return isValidBST(root->right);
        else return false;
    }
    if (root->right==NULL){
        if (max_val_root_left(root)<root->val) return isValidBST(root->left);
        else return false;
    }
    if ((max_val_root_left(root)<root->val)&&(min_val_root_right(root)>root->val)) return isValidBST(root->left)&&isValidBST(root->right);
    else return false;
}

int main(){

    return 0;
}