#include<iostream>
#include<vector>

bool isPalindrome(int x){
    if (x<0) return false;
    if (x>=0&&x<=9) return true;
    std::vector <int> digit;
    int temp = x;
    while (temp!=0){
        digit.push_back(temp%10);
        temp/=10;
    }
    int n = digit.size();
    for (int i=0;i<n/2;i++){
        if (digit[i]!=digit[n-i-1]) return false;
    }
    return true;
}

int main(){
    int x;
    std::cin>>x;
    std::cout<<std::boolalpha<<isPalindrome(x)<<std::endl;
    return 0;
}