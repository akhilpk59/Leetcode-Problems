#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL){}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

ListNode* mergeTwoLists (ListNode* list1, ListNode* list2){
    if (list1==NULL&&list2==NULL) return NULL;
    else if (list1==NULL) return list2;
    else if (list2==NULL) return list1;

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* answer = new ListNode;
    if (list1->val<=list2->val){
        answer->val = list1->val;
        answer->next = mergeTwoLists(list1->next,list2);
    }
    else {
        answer->val = list2->val;
        answer->next = mergeTwoLists(list1,list2->next);
    }
    return answer;
}

int main(){
    ListNode list1 = ListNode(1);
    ListNode list2 = ListNode(2);
    ListNode list3 = ListNode(4);
    ListNode list4 = ListNode(1);
    ListNode list5 = ListNode(3);
    ListNode list6 = ListNode(4);
    list1.next = &list2;
    list2.next = &list3;
    list4.next = &list5;
    list5.next = &list6;
    ListNode* temp1 = &list1;
    ListNode* temp2 = &list4;
    while (temp1!=NULL) {
        std::cout<<temp1->val<<" ";
        temp1=temp1->next;
    }
    std::cout<<std::endl;
    while (temp2!=NULL) {
        std::cout<<temp2->val<<" ";
        temp2=temp2->next;
    }
    std::cout<<std::endl;
    ListNode* answer = mergeTwoLists(&list1, &list4);
    while (answer!=NULL){
        std::cout<<answer->val<<" ";
        answer = answer->next;
    }
    return 0;
}