#include<iostream>
#include<vector>

int pow(int n){
    if (n<=0) return 1;
    else return 2*pow(n-1);
}

std::vector<int> grayCode(int n){
    
    std::vector<int>answer;
    answer.push_back(0);
    if (n==0) return answer;

    int final = pow(n);
    int count = 1;
    
    bool arr[n];
    for (int i=0;i<n;i++) arr[i] = true;

    while(count<final){
        int nums = answer.back();
        if (count%2!=0) {
            int mask = 1<<(n-1);
            int b = (arr[n-1]) ? 1 : 0;
            int temp = ((nums & ~mask) | (b<<(n-1)));
            answer.push_back(temp);
            arr[n-1] = !arr[n-1];
        }
        else {
            int exp = count%(pow(n-1));
            int counter = n-1;
            while (exp!=0){
                counter--;
                exp = count%(pow(counter));
            }
            int mask = 1<<(n-1-counter);
            int b = (arr[n-1-counter]) ? 1 : 0;
            int temp = ((nums & ~mask) | (b<<(n-1-counter)));
            answer.push_back(temp);
            arr[n-1-counter] = !arr[n-1-counter];
        }
        count++;
    }
    return answer;
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> answer = grayCode(n);
    for (auto val : answer) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}