#include<iostream>
#include<vector>
using namespace std;

#define max_num 99999999

struct LL{
    int data;
    LL* next;
};

LL* finale = NULL;

void print(LL* head){
    LL* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insert(LL*& head, int data){
    LL* temp = new LL;
    temp->data = data;
    temp->next = NULL;

    if (head==NULL){
        head = temp;
        return;
    }
    LL* temp1 = head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
    return;
}
void del (LL*& head){
    if (head==NULL) return;
    else if (head->next==NULL){
        delete head;
        head = NULL;
        return;
    }
    LL* temp = head->next;
    delete head;
    head = temp;
    return;
}
int longing (LL* head){
    if (head==NULL) return 0;
    LL* temp = head;
    int count = 0;
    while (temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int minim(vector<LL*>& list){
    int n = list.size();
    int minims = max_num;
    int index = -1;
    for (int i=0;i<n;i++){
        if (list[i]==NULL) continue;
        else if (list[i]->data<minims){
            minims = list[i]->data;
            index = i;
        }
    }
    if (index!=-1) del(list[index]);
    return minims;
}

void merge(vector<LL*>list){
    int n = list.size();
    int count = 0;
    for (int i=0;i<n;i++){
        count+=longing(list[i]);
    }
    while (count>0){
        insert(finale,minim(list));
        count--;
    }
}

int main(){
    vector<LL*> list;
    LL* head1 = NULL; 
    LL* head2 = NULL; 
    LL* head3 = NULL;
    LL* head4 = NULL;
    LL* head5 = NULL;
    LL* head6 = NULL;
    insert(head1,1);
    insert(head1,4);
    insert(head1,5);
    insert(head2,1);
    insert(head2,3);
    insert(head2,4);
    insert(head3,2);
    insert(head3,6);
    insert(head4,-2);
    insert(head4,-1);
    insert(head4,0);
    insert(head4,1);
    insert(head4,2);
    insert(head5,-2);
    insert(head5,0);
    insert(head5,2);
    insert(head5,3);
    insert(head5,6);
    insert(head5,8);
    insert(head5,10);
    insert(head5,10);
    insert(head5,10);
    insert(head6,-10);
    insert(head6,-5);
    insert(head6,0);
    insert(head6,5);
    insert(head6,10);
    insert(head6,15);

    list.push_back(head1);
    list.push_back(head2);
    list.push_back(head3);
    list.push_back(head4);
    list.push_back(head5);
    list.push_back(head6);
    merge(list);
    print(finale);
    return 0;
}