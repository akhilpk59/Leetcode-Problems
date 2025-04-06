#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>

using std::vector;
using std::string;
using std::pair;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

void print(TreeNode* root){
    if (root==NULL) return;
    std::queue<pair<TreeNode*, int>> q;
    int level = 0;
    pair<TreeNode*, int> temp;
    temp.first = root;
    temp.second = level;
    q.push(temp);
    while (!q.empty()){
        temp = q.front();
        std::cout<<"Value: "<<temp.first->val<<" Level : "<<temp.second<<" --- ";
        if (temp.first->left!=NULL){
            pair<TreeNode*, int> tempo;
            tempo.first = temp.first->left;
            tempo.second = temp.second + 1;
            q.push(tempo);
        }
        if (temp.first->right!=NULL){
            pair<TreeNode*, int> tempo;
            tempo.first = temp.first->right;
            tempo.second = temp.second + 1;
            q.push(tempo);
        }
        q.pop();
    }
    
}

TreeNode* CreateNode (int val){
    TreeNode* root = new TreeNode;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int search (int val, vector<int> inorder){
    int n = inorder.size();
    for (int i=0;i<n;i++) {
        if (inorder[i]==val) return i;
    }
    return -1;
}

vector<pair<string,int>> merge(vector<pair<string,int>> numsL, vector<pair<string,int>>  numsR){
    int nL = numsL.size();
    int nR = numsR.size();
    int i = 0;
    int j = 0;
    vector<pair<string,int>> answer;
    while (i<nL&&j<nR){
        if (numsL[i].first<=numsR[j].first) answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }
    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergeSort(vector<pair<string,int>>& finale){
    int n = finale.size();
    if (n<=1) return;
    vector<pair<string,int>> finaleL;
    vector<pair<string,int>> finaleR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) finaleL.push_back(finale[i]);
    for (int i=mid+1;i<n;i++) finaleR.push_back(finale[i]);
    mergeSort(finaleL);
    mergeSort(finaleR);
    finale = merge(finaleL,finaleR);
    return;
}

void insert(TreeNode*& root, int value, bool left){
    if (left) root->left = CreateNode(value);
    else root->right = CreateNode(value);
}

void navigate(TreeNode*& root, pair<string,int> temp){
    string move = temp.first;
    int value = temp.second;
    move.erase(move.begin());
    TreeNode* traveler = root;
    int n = move.size();
    for (int i=0;i<n;i++){
        if (move[i]=='L') {
            if (traveler->left!=NULL) traveler = traveler->left;
            if (i==n-1) {
                if (traveler->left==NULL)traveler->left = CreateNode(value);
                else traveler->left->val = value;
                return;
            }
          
        }
        else {
            if (traveler->right!=NULL) traveler = traveler->right;
            if (i==n-1){
                if (traveler->right==NULL) traveler->right = CreateNode(value);
                else traveler->right->val = value;
                return;
            }
        }
    }
}

TreeNode* createTree(vector<pair<string,int>> finale){
    int n = finale.size();
    TreeNode* root = CreateNode(finale[0].second);
    for (int i=1;i<n;i++){
        pair<string,int> temp = finale[i];
        navigate(root,temp);
    }
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    int n = inorder.size();
    if (n==1){
        TreeNode* root = CreateNode(inorder[0]);
        return root;
    }
    int rootVal = postorder[n-1];
    int rootIndex = search(rootVal,inorder);
    bool rmost = false;
    if (rootIndex==n-1) rmost = true;
    int prev = rootIndex;
    bool done[n];
    for (int i=0;i<n;i++) done[i] = false;
    string nodes[n];
    done[rootIndex] = true;
    nodes[rootIndex] = "0";
    string temp = "0";
    for (int i=n-2;i>=0;i--){
        int currentValue = postorder[i];
        int currentIndex = search(currentValue,inorder);
        if (!rmost){
            if (currentIndex==n-1) rmost = true;
            temp+="R";
            nodes[currentIndex] = temp;

        }
        else {
            if (prev>currentIndex) {
                int j = prev - 1;
                while (j>currentIndex) {
                    if (!done[j]) break;                
                    j--;
                }
                j++;
                nodes[currentIndex] = nodes[j] + "L";
            }
            else {
                nodes[currentIndex] = nodes[prev] + "R";
            }

        }
        prev = currentIndex;
        done[currentIndex] = true;
    }

    vector<pair<string, int>> finale;
    for (int i=0;i<n;i++){
        pair<string,int> temp;
        temp.first = nodes[i];
        temp.second = inorder[i];
        finale.push_back(temp);
    }   
    mergeSort(finale);
    for (auto val : finale) {
        std::cout<<val.second<<" "<<val.first<<std::endl;
    }
    TreeNode* root = createTree(finale);
    return root;
}

int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    print(buildTree(inorder,postorder));
    return 0;
}