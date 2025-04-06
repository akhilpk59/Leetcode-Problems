#include<iostream>
#include<string>

using std::string;
string add (string num1, string num2){
    if (num1=="0") return num2;
    if (num2=="0") return num1;
    int n1 = num1.length();
    int n2 = num2.length();
    int carry = 0;
    int i = n1-1;
    int j = n2-1;
    string answer;
    while (i>=0&&j>=0) {
        int x1 = num1[i--]-48;
        int x2 = num2[j--]-48;
        int digit = x1 + x2 + carry;
        int qnext = digit/10;
        int r = digit%10;
        char temp = '0' + r;
        answer = temp + answer;
        carry = qnext;
    }
    while (i>=0) {
        int digit = (num1[i--] - 48) + carry;
        int qnext = digit/10;
        int r = digit%10;
        char temp = '0' + r;
        answer = temp + answer;
        carry = qnext;
    }
    while (j>=0) {
        int digit = (num2[j--] - 48) + carry;
        int qnext = digit/10;
        int r = digit%10;
        char temp = '0' + r;
        answer = temp + answer;
        carry = qnext;
    }
    if (carry!=0) {
        char temp = '0' + carry;
       if (temp!='0') answer = temp + answer;
    }
    return answer;
}

string calc (string num, string n){
    if (n=="1") return num;
    string answer = "";
    int multiplier = n[0]-48;
    int m = num.size();
    int carry = 0;
    for (int i=m-1;i>=0;i--){
        int digit = (multiplier*(num[i]-48))+carry;
        int qnext = digit/10;
        int r2 = digit%10;
        char temp = '0' + r2;
        answer = temp + answer;
        carry = qnext;
    }
    if (carry!=0) {
        char temp = '0' + carry;
       if (temp!='0') answer = temp + answer;
    }
    return answer;
}

string multiply (string num1, string num2){
    if (num1=="0"||num2=="0") return "0";
    int m = num1.length();
    int n = num2.length();
    if (m==1||n==1) {
        if (m==1) return calc(num2,num1);
        else return calc(num1,num2);
    }
    int minim = (m<n) ? m : n;
    string breaking;
    string intact;
    if (minim==m) {
        breaking = num1;
        intact = num2;
    }
    else {
        breaking = num2;
        intact = num1;
    }
    int p = breaking.length();
    string answer = "0";
    for (int i=p-1, j=0;i>=0;i--,j++){
        string temp = "";
        temp += breaking[i];
        string single = multiply(intact,temp);
        int count = j;
        while (count>0){
            single +="0";
            count--;
        }
        answer = add(answer,single);
    }
    return answer;
}

int main(){
    string num1 = "123";
    string num2 = "456";
    std::cout<<multiply(num1,num2)<<std::endl;
    return 0;   
}