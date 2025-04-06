#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
};

void insert (ListNode*& head, int val){
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0){
    if (l1==NULL&&l2==NULL&&carry==0) return NULL;
    else if (l1==NULL&&l2==NULL){
        ListNode* sum = new ListNode;
        sum->val = carry;
        sum->next = NULL;
        return sum;
    }
    else if (l1==NULL){
        int temp = l2->val;
        l2->val= (temp + carry)%10;
        carry = (temp + carry)/10;
        l2->next = addTwoNumbers(NULL,l2->next,carry);
        return l2;
    }
    else if (l2==NULL){
        int temp = l1->val;
        l1->val= (temp + carry)%10;
        carry = (temp + carry)/10;
        l1->next = addTwoNumbers(NULL,l1->next,carry);
        return l1;
    }
    //ListNode* temp1 = l1;
    //ListNode* temp2 = l2;
    ListNode* sum = new ListNode;
    sum->val = (l1->val + l2->val+carry)%10;
    carry = (l1->val + l2->val+carry)/10;
    sum->next = addTwoNumbers(l1->next,l2->next,carry);
    return sum;
}

void print(ListNode* head){
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}

int main(){
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    insert(l1,9);
    insert(l1,9);
    insert(l1,9);
    insert(l1,9);
    insert(l1,9);
    insert(l1,9);
    insert(l1,9);
    print (l1);
    insert(l2,9);
    insert(l2,9);
    insert(l2,9);
    insert(l2,9);
    print (l2);
    print(addTwoNumbers(l1,l2));
    return 0;
}