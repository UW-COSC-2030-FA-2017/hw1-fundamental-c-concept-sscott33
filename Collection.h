// Collection class
// Created by Samuel Scott on 9/22/2017 @ 16:32


#ifndef _Collection_H
#define _Collection_H

#include <iostream>

using namespace std;

template <class type_> class Collection {

public:

    template <class T> Collection(int maxSize, T obj);


    /** Accessors **/
    template <class T> bool notContained(T item) {
        return true;
    }

    /** Mutators **/

protected:
    /** trait and collection variables **/
    int maxSize;
    int size;

    template <class T> T items[];


};


#endif
