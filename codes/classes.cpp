#include<iostream>
using namespace std;


class taken{
    int id;
    public:
    void setId(int id){
        this->id=id;
    }
    void getId(){
        cout<<id<<endl;
    }
    taken(){
        // default constructor got called.
    }
    taken(int health,int level,string name){
        this->health=health;
        this->level=level;
        this->name=name;
    }
    int health;
    int level;
    string name;
    // this keyword contains the pointer to the object with the closest scope
    // as this keyword contais the pointer to the object we can not use it directly
    // with dot operator and that is why we use -> with this operator.
    void setHealth(int health){
        this->health = health;
    }
    // this is a setter function to set value of level data memeber
    void setLevel(int level){
        this->level=level;
    }
    void getHealth(){
        cout<<health<<endl;
    }
    // this is a getter function to get value of level data member
    void getLevel(){
        cout<<level<<endl;
    }
    taken(taken &temp){
        this->health= temp.health;
        this->level= temp.level;
        this->name= temp.name;
    }
};

int main(){
    taken paul;
    // we can access public memebers of the class directly
    // without using public functions
    paul.name= "Paul";
    cout<<paul.name<<endl;
    paul.setHealth(100);
    paul.setLevel(20);
    cout<<paul.health<<" "<<paul.level<<endl;
    paul.getHealth();
    // private member we can not set or get the directly we will 
    // always have to use setter and getter functions to perform actions
    paul.setId(1002);
    paul.getId();
    // objects can be allocated dynamically as well and we will be
    // allocating them the same way we allocate any other variable
    taken* gin= new taken;
    gin->setId(1003);
    gin->getId();
    // using a constructor to set the value of data members , we have
    // to remember that constructors can only be called at the time of 
    // object creation . if we use constructor with pault variable of type
    // taken than it will not work as its already initialised
    taken rahul(100,10,"Rahul");
    rahul.getHealth();
    rahul.getLevel();
    cout<<rahul.name<<endl;
    // using constructor with dynamically allocated object of type taken
    taken* rohit = new taken(100,12,"Rohit");
    rohit->getHealth();
    rohit->getLevel();
    cout<<rohit->name<<endl;
    // delete keyword invokes the distructer as for dynamically allocated object
    // decstructor is not called automatically
    delete gin;
    delete rohit;
    // using copy onstructor
    taken shreyansh(paul);
    shreyansh.getHealth();
    shreyansh.getLevel();
    cout<<shreyansh.name<<endl;
    return 0;
}