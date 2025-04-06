#include<iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
void swap (int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

TreeNode* min_val_root_right(TreeNode* root){
    TreeNode* temp = root->right;
    while (temp->left!=NULL) temp = temp->left;
    return temp;
}

TreeNode* max_val_root_left(TreeNode* root){
    TreeNode* temp = root->left;
    while (temp->right!=NULL) temp = temp->right;
    return temp;
}

void recoverTree(TreeNode*& root){
    if (root==NULL) return;
    if (root->left==NULL&&root->right==NULL) return;
    if (root->left==NULL){
        if (root->right->val<root->val) {
            swap(root->val,root->right->val);
            return;
        }
        TreeNode* temp = min_val_root_right(root);
        if (temp->val<root->val) {
            swap(temp->val,root->val);
            return;
        }
        else recoverTree(root->right);
    }
    if (root->right==NULL){
        if (root->left->val>root->val) {
            swap (root->val, root->left->val);
            return;
        }
        TreeNode* temp = max_val_root_left(root);
        if (temp->val>root->val){
            swap(temp->val,root->val);
            return;
        }
        else recoverTree(root->left);
    }

    if (root->right->val<root->val){
        if (root->left->val<root->val) {
            swap(root->val,root->right->val);
            return;
        }
        else swap(root->left->val,root->right->val);
        return;
    }
    if (root->left->val>root->val){
        if (root->right->val>root->val){
        swap(root->left->val,root->val);
        return;
        }
        else swap (root->left->val,root->right->val);
        return;
    }

    TreeNode* temp1 = min_val_root_right(root);
    TreeNode* temp2 = max_val_root_left(root);
    if (temp1->val<root->val) {
        swap (temp1->val,root->val);
        return;
    }
    if (temp2->val>root->val){
        swap(temp2->val,root->val);
        return;
    }
    recoverTree(root->left);
    recoverTree(root->right);
}