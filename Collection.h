// Collection class
// Created by Samuel Scott on 9/22/2017 @ 16:32


#ifndef _Collection_H
#define _Collection_H

#include <iostream>

using namespace std;

template <class T> class Collection {

public:

    Collection<T>(int maxSize);


    /** Accessors **/
    bool notContained(T item) {
        // returning true right now to compile and check syntax
        return true;
    }

    /** Mutators **/

protected:
    /** trait and collection variables **/
    int maxSize;
    int size;

    T items[];


};


#endif
