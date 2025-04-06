#include<iostream>

const double pi = 3.14159265358979323846;

class circle{
    private : 
    double radius = 1;
    public : 
    double area(){
        return pi*radius*radius;
    }
    double circumference(){
        return 2*pi*radius;
    }
    void setRadius(double Radius){
        radius = Radius;
    }
    double getRadius(){
        return radius;
    }
};

int main(){

    circle c1;
    std::cout<<"circle of radius : "<<c1.getRadius()<<" has circumference "<<c1.circumference()<<" and area "<<c1.area()<<std::endl;
    std::cout<<"Please set the new radius of the circle to get circumference and area : "<<std::endl;
    double Radius;
    std::cin>>Radius;
    c1.setRadius(Radius);
    std::cout<<"The circle with radius : "<<Radius<<", has circumference : "<<c1.circumference()<<", and area : "<<c1.area()<<"."<<std::endl;
    return 0;   
}