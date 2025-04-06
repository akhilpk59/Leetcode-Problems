#include<iostream>

int power(int n){
    if (n==0) return 1;
    else return 2*power(n-1);
}

int rangeBitwiseAnd(int left, int right){
    if (left==0) return 0;
    if (left==right) return left;
    int bits = 0;
    int leftM = left;
    int rightM = right;
    while (leftM!=0){
        bits++;
        leftM/=2;
    }
    int bLeft = bits;
    bits = 0;
    while (rightM!=0){
        bits++;
        rightM/=2;
    }
    int bRight = bits;
    if (bLeft!=bRight) return 0;
    int counter = bLeft;
    int answer = 0;
    while (counter>0){
        int temp = right;
        int bit1 = (temp>>(counter-1))%2;
        temp = left;
        int bit2 = (temp>>(counter-1))%2;
        if (bit1&&bit2) answer+=power(counter-1);
        else if (bit1==bit2) {
            counter--;
            continue;
        }
        else return answer;
        counter--;
    }
    return answer;
}

int main(){
    int left;
    int right;
    std::cin>>left>>right;
    std::cout<<rangeBitwiseAnd(left,right)<<std::endl;
    return 0;
}