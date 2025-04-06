#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
};

void deleteNode (ListNode* node){
    ListNode* temp = node;
    while (temp->next->next!=NULL) {
        temp->val = temp->next->val;
        temp = temp->next;
    }
    temp->val = temp->next->val;
    ListNode* temp1 = temp->next;
    temp->next = NULL;
    delete temp1;
}