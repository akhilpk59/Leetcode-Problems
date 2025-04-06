#include<iostream>
#include<string>
#include<map>
using std::string;
using std::map;

int pow (int n){
    if (n==0) return 1;
    else return 10*pow(n-1);
}

string D2S (int nums){
    if (nums==0) return "0";
    if (nums==-2147483468) return "-2147483468";
    bool nFlag = false;
    if (nums<0) nFlag = true;
    if (nFlag) nums = 0 - nums;
    string answer = "";
    while (nums!=0){
        char temp = '0' + (nums%10);
        answer = temp + answer;
        nums/=10;
    }
    if (nFlag) answer = "-" + answer;
    return answer; 
}

string fractionToDecimal(int numerator, int denominator){
    if (numerator==0) return "0";
    int quotient;
    int remainder;
    string answer;
    bool nFlag = false;
    map<int,int> remains;
    int ind = 1;
    string decimal = "";
    if (numerator!=-2147483468&&denominator!=-1&&denominator!=-2147483648) {
        quotient = numerator/denominator;
        remainder = numerator%denominator;
        answer = D2S(quotient);
    }
    else if (denominator==-2147483648){
        if (numerator==-2147483648) return "1";
        quotient = numerator/denominator;
        remainder = numerator%denominator;
        answer = D2S(quotient);
        nFlag = (numerator<0) ? false : true;
        if (remainder==0) {
            if (nFlag&&answer[0]!='-') answer = "-" + answer;
            return answer;
        }
        answer+=".";
        if (remainder<0) remainder = 0-remainder;    
        while (remains.find(remainder)==remains.end()){
            remains[remainder] = ind++;
            remainder *= 10;
            quotient = remainder/denominator;
            if (quotient<0) quotient = 0 - quotient;
            remainder = remainder%denominator;
            decimal+=D2S(quotient);
            if (remainder==0) break;
        }
        if (remainder==0){
            answer+=decimal;
            if (nFlag&&answer[0]!='-') answer = "-" + answer;
        return answer;
        }
        else {
            int last = remains[remainder];
            if (last==1){
                answer = answer + "(" + decimal + ")";
                if (nFlag&&answer[0]!='-') answer = "-" + answer;
                return answer;
            }
            else {
                int index = last - 1;
                string non = "";
                string rep = "";
                int l = decimal.length();
                for (int i=0;i<index;i++) non+=decimal[i];
                for (int i=index;i<l;i++) rep+=decimal[i];
                answer = answer + non + "(" + rep + ")";
                if (nFlag&&answer[0]!='-') answer = "-" + answer;
                return answer;
            }
        }
    }
    else return "2147483648";

    nFlag = (numerator<0)^(denominator<0);
    if (remainder==0) {
        if (nFlag&&answer[0]!='-') answer = "-" + answer;
        return answer;
    }
    answer+=".";
    if (remainder<0) remainder = 0 - remainder;
    if (denominator<0) denominator = 0 - denominator;
    while (remains.find(remainder)==remains.end()){
        remains[remainder] = ind++;
        remainder *= 10;
        quotient = remainder/denominator;
        remainder = remainder%denominator;
        decimal+=D2S(quotient);
        if (remainder==0) break;
    }
    if (remainder==0){
        answer+=decimal;
        if (nFlag&&answer[0]!='-') answer = "-" + answer;
        return answer;
    }
    else {
        int last = remains[remainder];
        if (last==1){
            answer = answer + "(" + decimal + ")";
            if (nFlag&&answer[0]!='-') answer = "-" + answer;
            return answer;
        }
        else {
            int index = last - 1;
            string non = "";
            string rep = "";
            int l = decimal.length();
            for (int i=0;i<index;i++) non+=decimal[i];
            for (int i=index;i<l;i++) rep+=decimal[i];
            answer = answer + non + "(" + rep + ")";
            if (nFlag&&answer[0]!='-') answer = "-" + answer;
            return answer;
        }
    }
}

int main(){
    int numerator;
    int denominator;
    std::cin>>numerator>>denominator;
    std::cout<<fractionToDecimal(numerator,denominator)<<std::endl;
    return 0;
}