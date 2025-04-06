#include<iostream>
#include<string>
#include<set>

using std::string;

class Date{
private:
unsigned int Day;
string Month;
int Year;

string lower (string& month){
    int n = month.length();
    for (int i =0;i<n;i++){
        if (month[i]>='A'&&month[i]<='Z'){
            month[i]+='a' - 'A';
        }
    }
    return month;
}

public : 
void setdate(unsigned int day, string month, int year){
    Day = day;
    Month = month;
    Year = year;
}
bool isValidDate(){
    const std::set <string> month30 = {"april","june","september","november"};
    const std::set <string> month31 = {"january","march","may","july","august","october","december"};
    const std::set<string> month28 = {"february"};
    string lowermonth = lower(Month);
    // std::cout<<lowermonth<<std::endl;
    if (month31.find(lowermonth)==month31.end()&&month30.find(lowermonth)==month30.end()&&month28.find(lowermonth)==month28.end()) return false;
    else if (month31.find(lowermonth)!=month31.end()){
        std::cout<<"did we get here?"<<std::endl;
        if (Day>31) return false;
        return true;
    }
    else if (month30.find(lowermonth)!=month30.end()){
        if (Day>30) return false;
        return true;
    }
    else if (month28.find(lowermonth)!=month28.end()){
        if (Day>29) return false;
        else {
            if (Day<=28) return true;
            else {
                if (Year%4!=0) return false;
                else if ((Year%4==0)&&(Year%100!=0)) return true;
                else if ((Year%4==0)&&(Year%100==0)&&(Year%400!=0)) return false;
                else return true;
            }
        }
    }
    return true;
}

};

int main(){
    Date d1;
    unsigned int day;
    string month;
    int year;
    std::cin>>day;
    // std::cout<<std::endl;
    std::getline(std::cin,month);
    std::getline(std::cin,month);
    // std::cout<<std::endl;
    std::cin>>year;
    d1.setdate(day,month,year);
    std::cout<<std::boolalpha<<d1.isValidDate()<<std::endl;
    return 0;
}