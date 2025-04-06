#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL){}
    ListNode(int x) : val{x},next(NULL) {}
    ListNode (int x,ListNode* next) : val(x), next(next){}
};

ListNode* insertionSortList (ListNode* head){

    ListNode* answer = new ListNode(head->val);
    ListNode* temp = head->next;

    while (temp!=NULL){
        ListNode* temp1 = answer;
        bool flag = false;
        while (temp1->next!=NULL){
            if (temp1->val>temp->val){
                ListNode* newTemp = new ListNode(temp->val, temp1);
                answer = newTemp;
                flag = true;
                break;
            }
            else if (temp1->next->val<=temp->val) {
                temp1 = temp1->next;
            }
            else {
                ListNode* temp2 = temp1->next;
                ListNode* tempNew = new ListNode(temp->val, temp2);
                temp1->next = tempNew;
                flag = true;
                break;
            }
        }
        if (flag) {
            temp = temp->next;
            continue;
        }
        if (temp1==answer&&temp1->next==NULL){
            if (temp->val<temp1->val){
                ListNode* newTemp = new ListNode(temp->val,temp1);
                answer = newTemp;
            }
            else {
                ListNode* newTemp = new ListNode(temp->val);
                temp1->next = newTemp;
            }
        }
        else if (temp1->next==NULL) {
            ListNode* tempLast = new ListNode(temp->val);
            temp1->next = tempLast;
        }
        temp = temp->next;
    }

   return answer;
}

int main(){
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(1,head);
    ListNode* node3 = new ListNode(2,node2);
    ListNode* node4 = new ListNode(4, node3);

    ListNode* result = node4;

    while (result!=NULL){
        std::cout<<result->val<<" ";
        result = result->next;
    }
    std::cout<<std::endl;

    result = insertionSortList(node4);
    
    while (result!=NULL){
        std::cout<<result->val<<" ";
        result = result->next;
    }
    std::cout<<std::endl;
    return 0;
}