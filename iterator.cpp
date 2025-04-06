#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode (int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
};

class BSTIterator {
    
    TreeNode* current = new TreeNode(-1);
    TreeNode* next = NULL;
    TreeNode* refer = NULL;
    int maxim = -1;
    
    public :
    BSTIterator (TreeNode* root){
        refer = root;
        TreeNode* temp = root;
        while (temp->left!=NULL) temp = temp->left;
        next = temp;
        TreeNode* maximus = root;
        while (maximus->right!=NULL) maximus = maximus->right;
        maxim = maximus->val;
    }

    int next(){
        current = next;
        int target = current->val;
        if (next->right!=NULL) {
            TreeNode* temp = next->right;
            while (temp->left!=NULL) temp = temp->left;
            next = temp;
            return target;
        }
        TreeNode* temp = refer;
        while (temp->val!=target){
            if (temp->left!=NULL&&temp->left->val==target) {
                next = temp;
                return target;
            }
            if (temp->left->right!=NULL&&temp->left->right->val==target) {
                next = temp;
                return target;
            }
            if (temp->left!=NULL){
                TreeNode* check = temp->left;
                while (check->right!=NULL) check = check->right;
                if (check->val==target) {
                    next = temp;
                    return target;
                }
            }
            if (temp->val<target) temp = temp->right;
            else temp=temp->left;
        }
        temp = temp->right;
        if (temp==NULL) return target;
        while (temp->left!=NULL) temp = temp->left;
        next = temp;
        return target;
    }

    bool hasNext() {
        if (current->val==maxim) return false;
        else return true;
    }

};

int main(){

    return 0;
}