#include<iostream>
#include<string>

using std::string;

class Employee{
    private :
    string Name = "Nameless";
    string ID = "IDless";
    double Salary = 0;
    public : 
    void setName(string name){
        Name = name;
    }
    void setID(string id){
        ID = id;
    }
    void setSalary(double salary){
        Salary = salary;
    }
    void resetSalary (int performance){
        if (performance > 100) Salary *=1.5;
        else if (performance>=80&&performance<=100) Salary *=1.1;
        else if (performance<80&&performance>=50) Salary *= 0.7;
        else Salary *= 0.4;
    }
    void getSalary(){
        std::cout<<"the employee "<<Name<<" with employee ID "<<ID<<" is currently drawing a salary of Rs. "<<Salary<<"/- per month."<<std::endl;
    }
};

int main(){
    Employee E1;
    E1.setName("Siddarth");
    E1.setID("2");
    E1.setSalary(30000);
    E1.getSalary();
    int performance;
    std::cin>>performance;
    E1.resetSalary(performance);
    std::cout<<"Based on current performance of "<<performance<<" , ";
    E1.getSalary();
    std::cin>>performance;
    E1.resetSalary(performance);
    std::cout<<"Based on current performance of "<<performance<<" , ";
    E1.getSalary();
    std::cin>>performance;
    E1.resetSalary(performance);
    std::cout<<"Based on current performance of "<<performance<<" , ";
    E1.getSalary();
    std::cin>>performance;
    E1.resetSalary(performance);
    std::cout<<"Based on current performance of "<<performance<<" , ";
    E1.getSalary();
    return 0;
}