//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 5, Project 12 b
//  2/03/2016
//  Set made with inheritance

#include <iostream>
#include "set_Inherit_List.h"
using namespace std;

set::set(){}

set::set(const set& other) :List(other){}

void set::insert(const set::size_type& entry) {
    bool found = false;
    start();
    for(int i = 0; i < size(); i++) {
        if (current() == entry){
            found = true;
            break;
        }
        advance();
    }
    start();
    if (found == false){
        attach(entry);
    }
}

void set::takeout(const set::size_type& target){
    //find the element you want to Remove
    start();
    for(int i = 0; i < size(); i++) {
        if (current() == target){
            remove_current();
            break;
        }
        advance();
    }
}

set::value_type set::contains(const set::size_type& target){
    start();
    for(int i = 0; i < size(); i++) {
        if (current() == target){
            return true;
        }
        advance();
    }
    return false;
}

int main()
{
   set s;
   cout << "s" << endl;
   s.insert(10);
   s.insert(20);
   s.insert(30);
   cout << s << endl;

}
