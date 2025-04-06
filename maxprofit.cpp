#include<iostream>
#include<vector>

using std::vector;

int maxProfit(vector<int> prices){
    int n = prices.size();
    if (n==1) return 0;
    int sum = 0;
    bool firstBuy = false;
    for (int i=1;i<n;i++){
        if ((prices[i]>prices[i-1])&&!firstBuy) {
            firstBuy = true;
            sum += (prices[i] - prices[i-1]);
        }
        else if (firstBuy){
            if (prices[i]>=prices[i-1]) sum += (prices[i] - prices[i-1]);
        }
    }
    return sum;
}

int main(){
    vector<int> prices = {7,6,4,3,1};
    std::cout<<maxProfit(prices)<<std::endl;
    return 0;

}