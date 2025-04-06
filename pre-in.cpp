#include<iostream>
#include<vector>
#include<string>
#include<utility>
using std::vector;
using std::string;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* CreateNode(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(TreeNode*& root, int val, bool left){
    if (left) root->left = CreateNode(val);
    else root->right = CreateNode(val);
}

int search (int target, vector<int> nums){
    int n = nums.size();
    for (int i=0;i<n;i++){
        if (nums[i]==target) return i;
    }
    return -1;
}

vector<std::pair<string, int>> merge (vector<std::pair<string,int>> numsL, vector<std::pair<string,int>> numsR){
    int nL = numsL.size();
    int nR = numsR.size();
    vector<std::pair<string,int>> answer;
    int i = 0;
    int j = 0;
    while (i<nL&&j<nR){
        if (numsL[i].first<=numsR[j].first) answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }
    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergeSort (vector<std::pair<string,int>>& finale){
    int n = finale.size();
    if (n<=1) return;
    vector<std::pair<string,int>> finaleL;
    vector<std::pair<string,int>> finaleR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) finaleL.push_back(finale[i]);
    for (int i=mid+1;i<n;i++) finaleR.push_back(finale[i]);
    mergeSort(finaleL);
    mergeSort(finaleR);
    finale = merge(finaleL,finaleR);
    return;
}

void navigate(string temp, int value, TreeNode*& root){
    temp.erase(temp.begin());
    int n = temp.size();
    TreeNode* traveler = root;
    for (int i=0;i<n;i++){
        if (temp[i]=='L') {
            if (traveler->left!=NULL) {
                traveler = traveler->left;
                if (i==n-1) {
                    traveler->val = value;
                    return;
                }
            }
            else {
                if (i!=(n-1)) insert(traveler,3001,true);
                else {
                    insert(traveler,value,true);
                    return;
                }
                traveler = traveler->left;
            }
        }
        else {
            if (traveler->right!=NULL) {
                traveler = traveler->right;
                if (i==n-1) {
                    traveler->val = value;
                    return;
                }
            }
            else {
                if (i!=(n-1)) insert(traveler,3001,false);
                else {
                    insert(traveler,value,false);
                    return;
                }
                traveler = traveler->right;
            }
        }
    }
}

TreeNode* createTree(vector<std::pair<string,int>> finale) {
    TreeNode* root = CreateNode(finale[0].second);

    int n = finale.size();
    for (int i=1;i<n;i++){
        string temp = finale[i].first;
        int value = finale[i].second;
        navigate(temp,value,root);
    }
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    int n = preorder.size();
    TreeNode* root = CreateNode(preorder[0]);
    if (n==1) return root;
    bool done[n];
    string nodes[n];
    for (int i=0;i<n;i++) done[i] = false;
    int rootIndex = search(preorder[0],inorder);
    done[rootIndex] = true;
    nodes[rootIndex] = "0";
    bool lmost = false;
    if (rootIndex==0) lmost = true;
    //bool rflag = false;
    string current = "0";
    int prev = -1;
    for (int i=1;i<n;i++){
        int value = preorder[i];
        int index = search(value,inorder);
        if (!lmost){
            nodes[index] = current+="L";
            if (index==0) lmost = true;
        }
        else {
            if (prev<index){
                int j = index-1;
                while (j>=0){
                    if (done[j]==true) break;
                    j--;
                }
                nodes[index] = nodes[j]+"R";
            }
            else {
                nodes[index] = nodes[prev] + "L";
            }
        }
        prev = index;
        done[index] = true;
    }
    vector<std::pair<string,int>> finale;
    for (int i=0;i<n;i++){
        std::pair<string,int> temp;
        temp.first = nodes[i];
        temp.second = inorder[i];
        finale.push_back(temp);
    }
    mergeSort(finale);
    root = createTree(finale);
    return root;
}