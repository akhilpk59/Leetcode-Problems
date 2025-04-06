#include<iostream>
#include<string>
using std::string;

class person{
    string Name = "Nameless";
    string Age = "Ageless";
    string Country = "Countryless";
    public: 
    void setName(string name){
    Name = name;
    }
    void setAge(string age){
    Age = age;
    }
    void setCountry(string country){
    Country = country;
    }
    string getName (){
        return Name;
    }
    string getAge (){
        return Age;
    }
    string getCountry (){
        return Country;
    }
};

int main(){
    person P1;
    std::cout<<P1.getName()<<" is "<<P1.getAge()<<" years old and resides in "<<P1.getCountry()<<"."<<std::endl;
    string name;
    string age;
    string country;
    std::getline(std::cin,name);
    std::getline(std::cin,age);
    std::getline(std::cin,country);
    P1.setName(name);
    P1.setAge(age);
    P1.setCountry(country);
    std::cout<<"The person named "<<P1.getName()<<" is "<<P1.getAge()<<" years old and resides in "<<P1.getCountry()<<"."<<std::endl;
    return 0;
}