#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<string>

using std::vector;
using std::string;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

string convert(int m, int n){
    string temp = "";
    char a = '0' + m;
    char b = '0' + n;
    temp+=a+b;
    return temp;
}

string print(TreeNode* head){
    string answer = "";
    if (head==NULL) return answer;
    std::queue<std::pair<TreeNode*, int>> q;
    int level = 0;
    std::pair<TreeNode*,int> temp;
    temp.first = head;
    temp.second = level;
    q.push(temp);
    while (!q.empty()){
        std::pair<TreeNode*, int> now = q.front();
        TreeNode* temp1 = now.first;
        int value = now.second;
        answer+=convert(temp1->val,value);
        if (temp1->left!=NULL) {
            std::pair<TreeNode*, int> L;
            L.first = temp1->left;
            L.second = value+1;
            q.push(L);
        }
        if (temp1->right!=NULL){
            std::pair<TreeNode*, int> L;
            L.first = temp1->right;
            L.second = value+1;
            q.push(L);
        }
        q.pop();
    }
    return answer;
}

void printing(TreeNode* head){
    if (head==NULL) return;
    std::queue<TreeNode*> q;
    q.push(head);
    while (!q.empty()){
        std::cout<<q.front()->val<<" ";
        if (q.front()->left!=NULL) q.push(q.front()->left);
        if (q.front()->right!=NULL) q.push(q.front()->right);
        q.pop();
    }
    std::cout<<std::endl;
}

TreeNode* NewNode (int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(TreeNode*& head, int val){
    if (head==NULL) {
        TreeNode* temp = NewNode(val);
        head = temp; 
        return;
    }
    if (head->val>val) insert(head->left,val);
    else insert(head->right, val);
}
// std::map<vector<int>,int> result;

vector<TreeNode*> generateTrees(vector<int> nums){
    // if (result.find(nums)!=result.end()) return result[nums];
    vector<TreeNode*> answer;
    int n = nums.size();
    if (n==1){
        TreeNode* head = NULL;
        insert(head,nums[0]);
        answer.push_back(head);
        return answer;
    }
    for (int i=0;i<n;i++){
        int val = nums[i];
        vector<int> temp = nums;
        temp.erase(temp.begin()+i);
        vector<TreeNode*> rem = generateTrees(temp);
        for (auto it = rem.begin();it!=rem.end();it++){
            insert(*it,nums[i]);
            answer.push_back(*it);
        }
    }
    std::map<string,TreeNode*> check;
    for (auto val : answer) {
        string temp = print(val);
        if (check.find(temp)==check.end()){
            check[temp] = val;
        }
    }
    answer.clear();
    for (auto it = check.begin(); it!=check.end();it++){
        answer.push_back(it->second);
    }
    // result[nums] = answer;
    return answer;
}

vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> answer;
    if (n==1){
       TreeNode* head = NULL;
       insert(head,1);
       answer.push_back(head);
       return answer;
    }
    vector<int> nums;
    for (int i=1;i<=n;i++) nums.push_back(i);
    answer = generateTrees(nums);
    return answer;
}

int main(){
    int n;
    std::cin>>n;
    vector<TreeNode*> answer = generateTrees(n);
    for (auto val : answer){
        printing(val);
    }
    return 0;
}