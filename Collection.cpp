// function definitions for the Collection Class
// // Created by Samuel Scott on 9/22/2017 @ 16:37

// Collection class
// Created by Samuel Scott on 9/22/2017 @ 16:32


#ifndef _Collection_H_
#define _Collection_H_

#include <iostream>
#include <random>

using namespace std;

template <class T> class Collection {

public:

    Collection(int maxSize);
    ~Collection();


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
        this->maxSize = maxSize;
        size = 0;

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
        return (items[0].equals(new T()));
    }

    template <class T>
    bool Collection<T>::notContained(T x) {
        for (int i = 0; i < size; i++) {
            if (x.equals(items[i])) return false;
        }
        return true;
    }

    template <class T>
    void Collection<T>::makeEmpty() {
        for (int i = 0; i < size; i++) {
            items[i] = new T();
        }
        size = 0;
    }


    template <class T>
    bool Collection<T>::insert(T x) {
        if (size < maxSize) {
            items[size] = x;
            size++;
            return true;
        }
        return false;
    }


    template <class T>
    void Collection<T>::remove(T x) {
        for (int i = 0; i < size; i++) {
            if (items[i].equals(x)) {
                items[i] = new T();
            }
        }
        clean();
    }

    template <class T>
    void Collection<T>::removeRandom() {
        // the following code for generating random numbers within a range
            // originates from "https://stackoverflow.com/questions/7560114/random-number-c-in-some-range"
            // and was created by Morgan Stanley, known as "Cubbi" on stackoverflow
            // this code does make use of the "random" class
            // further info available in README.md

        random_device rd; // obtain a random number from hardware
        mt19937 eng(rd()); // seed the generator
        uniform_int_distribution<> distr(0, size - 1); // define the range

        // remove the item at the random index
        items[distr(eng)] = new T();

        // clean the array
        clean();
    }

//protected:
    template <class T>
    void Collection<T>::clean() {
        for (int i = 0; i < size - 1; i++) {
            static int index;

            if (items[i].equals(new T())) {
                index = i;

                do {
                    index++;
                } while (items[index].equals(new T()) && index < size);

                items[i] = items[index];
                items[index] = new T();
            }
        }

        int i = 0;
        while (i < maxSize && !items[i].equals(new T())) {
            i++;
        }
        size = i;
    }
