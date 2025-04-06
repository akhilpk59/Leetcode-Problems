#include<iostream>

int power(int n){
    if (n==0) return 1;
    else return 2*power(n-1);
}

void truncate(int left, int& right){
    int bits=0;
    if (left==0) bits = 1;
    while (left!=0){
        bits++;
        left/=2;
    }
    int value = 0;
    int current = 0;
    while (bits!=0){
        bits--;
        value+=((right%2)*power(current++));
        right/=2;
    }
    right = value;
}

int rangeBitwiseAnd (int left, int right){
    if (left==0) return 0;
    // truncate(left,right);
    if (left==right) return left;
    int leftS = left;
    int rightS = right;
    int bits=0;
    while (leftS!=0){
        bits++;
        leftS/=2;
    }
    int dLeft = bits;
    bits = 0;
    while (rightS!=0){
        bits++;
        rightS/=2;
    }
    int dRight = bits;
    int arr[dRight];
    for (int i=0;i<dRight;i++) arr[i]=1;
    for (int i=dLeft;i<dRight;i++) arr[i] = 0;
    int diff = right - left;
    bits = 0;
    while (diff!=0){
        diff/=2;
        bits++;
    }
    for (int i=0;i<bits-1;i++) arr[i] = 0;
      //i = bits-1 to i = dLeft-1 is remaining at this point 
    int last = dLeft - bits;
    int counter = 0;
    for (int i = right;i>=left;i--){
        for (int j=dLeft-1;j>=bits;j--){
            if (i%power(j)!=0) {
                arr[j-1]=0;
                counter++;
            }
        }
        if (counter==last) break;
    }
    int answer = 0;
    for (int i=0;i<dRight;i++) answer+=(arr[i]*(power(i)));
    return answer;
}

int main(){
    int left;
    int right;
    std::cin>>left>>right;
    std::cout<<rangeBitwiseAnd(left, right)<<std::endl;
    return 0;
}