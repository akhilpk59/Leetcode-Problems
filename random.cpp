#include<iostream>

struct Node {
    int val;
    Node* next;
    Node* random;
     Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

int count (Node* head, Node* random){
    if (random==NULL) return -1;
    Node* temp = head;
    int check = 0;
    while (temp!=NULL){
        if (random==temp) return check;
        check++;
        temp = temp->next;
    }
    return -1;
}

Node* target(Node* head, int count){
    Node* temp = head;
    while (count>0){
        temp = temp->next;
        count--;
    }
    return temp;
}

Node* copyRandomList (Node* head){
    if (head==NULL) return NULL;

    Node* temp1 = head;
    Node* prev = NULL;
    Node* headnew = NULL;
    while (temp1!=NULL){
        Node* temp = new Node(temp1->val);
        temp->val = temp1->val;
        temp->next = NULL;
        temp->random = NULL;
        if (prev!=NULL) prev->next = temp;
        if (prev==NULL) headnew = temp;
        prev = temp;
        temp1 = temp1->next;
    }
    temp1 = head;
    prev = headnew;
    while (temp1!=NULL){
        int num = count(head,temp1->random);
        if (num!=-1){
            prev->random = target(headnew,num);
        }
        prev = prev->next;
        temp1 = temp1->next;
    }
    return headnew;
}