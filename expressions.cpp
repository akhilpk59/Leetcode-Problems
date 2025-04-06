#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
using std::vector;
using std::string;
using std::map;
using std::stack;

int power (int n){
    if (n==0) return 1;
    else return 10*power(n-1);
}

int s2I (string s){
    if (s=="0") return 0;
    bool nFlag = false;
    if (s[0]=='-') {
        nFlag = true;
        s.erase(s.begin());
    }
    int value = 0;
    int n = s.length();
    for (int i=n-1;i>=0;i--){
        value+=(s[i]-48)*power(n-1-i);
    }
    return (nFlag) ? 0 - value : value;
}

vector<vector<int>> permute (vector<int> arr){
    int n = arr.size();
    vector<vector<int>> answer;
    if (n==0) return answer;
    if (n==1){
        answer.push_back(arr);
        return answer;
    }
    for (int i=0;i<n;i++){
        vector<int> temp = arr;
        temp.erase(temp.begin()+i);
        vector<vector<int>> rem = permute(temp);
        int m = rem.size();
        for (int j=0;j<m;j++){
            rem[j].insert(rem[j].begin(),i);
            answer.push_back(rem[j]);
        }
    }
    return answer;
}

vector<vector<int>> permute(int operatorCount){
    vector<vector<int>> answer;
    if (operatorCount==0) return answer;
    if (operatorCount==1) {
        vector<int> temp;
        temp.push_back(1);
        answer.push_back(temp);
        return answer;
    }
    vector<int> arr;
    for (int i=0;i<operatorCount;i++){
        arr.push_back(i);
    }
    answer = permute(arr);
    return answer;
}

string create (string expression, vector<int> permutation, vector<int> index){
    vector<string> numerals;
    vector<char> operators;
    int n = index.size();
    for (int i=0;i<n;i++){
        operators.push_back(expression[index[i]]);
    }
    int m = expression.length();
    string temp = "";
    for (int i=0;i<m;i++){
        if (expression[i]!='+'&&expression[i]!='-'&&expression[i]!='*'){
            temp +=expression[i];
        }
        else {
            numerals.push_back(temp);
            temp = "";
        }
    }
    if (temp!="") numerals.push_back(temp);
    while (!permutation.empty()){
        int current = permutation.front();
        char op = operators[current];
        string op1 = numerals[current];
        string op2 = numerals[current+1];
        string temp = "(" + op1 + op + op2 + ")";
        operators.erase(operators.begin()+current);
        numerals.erase(numerals.begin()+current,numerals.begin()+current+2);
        numerals.insert(numerals.begin()+current,temp);
        int k = permutation.size();
        for (int i=0;i<k;i++){
            if (permutation[i]>current) permutation[i]--;
        }
        permutation.erase(permutation.begin());
    }
    return numerals[0];
}

vector<int> index (string expression){
    int n = expression.length();
    vector<int> answer;
    for (int i=0;i<n;i++){
        if (expression[i]=='+'||expression[i]=='-'||expression[i]=='*') answer.push_back(i);
    }
    return answer;
}

vector<string> diffExpressions(string expression, vector<int> index){
    int operatorCount = index.size();
    vector<vector<int>> permutations = permute(operatorCount);
    vector<string> answer;
    int n = permutations.size();
    map<string,int> store;
    for (int i=0;i<n;i++){
        string temp = create(expression, permutations[i], index);
        if (store.find(temp)!=store.end()) continue;
        store[temp] = 1;
        answer.push_back(temp);
    }
    return answer;
}

int calculate (string op1, char op, string op2){
    int nums1 = s2I(op1);
    int nums2 = s2I (op2);
    return (op=='+') ? (nums1+nums2) : ((op=='*') ? (nums1*nums2) : (nums1 - nums2));
}

string i2S(int nums){
    if (nums==0) return "0";
    bool nFlag = false;
    if (nums<0){
        nFlag = true;
        nums = 0 - nums;
    }
    string answer = "";
    while (nums!=0){
        char temp = '0' + nums%10;
        answer = temp + answer;
        nums/=10;
    }
    if (nFlag) answer = '-' + answer;
    return answer;
}

int compute(string expression){
    // std::cout<<expression<<std::endl;
    // std::cout<<"--------------"<<std::endl;
    stack<string> operands;
    stack<char> operators;
    int n = expression.length();
    string temp = "";
    for (int i=0;i<n;i++){
        if (expression[i]=='(') {
            if (temp!="") {
                operands.push(temp);
                temp = "";
            }
            continue;
        }
        else if (expression[i]=='+'||expression[i]=='-'||expression[i]=='*') {
            operators.push(expression[i]);
            if (temp!="") {
                // std::cout<<temp<<" you are in operator detection "<<std::endl;
                operands.push(temp);
                temp = "";
            }
        }
        else if (expression[i]!=')') temp+=expression[i];
        else if (expression[i]==')'){
            string op2;
            if (temp!="") op2 = temp;
            else {
                op2 = operands.top();
                operands.pop();
            }
            string op1 = operands.top();
            char op = operators.top();
            operands.pop();
            operators.pop();
            temp = "";
            int nums = calculate(op1,op,op2);
            string value = i2S(nums);
            // std::cout<<op1<<" "<<op<<" "<<op2<<" = "<<value<<std::endl;
            operands.push(value);
        }
    }
    if (temp!="") {
        string op2 = temp;
        string op1 = operands.top();
        char op = operators.top();
        operands.pop();
        operators.pop();
        temp = "";
        // std::cout<<op1<<" "<<op<<" "<<op2<<std::endl;
        return calculate(op1,op,op2);
    }
    // std::cout<<operands.top()<<"final answer"<<std::endl;
    return s2I(operands.top());
}

vector<int> diffWaysToCompute (string expression){
    int nE = expression.length();
    vector<int> answer;
    if (nE<=2) {
        answer.push_back(s2I(expression));
        return answer;
    }
    vector<int> positions = index(expression);
    int operatorCount = positions.size();
    // for (int i=0;i<nE;i++){
    //     if (expression[i]=='-'||expression[i]=='+'||expression[i]=='*') operatorCount++;
    // }
    if (operatorCount==0){
        answer.push_back(s2I(expression));
        return answer;
    }
    else if (operatorCount==1) {
        expression.insert(expression.begin(),'(');
        expression += ')';
        answer.push_back(compute(expression));
        return answer;
    }
    vector<string> types = diffExpressions(expression,positions);
    int n = types.size();
    for (int i=0;i<n;i++) answer.push_back(compute(types[i]));
    return answer;
}

int main(){
    string expression = "0+1";
    vector<int> output = diffWaysToCompute(expression);
    for (auto val : output) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}