#include<iostream>
#include<map>

using std::map;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

ListNode* detectCycle(ListNode* head){
    map<ListNode*, int> nodes;
    if (head==NULL) return NULL;
    ListNode* temp = head;
    int ind = 0;

    while (temp!=NULL){
        if (nodes.find(temp)==nodes.end()) nodes[temp] = ind++; 
        else return temp;
        temp = temp->next;
    }
    return NULL;
}

