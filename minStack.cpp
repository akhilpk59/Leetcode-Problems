#include<iostream>

class MinStack{
   
   struct Node {
        int value;
        int min_val;
        Node* next;
   };

    Node* head;

public:
    MinStack(){
        head = NULL;
    }
    void push(int val){
        Node* temp = new Node;
        temp->next = NULL;
        temp->value = val;
        
        if (head==NULL) {
            temp->min_val = val;
            head = temp;
            return;
        }
        if (head->min_val<val) temp->min_val = head->min_val;
        else temp->min_val = val;
        temp->next = head;
        head = temp;
    }

    void pop(){
        if (head==NULL) return;
        if (head->next==NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    int top(){
        return head->value;
    }
    int getMin(){
        return head->min_val;
    }
};

int main(){
    return 0;
}