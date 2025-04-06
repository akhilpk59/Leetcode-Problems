// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:
// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:
// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Constraints:
// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

#include<iostream>
#include<string>
using namespace std;

// bool check(string p){
// int n = p.length();
// for (int i=0;i<n;i++){
//     if (p[i]=='.'||p[i]=='*') return true;
// }
// return false;
// }

bool match(string s, string p){
if (p==s) return true;
//if (!check(p)) return false;
int lp = p.length();
int ls = s.length();
int j=0;
for (int i=0;i<ls;i++){
    if (j>=lp) return false;
    if ((p[j]==s[i])||(p[j]=='.')) {
        j++;
        continue;
    }
    if ((p[j]!=s[i])&&(p[j]!='.')&&(p[j]!='*')){
        if (p[j+1]!='*') return false;
        else {
            j+=2;
            continue;
        }
    } 
    else if (p[j]=='*') {
        if (s[i]==p[j-1]||p[j-1]=='.') continue;
        if ((p[j+1]!=s[i])&&(p[j+1]!='.')) return false;
        j+=2;
    }
}
while (j<lp){
    if (p[j]!='.'&&p[j]!='*'&&(p[j]!=s[ls-1])) return false;
    j++;
}
return true;
}

int main(){
    string s = "aaa";
    string p = "a*a";
    cout<<boolalpha<<match(s,p);
    return 0;
}   