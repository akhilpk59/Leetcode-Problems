#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using std::queue;
using std::pair;
using std::vector;

int power(int n){
    if (n==0) return 1;
    else return 2* power(n-1);
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(NULL) , right(NULL) {}
    TreeNode(int x) : val(x) , left(NULL), right(NULL) {}
    TreeNode (int x, TreeNode* left, TreeNode* right) : val(x) , left(left), right(right) {}
};

int countNodes(TreeNode* root){
    if (root==NULL) return 0;
    int maxHeight = 0;
    TreeNode* temp = root;
    while (temp->left!=NULL) {
        temp = temp->left;
        maxHeight++;
    }
    if (maxHeight==0) return 1;
    int nodes = power(maxHeight)-1;
    
    queue<pair<TreeNode*,int>> q;
    pair<TreeNode*, int> tempo;
    tempo.first = root;
    tempo.second = 0;
    q.push(tempo);
    vector<TreeNode*> collect;
    while (!q.empty()){
        pair<TreeNode*, int> current = q.front();
        TreeNode* here = current.first;
        int level = current.second;
        if (level==maxHeight) break;
        if (here->left!=NULL){
            pair<TreeNode*, int> lc;
            lc.first = here->left;
            lc.second = level + 1;
            q.push(lc);
            if (lc.second==maxHeight) collect.push_back(lc.first);
        }
        if (here->right!=NULL){
            pair<TreeNode*, int> rc;
            rc.first = here->right;
            rc.second = level + 1;
            q.push(rc);
            if (rc.second==maxHeight) collect.push_back(rc.first);
        }
        q.pop();
    }
    nodes+=collect.size();
    return nodes;
}