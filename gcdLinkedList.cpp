#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
};
int gcd(int x, int y){
    if (y<x) {
        int temp = x;
        x = y;
        y = temp;
    }
    for (int i=x;i>0;i--){
        if (y%i==0&&x%i==0) return i;
    }
    return 1;
}

ListNode* insertGreatestCommonDivisors(ListNode*& head){
    if (head->next==NULL) return head;
    //ListNode* temp = head;
    ListNode* tempNext = head->next;
    ListNode* GCD = new ListNode;
    GCD->val = gcd(head->val,head->next->val);
    head->next = GCD;
    GCD->next = insertGreatestCommonDivisors(tempNext);
    return head;
}
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
void print (ListNode* head){
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}

int main(){
    ListNode* head = NULL;
    insert(head,7);
    // insert(head,6);
    // insert(head,10);
    // insert(head,3);
    print(head);
    head = insertGreatestCommonDivisors(head);
    print(head);
    return 0;
}