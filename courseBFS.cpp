#include<iostream>
#include<vector>
#include<queue>
using std::vector;
using std::queue;

struct Node {
    int val;
    Node* next;
};

void insert(int val, Node*& head){
    Node* temp = new Node;
    temp->next=NULL;
    temp->val = val;
    if (head==NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
}

void reset(bool visited[], int numCourses){
    for (int i=0;i<numCourses;i++) visited[i] = false;
}

void BFS (vector<Node*> requirements, bool visited[], int i, bool& check){
    visited[i] = true;
    queue<int> q;
    q.push(i);
    while (!q.empty()){
        int value = q.front();
        Node* current = requirements[value];
        if (current!=NULL&&current->val==i){
            check = false;
            return;
        }
        while (current!=NULL){
            if (visited[current->val]) {
                if (current->val==i) {
                    check = false;
                    return;
                }
                current = current->next;
                continue;
            }
            q.push(current->val);
            visited[current->val] = true;
            current = current->next;
        }
        q.pop();
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    int n = prerequisites.size();
    if (n==0) return true;
    if (numCourses==1) return false;

    vector<Node*> requirements;
    bool visited[numCourses];

    for (int i=0;i<numCourses;i++){
        requirements.push_back(NULL);
        visited[i] = false;
    }

    for (int i=0;i<n;i++){
        vector<int> temp = prerequisites[i];
        if (temp[0]==temp[1]) return false;
        insert(temp[0],requirements[temp[1]]);
    }

    for (int i=0;i<numCourses;i++){
        if (requirements[i]==NULL) continue;
        bool check = true;
        BFS(requirements,visited,i,check);
        if (!check) return false;
        reset(visited,numCourses);
    }
    return true;
}

int main(){
    int numCourses;
    std::cin>>numCourses;
    vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2},{2,1}};
    std::cout<<std::boolalpha<<canFinish(numCourses,prerequisites)<<std::endl;
    return 0;
}