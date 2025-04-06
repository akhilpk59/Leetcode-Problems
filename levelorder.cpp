#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<vector<int>> levelOrder (TreeNode* root){
    vector<vector<int>> answer;
    if (root == NULL) return answer;
    std::queue<std::pair<TreeNode*, int>> q;
    std::pair<TreeNode*, int> temp;
    int level = 0;
    temp.first = root;
    temp.second = level;
    int prev = 0;
    q.push(temp);
    vector<int> store;
    while(!q.empty()){
        std::pair<TreeNode*, int> check = q.front();
        TreeNode* current = check.first;
        level = check.second;
        if (level==prev) {
            store.push_back(current->val);
            if (current->left!=NULL){
                std::pair<TreeNode*, int> next;
                next.first = current->left;
                next.second = level + 1;
                q.push(next);
            }
            if (current->right!=NULL){
                std::pair<TreeNode*, int> next;
                next.first = current->right;
                next.second = level + 1;
                q.push(next);
            }
        }
        else {
            prev = level;
            answer.push_back(store);
            store.clear();
            store.push_back(current->val);
            if (current->left!=NULL){
                std::pair<TreeNode*, int> next;
                next.first = current->left;
                next.second = level + 1;
                q.push(next);
            }
            if (current->right!=NULL){
                std::pair<TreeNode*, int> next;
                next.first = current->right;
                next.second = level + 1;
                q.push(next);
            }
        }
        q.pop();
    }
    if (!store.empty()) answer.push_back(store);
    return answer;
}