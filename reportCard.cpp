#include<iostream>
#include<fstream>

void create(){
    std::fstream fout;
    fout.open("reportCard.csv",std::ios::out|std::ios::app);
    std::cout<<"Enter the details of the students in the following order : Name, Roll number, Maths Marks, Physics Marks, Chemistra Marks"<<std::endl;
    std::cout<<"At the end, Enter Q to finish entering the application"<<std::endl;
    int mat,phy,chem;
    std::string name = "",roll = "";
    fout<<"Name, Roll Number, Math, Physics, Chemistry\n";
    
    do {
        std::cout<<"Enter name\n";
        std::getline(std::cin>>std::ws,name);
        if (name=="q"||name=="Q") break;
        std::cout<<"Enter roll number\n";
        std::cin>>roll;
        std::cout<<"Enter Maths Marks\n";
        std::cin>>mat;
        std::cout<<"Enter Physics Marks\n";
        std::cin>>phy;
        std::cout<<"Enter Chemistry Marks\n";
        std::cin>>chem;

        fout<<name<<", "<<roll<<", "<<mat<<", "<<phy<<", "<<chem<<std::endl;
        std::cout<<"If you want to stop entering data, please enter Q/q at the next name prompt\n";

    } while (name!="q"&&name!="Q");
    fout.close();
    std::cout<<"Here are the contents of the file saved by you\n";
    fout.open("reportCard.csv");
    while (std::getline(fout,name)){
        std::cout<<name<<std::endl;
    }
}

int main(){
    create();
    return 0;
}