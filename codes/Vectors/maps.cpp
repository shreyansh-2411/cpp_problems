#include<iostream>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;


void printMap(map<int,string> map1){
    for(auto it : map1){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void printMap(unordered_map<int,string> map1){
    for(auto it : map1){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void printSet(set<int> s){
    for(auto it : s)
        cout<<it<<" ";
    cout<<endl;
}

int main(){
    map<int,string> map1;
    // here int is the key of map and string is the value , we store values 
    // in a key value pair for maps ( first element is the key )
    map1[3]= "first";
    map1.insert({5,"second"});
    // we can insert a value inside a map using either of above mentioned methods
    
    // using the below code we can make an iterator for map and traverse through it
    for(map<int,string>::iterator it= map1.begin();it !=map1.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    // We can make our code simpler and smaller while traversing through data
    // structures using range based loops ( below is syntax for that). In this 
    // method we don't define a iterator 
    
    // while using range based loops we have to remember that they take the value
    // by default , to use them as reference we have to user the & operator 
    // and with this we have to use const with key value in case of map as for 
    // map key is const by default .
    for(pair<const int,string> &it : map1){
        cout<<it.first<<" "<<it.second<<endl;
    }
    // we can make this code even smaller , we can use range based loops with auto
    // keyword which will automatically assign the data type.
    for(auto it : map1){
        cout<<it.first<<" "<<it.second<<endl;
    }
    map<string,int> map2;
    map2["Shreyansh"]=10;
    map2["Rahul"]=5;
    for(auto &it : map2){
        cout<<it.first<<" "<<it.second<<endl;
    }
    // in the above example of map you can see that the first value will always
    // be the key of the map , it does not matter if it is integer or not
    map1.insert({4,"fourth"});
    map1.insert({10,"seventh"});
    printMap(map1);
    // we can use find function to get any element from a map , we will have to
    // pass key and this function will return an iterator to that element.
    map<int,string>::iterator iterator1= map1.find(3);
    cout<<iterator1->first<<" "<<iterator1->second<<endl;
    auto iterator2= map2.find("Rahul");
    cout<<iterator2->first<<" "<<iterator2->second<<endl;
    // if no element is found for this key than iterator next to the last
    // element will be returned that is the end iterator to that data structure
    
    // erase function can be used to delete an element from map
    map1.erase(10);
    printMap(map1);
    // we can also pass an iterator to this function (for element to be deleted)
    map1.erase(iterator1);
    printMap(map1);
    
    // unordered maps are very simiilar to maps in many functionalities ,The major
    // difference is that they are not stroed in any order and their internal imp
    // lementation involves hashing for faster access of data.
    unordered_map<int,string> map3;
    map3[1]="Shreyansh";
    printMap(map3);
    // while using unordered maps we have to remember that we can only used basic
    // data types ( can not use vectors and pair ,unordered_map<pair<int,int>,int> )
    // will not work as there is no internal implemenation for hashing for these
    // complex data types .
    set<int> set1;
    set1.insert(10);
    set1.insert(2);
    printSet(set1);
    // sets are similar to maps , in sets elemets are stored in order
    unordered_map<int,int> map4;
    map4[1]=30;
    map4[3]=20;
    map4[1]=10;
    map4[2]=10;
    // this is another way of using maps (with key value pairs)
    for(auto it : map4){
        cout<<it.first<<" "<<it.second<<endl;
    }
}