#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
};

void insert(ListNode*& head, int val){
    ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = NULL;
    if (head==NULL) {
        head = temp;
        return;
    }
    ListNode* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}

void print(ListNode* head){
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}
ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* temp = head;
    int count = 0;
    while (temp!=NULL){
        count++;
        temp = temp->next;
    }
    temp = head;
    int loop = count - n + 1;
    if (loop == 1) {
         head = temp->next;
         delete temp;
         return head;
    }
    while (loop>2){
        temp = temp->next;
        loop--;
    }
    ListNode* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head;
}

int main(){
    ListNode* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    int n;
    std::cin>>n;
    ListNode* temp = removeNthFromEnd(head,n);
    print(temp);
    return 0;
}