#include<iostream>

class rectangle{

    double length = 1;
    double width = 1;

    public : 
    void setLength(double Length){
        length = Length;
    }
    double getLength(){
        return length;
    }
    void setWidth(double Length){
        width = Length;
    }
    double getWidth(){
        return width;
    }
    void perimeter(){
        double peri = 2*(length+width);
        std::cout<<"The perimeter of the given rectangle with length "<<length<<" and width "<<width<<", is : "<<peri<<"."<<std::endl;
       // return peri;
    }
    void area(){
        double peri = length*width;
        std::cout<<"The area of the given rectangle with length "<<length<<" and width "<<width<<", is : "<<peri<<"."<<std::endl;
    }
};

int main(){
    rectangle r1;
    r1.perimeter();
    r1.area();
    r1.setLength(5);
    r1.setWidth(4);
    r1.perimeter();
    r1.area();
    return 0;
}