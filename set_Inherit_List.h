//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 5, Project 12 b
//  2/03/2016
//  Set made with inheritance

#include <cstdlib>  // Provides size_t
#include <iostream>
#include "listbase.h"
class set:public List{
public:
    typedef bool value_type;
    typedef int size_type;
    // CONSTRUCTOR
    set( );
    set(const set& other);
    // MODIFICATION MEMBER FUNCTIONS
    void insert(const size_type& entry);
    void takeout(const size_type& target);
    // CONSTANT MEMBER FUNCTIONS
    value_type contains(const size_type& target);
};
