#include<iostream>
#include<vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<vector<int>> pathsum (TreeNode* root, int targetsum){
    vector<vector<int>> answer;
    if (root==NULL) return answer;
    if (root->left==NULL&&root->right==NULL){
        if (root->val==targetsum){
            vector<int> temp;
            temp.push_back(root->val);
            answer.push_back(temp);
            return answer;
        }
        else return answer;
    }
    vector<vector<int>> remL = pathsum(root->left,targetsum-root->val);
    vector<vector<int>> remR = pathsum(root->right,targetsum-root->val);
    int nL = remL.size();
    int nR = remR.size();
    for (int i=0;i<nL;i++){
        remL[i].insert(remL[i].begin(),root->val);
        answer.push_back(remL[i]);
    }
    for (int i=0;i<nR;i++){
        remR[i].insert(remR[i].begin(),root->val);
        answer.push_back(remR[i]);
    }
    return answer;
}

