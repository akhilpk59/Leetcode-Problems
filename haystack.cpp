#include<iostream>
#include<string>
using std::string;

int strStr(string haystack, string needle){
    int nH = haystack.length();
    int nN = needle.length();
    for (int i=0;i<=nH-nN;i++){
        if (needle[0]==haystack[i]){
            int count = 1;
            for (int j=1;j<nN;j++){
                if (needle[j]==haystack[i+j]) count++;
                else break;
            }
            if (count==nN) return i;
            else {
                i = i+count-1;
                continue;
            }
        }
        else continue;
    }
    return -1;
}

int main(){
    string needle = "leeto";
    string haystack = "leetcode";
    std::cout<<strStr(haystack,needle)<<std::endl;
    return 0;
}