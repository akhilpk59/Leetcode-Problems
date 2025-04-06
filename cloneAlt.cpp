#include<iostream>
#include<vector>
#include<set>
#include<utility>
using std::vector;
using std::set;
using std::pair;

class Node {
    public :
    int val;
    vector<Node*> neighbours;
};

struct ListNode {
    Node* check;
    ListNode* next;
};

void insert(ListNode*& head, Node* val){
    ListNode* temp = new ListNode;
    temp->next = NULL;
    temp->check = val;
    if (head==NULL){
        head = temp;
        return;
    }
    ListNode* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
}

set<int> nums;
vector<Node*> collect;
vector<pair<int,int>> edges;

vector<Node*> merge(vector<Node*>collectL, vector<Node*> collectR){
    int nL = collectL.size();
    int nR = collectR.size();
    int i=0;
    int j=0;
    vector<Node*> answer;
    while (i<nL&&j<nR){
        if (collectL[i]->val<=collectR[j]->val) answer.push_back(collectL[i++]);
        else answer.push_back(collectR[j++]);
    }
    while (i<nL) answer.push_back(collectL[i++]);
    while (j<nR) answer.push_back(collectR[j++]);
    return answer;
}

void mergeSort(vector<Node*>& collect){
    int n = collect.size();
    if (n<=1) return;
    int mid = (n-1)/2;
    vector<Node*> collectL;
    vector<Node*> collectR;

    for (int i=0;i<=mid;i++) collectL.push_back(collect[i]);
    for (int i=mid+1;i<n;i++) collectR.push_back(collect[i]);
    mergeSort(collectL);
    mergeSort(collectR);
    collect = merge(collectL,collectR);
}

Node* search(int value, vector<Node*> all, int start, int end){
    if (start>end) {
        Node* blank = new Node;
        blank->val = 0;
        return blank;
    }
    int mid = (start+end)/2;
    if (value==all[mid]->val) return all[mid];
    else if (value>all[mid]->val) return search (value,all,mid+1,end);
    else return search (value,all,start,mid-1);
}

Node* cloneGraph (Node* node){
    ListNode* head = NULL;
    insert(head,node);
    nums.insert(node->val);
    // std::cout<<"1"<<std::endl;
    ListNode* temp = head;
    while (temp!=NULL){
        Node* current = temp->check;
        vector<Node*> neigh = current->neighbours;
        for (auto value : neigh){
            if (nums.find(value->val)==nums.end()){
                nums.insert(value->val);
                insert(head,value);
            }
            pair<int,int> edge;        
            edge.first = current->val;
            edge.second = value->val;
            edges.push_back(edge);
        }
        temp = temp->next;
    }
    // std::cout<<"2"<<std::endl;
    temp = head;
    while (temp!=NULL){
        collect.push_back(temp->check);
        temp = temp->next;
    }
    mergeSort(collect);
    // std::cout<<"3"<<std::endl;
    vector<Node*> all;
    for (auto value : collect){
        Node* temp = new Node;
        temp->val = value->val;
        all.push_back(temp);
    }
    // std::cout<<"4"<<std::endl;
    int n = all.size();

    for (auto value : edges){
        Node* temp = search(value.first,all,0,n-1);
        temp->neighbours.push_back(search(value.second,all,0,n-1));
    }
    // std::cout<<"5"<<std::endl;
    return all[0];
}

int main(){
    Node* one = new Node;
    one->val = 1;
    Node* two = new Node;
    two->val = 2;
    Node* three = new Node;
    three->val = 3;
    Node* four = new Node;
    four->val = 4;
    one->neighbours.push_back(two);
    one->neighbours.push_back(four);
    two->neighbours.push_back(one);
    two->neighbours.push_back(three);
    three->neighbours.push_back(two);
    three->neighbours.push_back(four);
    four->neighbours.push_back(one);
    four->neighbours.push_back(three);
    
    Node* answer = cloneGraph(one);
    std::cout<<answer->val<<std::endl;

    for (auto value : answer->neighbours){
        std::cout<<value->val<<" ";
    }

    return 0;
}