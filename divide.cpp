#include<iostream>

// static bool nFlag = false;
// static int count = 0;

int divide(int dividend, int divisor){
    // if (count==10000000) return 0;
    // count++;
    bool nDividend = false;
    bool nDivisor = false;
    if (dividend==divisor) return 1;
    // std::cout<<"WE "<<count<<" dividend : "<<dividend<<" divisor : "<<divisor<<std::endl;
    if (dividend==-2147483648) {
        // std::cout<<"did we get here? ";
        if (divisor>0) {
            if (divisor==1) return -2147483648;
            int rem = dividend + divisor;
            // std::cout<<"we are here"<<" ";
            // std::cout<<std::endl;
            return divide(rem,divisor) - 1 ;
        }
        else {
            if (divisor==-1) return 2147483647;
            int rem = dividend - divisor;
            return divide(rem,divisor) + 1;
        }
    }
    if (dividend<0) nDividend = true;
    if (divisor<0) nDivisor = true;
    int mDividend = (nDividend) ? 0-dividend : dividend;
    int mDivisor = (nDivisor) ? 0-divisor : divisor;
    if (mDividend<mDivisor||mDividend==0) return 0;
    int rem = mDividend - mDivisor;
    // if (count==0) nFlag = (nDividend^nDivisor);
    // count++;
    // if (count==2147483647&&!nFlag) return 1;
    // else if (count==2147483647&&nFlag&&rem>mDivisor) return -2147483648;
    return (!(nDividend^nDivisor)) ? (1 + divide(rem,mDivisor)) : 0 - (1 + divide(rem,mDivisor));
}

int main() {
    int dividend;
    int divisor;
    std::cin>>dividend>>divisor;
    std::cout<<divide(dividend, divisor)<<std::endl;
    return 0;
}