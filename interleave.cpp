#include<iostream>
#include<string>
#include<map>
using std::string;


string maxim(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    if (m>n) return "";
    string answer = "";
    for (int i=0,k=0;i<n;i++){
        if (s1[k]==s2[i]) answer+=s1[k++];
        else break;
    }
    return answer;
}

std::map <string, bool> result;

bool isInterleave(string s1,string s2, string s3, int index){
    if (s1==""&&s2==""&&s3=="") return true;
    if (s1==""&&s2==""&&s3!="") return false;
    if (s1=="") {
        if (s2==s3&&index==2) return true;
        else return false;
    }
    if (s2==""){
        if (s1==s3&&index==1) return true;
        else return false;
    }
    int m1 = s1.length();
    int m2 = s2.length();
    int m3 = s3.length();
    if ((m1+m2)!=m3) return false;
    string mix = s1 + s2 + s3;
    if (result.find(mix)!=result.end()) return result[mix];
    if (index==0){
        string check1 = maxim(s1,s3);
        string check2 = maxim(s2,s3);
        if (check1==""&&check2=="") return false;
        if (check1=="") {
            int l = check2.size();
            for (int i=1;i<=l;i++){
                string temp = s2;
                temp.erase(temp.begin(),temp.begin()+i);
                string rest = s3;
                rest.erase(rest.begin(),rest.begin()+i);
                if (isInterleave(s1,temp,rest,1)) {
                    result[mix] = true;
                    return true;
                }
            }
            result[mix] = false;
            return false;
        }
        if (check2=="") {
            int l = check1.size();
            for (int i=1;i<=l;i++){
                string temp = s1;
                temp.erase(temp.begin(),temp.begin()+i);
                string rest = s3;
                rest.erase(rest.begin(),rest.begin()+i);
                if (isInterleave(temp,s2,rest,2)) {
                    result[mix] = true;
                    return true;
                }
            }
            result[mix] = false;
            return false;
        }
        int n1 = check1.size();
        int n2 = check2.size();
        for (int i=1;i<=n2;i++){
            string temp = s2;
            temp.erase(temp.begin(),temp.begin()+i);
            string rest = s3;
            rest.erase(rest.begin(),rest.begin()+i);
            if (isInterleave(s1,temp,rest,1)) {
                result[mix] = true;
                return true;
            }
        }
        for (int i=1;i<=n1;i++){
            string temp = s1;
            temp.erase(temp.begin(),temp.begin()+i);
            string rest = s3;
            rest.erase(rest.begin(),rest.begin()+i);
            if (isInterleave(temp,s2,rest,2)) {
                result[mix] = true;
                return true;
            }
        }
        result[mix] = false;
        return false;
    }
    else if (index==1){
        string check1 = maxim(s1,s3);
        int n1 = check1.size();
        if (n1==0) return false;
        for (int i=1;i<=n1;i++) {
            string temp = s1;
            temp.erase(temp.begin(),temp.begin()+i);
            string rest = s3;
            rest.erase(rest.begin(),rest.begin()+i);
            if (isInterleave(temp,s2,rest,2)) {
                result[mix] = true;
                return true;
            }
        }
        result[mix] = false;
        return false;
    }
    else {
        string check2 = maxim(s2,s3);
        int n2 = check2.size();
        if (n2==0) return false;
        for (int i=1;i<=n2;i++){
            string temp = s2;
            temp.erase(temp.begin(),temp.begin()+i);
            string rest = s3;
            rest.erase(rest.begin(),rest.begin()+i);
            if (isInterleave(s1,temp,rest,1)) {
                result[mix] = true;
                return true;
            }
        }
        result[mix] = false;
        return false;
    }
}

bool isInterleave(string s1, string s2, string s3){
    if (s1==""&&s2==""&&s3=="") return true;
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();
    if ((n1+n2)!=n3) return false;
    if (s1=="") {
        if (s2==s3) return true;
        else return false;
    }
    if (s2==""){
        if (s1==s3) return true;
        else return false;
    }
    return isInterleave(s1,s2,s3,0);
}

int main(){
    string s1;
    string s2;
    string s3;
    std::getline(std::cin,s1);
    std::getline(std::cin,s2);
    std::getline(std::cin,s3);
    std::cout<<std::boolalpha<<isInterleave(s1,s2,s3)<<std::endl;
    return 0;
}