// function definitions for the Collection Class
// // Created by Samuel Scott on 9/22/2017 @ 16:37

// Collection class
// Created by Samuel Scott on 9/22/2017 @ 16:32


// the default form of an object is what is used as a "NULL" for clearing and removal in the list
    // (the object in its "emptiest" form)

#ifndef _Collection_H_
#define _Collection_H_

#include <iostream>
#include <random>

using namespace std;

template <class T> class Collection {

public:

    // constructor and destructor
    Collection(int maxSize);    // must know the size of the array
    ~Collection();              // not really sure how to properly use this
                                // (deleting variables and arrays does not seem to be a valid use)


    /** Accessors **/

    bool isEmpty();
        // returns true IFF there are no objects in the array "items"
        // requires that an empty object accept null in equals()
        // requires that an empty object be equivalent to its default

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

    void removeRandom();
        // remeoves an object at a random location in the array
        // the indexes that can be chosen are elements of [0,size - 1]


protected:
    void clean();
    // moves all objects in the array as forward as possible
    // also removes gaps in the array
    // should be used after each removal mutator function except makeEmpty
    // also updates the size attribue after removals


    // overload the assignment operator
    // template <class T>
    // T& operator= const T &obj;
    //T& operator=(const T& obj);


    /** trait and collection variables **/
    int maxSize;
    int size;


    T *items;




};


#endif

//public:

    template <class T>
    Collection<T>::Collection(int maxSize) {
        // define the constraint maxSize
        this->maxSize = maxSize;

        // array is empty at object creation
        size = 0;

        // define the array type and size
        items = new T[maxSize];
    }

    template <class T>
    Collection<T>::~Collection() {
        // delete size;
        // delete maxSize;
        // delete items;
    }

    template <class T>
    bool Collection<T>::isEmpty() {
        // only need to check the first object b/c all removal operations
            // will shift the remaining objects toward the zero index
        return (items[0].equals(*(new T())));
    }

    template <class T>
    bool Collection<T>::notContained(T x) {

        // search through the array for the specific item
        for (int i = 0; i < size; i++) {
            if (x.equals(items[i])) return false;
        }
        return true;
    }

    template <class T>
    void Collection<T>::makeEmpty() {
        // size may == maxSize
        // all valid entries are elements of the index range [0,size)
        // only clear the valid entries, other entries are already cleared
        for (int i = 0; i < size; i++) {
            items[i] = *(new T());
        }

        // reset the size
        size = 0;
    }


    template <class T>
    bool Collection<T>::insert(T x) {
        // check that there is sufficient space for the new object
        if (size < maxSize) {
            // insert the object after the current valid entries
            items[size] = x;
            size++;
            return true;
        }

        // insufficient space for the new object
        return false;
    }


    template <class T>
    void Collection<T>::remove(T x) {
        // size may == maxSize
        // all valid entries to be checked are elements of the index range [0,size)
        // only clear the valid entries that match the input
        // all valid entries must be checked
        for (int i = 0; i < size; i++) {
            if (items[i].equals(x)) {
                items[i] = *(new T());
            }
        }

        // invoke clean to reorganize the array for use with other operations
        clean();
    }

    template <class T>
    void Collection<T>::removeRandom() {
        // the following code for generating random numbers within a range
            // originates from "https://stackoverflow.com/questions/7560114/random-number-c-in-some-range"
            // and was created by Morgan Stanley, known as "Cubbi" on stackoverflow
            // this code does make use of the "random" class
            // further info and original code available in README.md

        random_device rd; // obtain a random number from hardware
        mt19937 eng(rd()); // seed the generator
        uniform_int_distribution<> distr(0, size - 1); // define the range (inclusive interval)
            // only set the range to the elements containing valid entries

        // remove the item at the random index
        items[distr(eng)] = *(new T());

        // clean the array
        clean();
    }

//protected:
    template <class T>
    void Collection<T>::clean() {

        // shift all valid objects in the direction of the zero index
        for (int i = 0; i < size - 1; i++) {
            static int index;

            if (items[i].equals(*(new T()))) {
                index = i;

                do {
                    index++;
                } while (items[index].equals(*(new T())) && index < size);

                items[i] = items[index];
                items[index] = *(new T());
            }
        }

        // redefine the size to encompass only the valid objects (which are now at the front of the array)
        int i = 0;
        while (i < maxSize && !items[i].equals(*(new T()))) {
            i++;
        }
        size = i;
    }
