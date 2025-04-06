#include<iostream>
#include<string>
using namespace std;

int digit(int num){
int count = 0;
while (num>0){
    count++;
    num/=10;
}
return count;
}

string append_1(string& number, int num){
    if (num==0) return number;
    else if (num==1) return number+=" one";
    else if (num==2) return number+=" two";
    else if (num==3) return number+=" three";
    else if (num==4) return number+=" four";
    else if (num==5) return number+=" five";
    else if (num==6) return number+=" six";
    else if (num==7) return number+=" seven";
    else if (num==8) return number+=" eight";
    else if (num==9) return number+=" nine";
    else return number;
}
string append_2(string& number, int num){
    if (num==10) return number+= "ten";
    else if (num==11) return number+=" eleven";
    else if (num==12) return number+=" twelve";
    else if (num==13) return number+=" thirteen";
    else if (num==14) return number+=" fourteen";
    else if (num==15) return number+=" fifteen";
    else if (num==16) return number+=" sixteen";
    else if (num==17) return number+=" seventeen";
    else if (num==18) return number+=" eighteen";
    else if (num==19) return number+=" nineteen";
    else if (num>=20&&num<=29) return number+=" twenty";
    else if (num>=30&&num<=39) return number+=" thirty";
    else if (num>=40&&num<=49) return number+=" forty";
    else if (num>=50&&num<=59) return number+=" fifty";
    else if (num>=60&&num<=69) return number+=" sixty";
    else if (num>=70&&num<=79) return number+=" seventy";
    else if (num>=80&&num<=89) return number+=" eighty";
    else if (num>=90&&num<=99) return number+=" ninety";
    else return number;
}
string append_3(string& number, int num){
    if (num>=100&&num<=199) return number+=" one hundred";
    else if (num>=200&&num<=299) return number+=" two hundred";
    else if (num>=300&&num<=399) return number+=" three hundred";
    else if (num>=400&&num<=499) return number+=" four hundred";
    else if (num>=500&&num<=599) return number+=" five hundred";
    else if (num>=600&&num<=699) return number+=" six hundred";
    else if (num>=700&&num<=799) return number+=" seven hundred";
    else if (num>=800&&num<=899) return number+=" eight hundred";
    else if (num>=900&&num<=999) return number+=" nine hundred";
    else return number;
}
string append_4(string& number, int num){
    if (num>=1000&&num<=1999) return number+=" one thousand";
    else if (num>=2000&&num<=2999) return number+=" two thousand";
    else if (num>=3000&&num<=3999) return number+=" three thousand";
    else if (num>=4000&&num<=4999) return number+=" four thousand";
    else if (num>=5000&&num<=5999) return number+=" five thousand";
    else if (num>=6000&&num<=6999) return number+=" six thousand";
    else if (num>=7000&&num<=7999) return number+=" seven thousand";
    else if (num>=8000&&num<=8999) return number+=" eight thousand";
    else if (num>=9000&&num<=9999) return number+=" nine thousand";
    else return number;
}

string numberToWords(int num){
    if (num==0) return "Zero";
string number="";
int digits = digit(num);
if (digits==1){
    return append_1(number,num);
}
else if (digits==2){
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
}
else if (digits==3){
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
    
}
else if (digits==4){
    number = append_4(number,num);
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
    
}
else if (digits==5){
    int thou = num/1000;
    number = append_2(number,thou);
    if (thou/10!=1) number = append_1(number,thou%10);
    number+=" thousand";
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
    
}
else if (digits==6){
    int thou = num/1000;
    number = append_3(number,thou);
    thou%=100;
    number = append_2(number,thou);
    if (thou/10!=1) number = append_1(number,thou%10);
    number+=" thousand";
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
    
}
else if (digits==7){
    number=append_1(number,num/1000000);
    number+=" million";
    num%=1000000;
    int thou = num/1000;
    number = append_3(number,thou);
    thou%=100;
    number = append_2(number,thou);
    if (thou/10!=1) number = append_1(number,thou%10);
    number+=" thousand";
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
}
else if (digits==8){
    number=append_2(number,num/1000000);
    if ((num/1000000)/10!=1) number = append_1(number,(num/1000000)%10);
    number+=" million";
    num%=1000000;
    int thou = num/1000;
    number = append_3(number,thou);
    thou%=100;
    number = append_2(number,thou);
    if (thou/10!=1) number = append_1(number,thou%10);
    number+=" thousand";
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
}
else if (digits==9){
    int mill = num/1000000;
    number=append_3(number,mill);
    mill%=100;
    number=append_2(number,mill);
    if (mill/10!=1) number = append_1(number,(num/1000000)%10);
    number+=" million";
    num%=1000000;
    int thou = num/1000;
    number = append_3(number,thou);
    thou%=100;
    number = append_2(number,thou);
    if (thou/10!=1) number = append_1(number,thou%10);
    number+=" thousand";
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
}
else if (digits==10){
    number=append_1(number,num/1000000000);
    number+=" billion";
    num%=1000000000;
    int mill = num/1000000;
    number=append_3(number,mill);
    mill%=100;
    number=append_2(number,mill);
    if (mill/10!=1) number = append_1(number,(num/1000000)%10);
    number+=" million";
    num%=1000000;
    int thou = num/1000;
    number = append_3(number,thou);
    thou%=100;
    number = append_2(number,thou);
    if (thou/10!=1) number = append_1(number,thou%10);
    number+=" thousand";
    num = num%1000;
    number = append_3(number,num);
    num=num%100;
    number = append_2(number,num);
    if (num/10!=1) return append_1(number,num%10);
    else return number;
}

return "";
}

int main(){
    int num;
    cin>>num;
    cout<<numberToWords(num)<<endl;
    return 0;
}