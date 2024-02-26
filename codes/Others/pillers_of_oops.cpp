#include<iostream>
using namespace std;


class animal{
    public:
    string name;
    int count;
    int func1(){
        cout<<"func1 form parent class";
        return 0;
    }
};
// inheriting animal class in men class with mode public
class men: public animal{
    public:
    int height;
    string colour;
    // func1 is being overloaded 
    int func1(){
        cout<<"func1 with no argument"<<endl;
        return 0;
    }
    int func1(int test){
        cout<<"func1 with int argument"<<endl;
        return test;
    }
};

int main(){
    men rahul;
    // using name member of men class which is inherited fom animal
    rahul.name = "Rahul";
    cout<<rahul.name<<endl;
    rahul.func1();
    rahul.func1(1);
    // this is run time polymorphism
    rahul.animal::func1();
}