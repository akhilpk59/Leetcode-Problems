#include<iostream>
#include<vector>
using std::vector;

struct LinkedList{
    int val;
    LinkedList* next;
};

void insert(LinkedList*& head, int val){
    LinkedList* temp = new LinkedList;
    temp->val = val;
    temp->next = NULL;

    if (head==NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void remove(LinkedList*& head, int val){
    if (head==NULL) return;
    if (head->val==val){
        LinkedList* temp = head;
        head = temp->next;
        delete temp;
        return;
    }
    LinkedList* temp = head;

    while (temp->next!=NULL&&temp->next->val!=val) temp = temp->next;

    if (temp->next==NULL) return;
    LinkedList* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
}

void nullify (LinkedList*& head){
    LinkedList* temp = head;
    head = NULL;
    delete temp;
}

int count(LinkedList* head){
    if (head==NULL) return 0;
    int count = 0;
    while (head!=NULL) {
        count++;
        head = head->next;
    }
    return count;
}

bool checkTree(LinkedList* tree[], int n){
    int nums = 0;
    for (int i=0;i<n;i++){
        if (count(tree[i])>1) nums++;
        if (nums>1) break;
    }
    return (nums>1) ? false : true;
}

void trim(LinkedList* tree[], int n){
    vector<int> nodes;
    for (int i=0;i<n;i++){
        if (count(tree[i])==1) nodes.push_back(i);
    }
    for (auto value : nodes){
        int index = tree[value]->val;
        nullify(tree[value]);
        remove(tree[index],value);
    }
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
    vector<int> answer;
    if (n==1) {
        answer.push_back(0);
        return answer;
    }
    if (n==2){
        answer.push_back(0);
        answer.push_back(1);
        return answer;
    }
    LinkedList* tree[n];
    for (int i=0;i<n;i++) tree[i] = NULL;

    int m = edges.size();
    for (int i=0;i<m;i++){
        int x = edges[i][0];
        int y = edges[i][1];
        insert(tree[x],y);
        insert(tree[y],x);
    }

    while(!checkTree(tree,n)){
        trim(tree,n);
    }
    int counter = 0;
    int node = -1;
    for (int i=0;i<n;i++){
        if (count(tree[i])>1) {
            counter++;
            node = i;
            break;
        }
    }
    if (counter==1) {
        answer.push_back(node);
        return answer;
    }

    for (int i=0;i<n;i++){
        if (count(tree[i])==1) answer.push_back(i);
        if (answer.size()==2) return answer;
    }
    return answer;
}

int main(){

    return 0;
}
