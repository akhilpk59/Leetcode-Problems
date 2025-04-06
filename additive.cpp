#include<iostream>
#include<string>

using std::string;

// string i2S (long long int n){
//     if (n==0) return "0";
//     string answer = "";
//     while (n!=0){
//         char temp = '0' + n%10;
//         answer = temp + answer;
//         n/=10;
//     }
//     return answer;
// }

// long long int pow (int n){
//     if (n==0) return 1;
//     else return 10*pow(n-1);
// }

// long long int s2I(string s){
//     int n = s.length();
//     int num = 0;
//     for (int i=n-1;i>=0;i--){
//         num+= (s[i]-48)*pow(n-1-i);
//     }
//     return num;
// }

bool greaterThan(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();
return true;
}

string add (string s1, string s2){
    if (s2=="N") return "false";
    if (s1=="0"||s2=="0"){
        if (s1=="0") return s2;
        else return s1;
    }
    int n1 = s1.length();
    int n2 = s2.length();
    if (n2>n1) return add(s2,s1);
    int carry = 0;
    string temp = "";
    for (int i=0;i<n2;i++){
        int r1 = s1[n1-i-1] - 48;
        int r2 = s2[n2-i-1] - 48;
        char result = '0' + (r1+r2+carry)%10;
        carry = (r1+r2+carry)/10;
        temp = result + temp;
    }
    for (int i=n1-n2-1;i>=0;i--){
        char result = '0' + ((s1[i]-48)+carry)%10;
        carry = ((s1[i]-48)+carry)/10;
        temp = result + temp;
    }
    if (carry!=0){
        char result = '0' + carry;
        temp = result + temp;
        }
    std::cout<<"s1 ("<<s1<<") + s2 ("<<s2<<") = answer ("<<temp<<")"<<std::endl;
    return temp;
}

bool compute(string t1, string remain, string t2="N"){
    int n1 = t1.length();
    int n2 = t2.length();
    int nR = remain.length();
    if (n1==0||n2==0) return false; 
    if ((t1[0]=='0'||t2[0]=='0')&&n1!=1&&n2!=1) return false;
    if (remain==add(t1,t2)) return true;
    
    if (t2=="N"){
        string temp = "";
        for (int i=0;i<nR;i++){
            temp +=remain[i];
            string rem = remain;
            rem.erase(rem.begin(),rem.begin()+i+1);
            std::cout<<"t1 = "<<t1<<",& temp = "<<temp<<", rem = "<<rem<<" in the N cycle."<<std::endl;
            if (compute (t1,rem,temp)) return true;
        }
        return false;
    }
    else {
        string temp = "";
        for (int i=0;i<nR;i++){
            temp+=remain[i];
            if (add(t1,t2)>temp) continue;
            else if (add(t1,t2)<temp) break;
            string rem = remain;
            rem.erase(rem.begin(),rem.begin()+i+1);
            std::cout<<"t1 = "<<t1<<", t2 = "<<t2<<", temp = "<<temp<<" & rem = "<<rem<<std::endl;
            if (compute(t2,rem,temp)) return true;
        }
        return false;
    }
    return false;
}

bool isAdditiveNumber(string num){
    int n = num.length();
    if (n<3) return false;
    string temp = "";
    for (int i=0;i<n;i++){
        temp+=num[i];
        string next = num;
        next.erase(next.begin(),next.begin()+i+1);
        if (compute (temp,next)) return true;
    }
    return false;
}

int main(){
    string num = "199100199";
    std::cout<<std::boolalpha<<isAdditiveNumber(num)<<std::endl;
    return 0;
}