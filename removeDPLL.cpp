#include<iostream>
#include<set>

struct ListNode{
    int val;
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

void del (ListNode*& head, int val){
    if (head==NULL) return;
    if (head->next==NULL&&head->val==val){
        delete head;
        head = NULL;
        return;
    }
    ListNode* temp = head;
    if (temp->val==val){
        ListNode* temp1 = head->next;
        head = temp1;
        delete temp;
        del(head,val);
    }
    else {
    while (temp->next!=NULL&&temp->next->val!=val) temp = temp->next;
    if (temp->next==NULL) return;
    if (temp->next->val==val){
        ListNode* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        del(head,val);
    }
    }
}
void print (ListNode* head){
    while (head!=NULL){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}

ListNode* deleteDuplicates (ListNode*& head){
    if (head==NULL) return head;
    else if (head->next==NULL) return head;

    std::set <int> check;
    int count = 1;
    int temp = head->val;
    ListNode* tempPtr = head->next;

    while (tempPtr!=NULL){
        if (tempPtr->val==temp){
            count++;
            if (count>1) check.insert(tempPtr->val);
        }
        else {
            temp = tempPtr->val;
            count = 1;
        }
        tempPtr = tempPtr->next;
    }

    for (auto it=check.begin();it!=check.end();it++){
        del(head,*it);
    }
    return head;
}

int main(){
    ListNode* head = NULL;
    insert(head,1);
    insert(head,1);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    // insert(head,4);
    // insert(head,5);
    print(head);
    head = deleteDuplicates(head);
    print(head);
    return 0;
}