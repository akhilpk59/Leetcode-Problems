#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

struct stack {
    int val;
    stack* next;
};

bool stackEmpty(stack* head){
    if (head==NULL) return true;
    else return false;
}

void push(stack*& head, int val){
    stack* temp = new stack;
    temp->val = val;
    temp->next = NULL;

    if (stackEmpty(head)){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void pop(stack*& head){
    if (stackEmpty(head)) return;
    stack* temp = head;
    head = temp->next;
    delete temp;
}

int top(stack* head){
    if (stackEmpty(head)) return 201;
    return head->val;
}

int pow (int n){
    if (n==0) return 1;
    else return 10*pow(n-1);
}

int aToI (string temp){
    int n = temp.size();
    bool nFlag = false;
    if (temp[0]=='-') nFlag = true;
    if (nFlag){
        temp.erase(temp.begin());
        n--;
    }
    int answer = 0;
    for (int i=n-1;i>=0;i--){
        int digit = (temp[i]-48);
        answer+= digit*pow(n-1-i);
    }
    return (!nFlag) ? answer : 0 - answer;
}

int evalRPN(vector<string>& tokens){
    stack* nums = NULL;
    int n = tokens.size();
    for (int i=0;i<n;i++){
        if (tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
            int num = aToI(tokens[i]);
            push(nums,num);
        }
        else {
            int num1 = top(nums);
            pop(nums);
            int num2 = top(nums);
            pop(nums);
            if (tokens[i]=="+") push(nums,num1+num2);
            else if (tokens[i]=="-") push(nums,num2-num1);
            else if (tokens[i]=="*") push(nums,num1*num2);
            else push(nums,num2/num1);
        }
    }
    return top(nums);
}

int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout<<evalRPN(tokens)<<std::endl;
    return 0;
}