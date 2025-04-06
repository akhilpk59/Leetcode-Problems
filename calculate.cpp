#include<iostream>
#include<string>
using std::string;

int pow(int n){
    if (n==0) return 1;
    else return 10*pow(n-1);
}

int s2I(string s){
    if (s=="") return 0;
    bool nFlag = false;
    if (s[0]=='-') {
        nFlag = true;
        s.erase(s.begin());
    }
    int n = s.length();
    int value = 0;
    for (int i=n-1;i>=0;i--){
        value += (s[i]-48)* pow(n-1-i);
    }
    return (!nFlag)? value : 0 - value;
}

string i2S(int i){
    if (i==0) return "0";
    string answer = "";
    while (i!=0){
        char temp = '0' + (i%10);
        answer = temp + answer;
        i/=10;
    }
    return answer;
}

void removeDivide(string& s){
    int n = s.length();
    // std::cout<<"incoming string : "<<s<<std::endl;
    for (int i=0;i<s.length();i++){
        if (s[i]=='/'){
            string op1 = "";
            string op2 = "";
            int left = i-1;
            int right = i+1;
            while (left>=0&&s[left]!='+'&&s[left]!='-'&&s[left]!='*'&&s[left]!='/'){
                if (s[left]!=' ') op1 = s[left]+op1;
                left--;
            }
            while (right<s.length()&&s[right]!='+'&&s[right]!='-'&&s[right]!='*'&&s[right]!='/'){
                if (s[right]!=' ') op2 +=s[right];
                right++;
            }
            // std::cout<<"op1 : "<<op1<<", op2 : "<<op2<<" ";
            int value = s2I(op1)/s2I(op2);
            string replace = i2S(value);
            // std::cout<<"replace "<<replace<<std::endl;
            int j = left+1;
            int k = 0;
            int l = replace.length();
            for (int j=left+1;j<right;j++){
                if (k<l) s[j] = replace[k++];
                else break;
            }
            s.erase(s.begin()+left+l+1,s.begin()+right);
            //  std::cout<<"string after removing divide : "<<s<<std::endl;
            i = left-1; 
            if (i<-1) i = -1;
        }
    }
}
void removeMultiply(string& s){
    int n = s.length();
    // std::cout<<"incoming string : "<<s<<std::endl;
    for (int i=0;i<s.length();i++){
        if (s[i]=='*'){
            string op1 = "";
            string op2 = "";
            int left = i-1;
            int right = i+1;
            while (left>=0&&s[left]!='+'&&s[left]!='-'&&s[left]!='*'&&s[left]!='/'){
                if (s[left]!=' ') op1 = s[left]+op1;
                left--;
            }
            while (right<s.length()&&s[right]!='+'&&s[right]!='-'&&s[right]!='*'&&s[right]!='/'){
                if (s[right]!=' ') op2 +=s[right];
                right++;
            }
            // std::cout<<"op1 : "<<op1<<", op2 : "<<op2<<" ";
            int value = s2I(op1)*s2I(op2);
            string replace = i2S(value);
            // std::cout<<"replace "<<replace<<std::endl;
            int j = left+1;
            int k = 0;
            int l = replace.length();
            for (int j=left+1;j<right;j++){
                if (k<l) s[j] = replace[k++];
                else break;
            }
            s.erase(s.begin()+left+l+1,s.begin()+right);
            //  std::cout<<"string after removing multiply : "<<s<<std::endl;
            i = left-1; 
            if (i<-1) i = -1;
        }
    }
}
void removeAdd(string& s){
    int n = s.length();
    // std::cout<<"incoming string : "<<s<<std::endl;
    for (int i=0;i<s.length();i++){
        if (s[i]=='+'){
            string op1 = "";
            string op2 = "";
            int left = i-1;
            int right = i+1;
            while (left>=0&&s[left]!='+'&&s[left]!='-'&&s[left]!='*'&&s[left]!='/'){
                if (s[left]!=' ') op1 = s[left]+op1;
                left--;
            }
            while (right<s.length()&&s[right]!='+'&&s[right]!='-'&&s[right]!='*'&&s[right]!='/'){
                if (s[right]!=' ') op2 +=s[right];
                right++;
            }
            // std::cout<<"op1 : "<<op1<<", op2 : "<<op2<<" ";
            int value = s2I(op1)+s2I(op2);
            string replace = i2S(value);
            // std::cout<<"replace "<<replace<<std::endl;
            int j = left+1;
            int k = 0;
            int l = replace.length();
            for (int j=left+1;j<right;j++){
                if (k<l) s[j] = replace[k++];
                else break;
            }
            s.erase(s.begin()+left+l+1,s.begin()+right);
            //  std::cout<<"string after removing multiply : "<<s<<std::endl;
            i = left-1; 
            if (i<-1) i = -1;
        }
    }
}
int removeSubtract(string& s){
    int n = s.length();
    string temp = "";
    int value = 0;
    bool negative = false;
    bool first = true;
    int count = 0;
    for (int i=0;i<n;i++){
        if (s[i]=='-') {
            count++;
            break;
        }
    }
    if (count==0) return s2I(s);
  
    for (int i=0;i<n;i++){
        if (s[i]!='-'){
            temp+=s[i];
        }
        else {
            if (first) {
                first = false;
                value+=s2I(temp);
                temp = "";
                continue;
            }
            if (temp=="") {
                negative = true;
                continue;
            }
            if (!negative) value -=s2I(temp);
            else value +=s2I(temp); 
            temp = "";
            negative = false;
        }
    }
    if (!negative) value-=s2I(temp);
    else value+=s2I(temp);
    return value;
}

void cleanUp(string& s){
    int n = s.length();
    string temp = "";
    for (int i=0;i<n;i++){
        if (s[i]!=' ') temp+=s[i];
    }
    s = temp;
}

int calculate(string s){
    cleanUp(s);
    int n = s.length();
    if (n<=2) return s2I(s);
    removeDivide(s);
    removeMultiply(s);
    removeAdd(s);
    return removeSubtract(s);
}

int main(){
    string s = "-10-3--4-6-1--2-12-123--234";
    std::cout<<calculate(s)<<std::endl;
    return 0;
}