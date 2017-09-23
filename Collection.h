// Collection class
// Created by Samuel Scott on 9/22/2017 @ 16:32


#ifndef _Collection_H
#define _Collection_H

#include <iostream>
#include <random>

using namespace std;

template <class T> class Collection {

public:

    Collection<T>(int maxSize);


    /** Accessors **/

    bool isEmpty();
        // returns true IFF there are no objects in the array "items"

    bool notContained(T x);
        // returns true IFF the object "x" is not contained in "items"

    /** Mutators **/

    void makeEmpty();
        // removes all objects from the array

    bool insert(T x);
        // inserts an object "x" as the next abailable array element
        // returns true if there is room and insertion was successful
        // returns false if there is no room in the array and does not...
            // attempt to insert the object

    void remove(T x);
        // removes an object "x" from the array if it exists as an element
        // if multiple "x" equivalents exist, it will remove them too

    void removeRandom(T x);
        // remeoves an object at a random location in the array
        // the indexes that can be chosen are elements of [0,size - 1]


protected:
    /** trait and collection variables **/
    int maxSize;
    int size;

    T items[];


};


#endif
