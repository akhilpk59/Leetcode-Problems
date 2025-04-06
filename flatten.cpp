#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string>

using std::string;
using std::vector;
using std::pair;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* CreateNode(int val){
    TreeNode* root = new TreeNode;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

vector<int> preorder(TreeNode* root){
    vector<int> answer;
    if (root==NULL) return answer;
    if (root->left==NULL&&root->right==NULL){
        answer.push_back(root->val);
        return answer;
    }
    vector<int> answerL = preorder(root->left);
    vector<int> answerR = preorder(root->right);
    answer.push_back(root->val);
    for (auto val : answerL) answer.push_back(val);
    for (auto val : answerR) answer.push_back(val);
    return answer;
}

void flatten (TreeNode*& root){
    if (root==NULL) return;
    if (root->left==NULL&&root->right==NULL) return;
    vector<int> answer = preorder(root);
    int n = answer.size();
    delete root;
    root = NULL;
    root = CreateNode(answer[0]);
    TreeNode* traveler = root;
    for (int i=1;i<n;i++){
        traveler->right = CreateNode(answer[i]);
        traveler = traveler->right;
    }
}
void print (TreeNode* root){
    if (root==NULL) return;
    std::queue<pair<TreeNode*, string>> q;
    pair<TreeNode*, string> temp;
    int level = 0;
    char tempC = '0' + level;
    string value = "N";
    value = tempC + value;
    temp.first = root;
    temp.second = value;
    q.push(temp);
    while (!q.empty()){
        temp = q.front();
        TreeNode* current = temp.first;
        value = temp.second;
        level = value[0]-48;
        std::cout<<"Value : "<<current->val<<", Level : "<<level<<" and Child : "<<value[1]<<" ==//== ";
        if (current->left!=NULL){
            pair<TreeNode*, string> tempo;
            tempo.first = current->left;
            int childLevel = level + 1;
            tempC = '0' + childLevel;
            value = "";
            value+= tempC;
            value+= "L";
            tempo.second = value;
            q.push(tempo);
        }
        if (current->right!=NULL){
            pair<TreeNode*, string> tempo;
            tempo.first = current->right;
            int childLevel = level + 1;
            tempC = '0' + childLevel;
            value = "";
            value+= tempC;
            value+= "R";
            tempo.second = value;
            q.push(tempo);
        }
        q.pop();
    }
    std::cout<<std::endl;
}

int main(){
    TreeNode* root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(5);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(4);
    root->right->right = CreateNode(6);

    print (root);
    flatten(root);
    print(root);

    return 0;
}