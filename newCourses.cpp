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
    temp->val = val;
    temp->next = NULL;

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

void BFS (int i, Node* courses[],bool& check, bool visited[], int target, int numCourses){
    visited[i] = true;
    queue<int> q;
    q.push(i);
    while (!q.empty()){
        Node* temp = courses[q.front()];
        if (temp!=NULL&&temp->val==target){
            check = false;
            return;
        }
        while (temp!=NULL){
            if (!visited[temp->val]) {
                q.push(temp->val);
                visited[temp->val] = true;
            }
            temp = temp->next;
        }
        q.pop();
    }
}

bool acyclic (int numCourses, vector<vector<int>>& prerequisites){
    int n = prerequisites.size();
    Node* courses[numCourses];
    bool visited[numCourses];
    for (int i=0;i<numCourses;i++){
        courses[i] = NULL;
        visited[i] = false;
    }
    for (int i=0;i<n;i++){
        vector<int> temp = prerequisites[i];
        insert(temp[0], courses[temp[1]]);
    }

    for (int i=0;i<numCourses;i++){
        if (courses[i]==NULL) continue;
        bool check = true;
        BFS(i,courses,check,visited,i,numCourses);
        if (!check) return false;
        reset(visited,numCourses);
    }
    return true;
}

void DFS (int j, int numCourses, int ordering[], int& i, bool visited[], Node* courses[]){
    if (visited[j]||i==-1) return;
    visited[j] = true;
    Node* current = courses[j];
    if (current==NULL) {
        ordering[i--] = j;
        return;
    } 
    while (current!=NULL){
        int value = current->val;
        DFS(value,numCourses,ordering,i,visited,courses);
        current = current->next;
    }
    ordering[i--] = j; 
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> answer;
    if (numCourses==1) {
        answer.push_back(0);
        return answer;
    }
    if (!acyclic(numCourses,prerequisites)) return answer;

    int ordering[numCourses];
    int i = numCourses-1;
    int n = prerequisites.size();
    if (n==0) {
        for (int i = 0;i<numCourses;i++) answer.push_back(i);
        return answer;
    }
    Node* courses[numCourses];
    bool visited[numCourses];
    for (int i=0;i<numCourses;i++){
        courses[i] = NULL;
        visited[i] = false;
    }

    for (int i=0;i<n;i++){
        vector<int> temp = prerequisites[i];
        insert(temp[0], courses[temp[1]]);
    }

    for (int j=0;j<numCourses;j++){
        if (i==-1) break;
        if (visited[j]) continue;
        DFS(j,numCourses,ordering,i,visited,courses);       
    }
    
    for (int i=0;i<numCourses;i++) answer.push_back(ordering[i]);
    return answer;
}

int main(){
    int numCourses;
    std::cin>>numCourses;
    vector<vector<int>> prerequisites = {{2,0},{1,0},{3,1},{3,2},{1,3}};
    vector<int> ordering = findOrder(numCourses,prerequisites);
    for (auto val : ordering) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}