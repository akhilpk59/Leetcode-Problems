#include<iostream>
#include<vector>

using std::vector;

struct ListNode{
    int  val;
    ListNode* next;
};
void insert(ListNode*& head, int val){
    ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = NULL;

    if (head==NULL){
        head = temp;
        return;
    }
    ListNode* temp1 = head;
    while(temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}

void del (ListNode*& head, int val, int node){
    if (head==NULL) return;
    if (head->next==NULL) return;
    ListNode* temp = head;
    
    while(temp->val!=node) temp = temp->next;

    ListNode* temp1 = temp;

    while(temp1->next->val!=val) temp1 = temp1->next;
    ListNode* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
    return;
}

void insert(ListNode*& head,int val, int node){
    ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = NULL;
    
    if (head->val == node){
        temp->next = head;
        head = temp;
        return;
    }

    ListNode* temp1 = head;
    while (temp1->next->val!=node) temp1 = temp1->next;
    ListNode* temp2 = temp1->next;
    temp1->next = temp;
    temp->next = temp2;
    return;
}

ListNode* partition(ListNode*& head, int x){
    if (head==NULL||head->next==NULL) return head;
    ListNode* temp = head;
    vector<int> nums;
    int count = 1;
    int store = 201;
    while (temp!=NULL){
        if (temp->val>=x) {
            store = temp->val;
            break;
        }
        else {
            count++;
            temp = temp->next;
        }
    }
    if (store==201) return head;

    temp = head;
    while (temp!=NULL) {
        while (count>0){
            temp = temp->next;
            count--;
        }
        if (temp==NULL) break;
        if (temp->val<x) nums.push_back(temp->val);
        temp = temp->next;
    }
    int n = nums.size();
    for (int i=0;i<n;i++){
        del(head,nums[i],store);
    }
    for (int i=0;i<n;i++){
        insert(head,nums[i],store);
    }
    return head;
}
void print(ListNode* head){
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}

int main(){
    ListNode* head = NULL; //-1,2,1,3,5,1
    insert(head, 1);
    insert(head, 3);
    insert(head, -1);
    insert(head, 5);
    insert(head, 2);
    insert(head, 1);
    print(head);
    partition(head,3);
    print(head);
    return 0;
}