#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
};

void reorderList(ListNode*& head){
    if (head==NULL||head->next==NULL) return;
    ListNode* temp = head;
    while(temp->next->next!=NULL) temp = temp->next;
    ListNode* temp1 = temp->next;
    temp->next = NULL;
    ListNode* temp2 = head->next;
    head->next = temp1;
    temp1->next = temp2;
    reorderList(temp2);
}