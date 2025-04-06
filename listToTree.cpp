#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using std::pair;
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
};

struct TreeNode{
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

TreeNode* createTree(vector<int> nums, int start, int end){
    int n = end-start+1;
    if (start>end) return NULL;
    if (n==1) return CreateNode(nums[start]);
    if (n==2){
        TreeNode* root = CreateNode(nums[end]);
        root->left = CreateNode(nums[start]);
        return root;
    }
    int mid = (end+start)/2;
    TreeNode* root = CreateNode(nums[mid]);
    root->left = createTree(nums,start,mid-1);
    root->right = createTree(nums,mid+1,end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head){
    if (head==NULL){
        TreeNode* root = NULL;
        return root;
    }
    vector<int> nums;
    while (head!=NULL){
        nums.push_back(head->val);
        head = head->next;
    }
    int n = nums.size();
    // std::cout<<"Vector : ";
    // for (auto val : nums) std::cout<<val<<" ";
    // std::cout<<std::endl;
    return createTree(nums,0,n-1);
}

void insert(ListNode*& head, int val){
    ListNode* temp = new ListNode;
    temp->next = NULL;
    temp->val = val;
    if (head==NULL){
        head = temp;
        return;
    }
    ListNode* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}
void print(ListNode* head){
    if (head==NULL) return;
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
        std::cout<<std::endl;
}

void print(TreeNode* root){
    if (root==NULL) return;
    std::queue<pair<TreeNode*, int>> q;
    pair<TreeNode*, int> temp;
    int level = 0;
    temp.first = root;
    temp.second = level;
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        TreeNode* current = temp.first;
        level = temp.second;
        std::cout<<"Value : "<<current->val<<", Level : "<<level<<" --- ";
        if (current->left!=NULL){
            pair<TreeNode*, int> store;
            store.first = current->left;
            store.second = level + 1;
            q.push(store);
        }
        if (current->right!=NULL){
            pair<TreeNode*, int> store;
            store.first = current->right;
            store.second = level + 1;
            q.push(store);
        }
        q.pop();
    }
}

int main(){
    ListNode* head = NULL;
    // insert(head,-10);
    // insert(head,-3);
    insert(head,3);
    insert(head,5);
    insert(head,8);
    // print(head);
    TreeNode* root = sortedListToBST(head);
    // std::cout<<"Did we get here?"<<std::endl;
    print(root);
    return 0;
}