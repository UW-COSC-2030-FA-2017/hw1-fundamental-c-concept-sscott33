// function definitions for the Collection Class
// // Created by Samuel Scott on 9/22/2017 @ 16:37

#include "Collection.h"

//public:

    template <class T>
    Collection<T>::Collection(int maxSize) {
        this->maxSize = maxSize;
        size = 0;
        /*this->type*/ items[maxSize];
    }

    template <class T>
    Collection<T>::~Collection() {
        delete size;
        delete maxSize;
        delete items;
    }

    template <class T>
    bool Collection<T>::isEmpty() {
        return (items[0] == NULL);
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
            items[i] = NULL;
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
            if (items[i] == x) {
                items[i] = NULL;
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
        items[distr(eng)] = NULL;

        // clean the array
        clean();
    }

//protected:
    template <class T>
    void Collection<T>::clean() {
        for (int i = 0; i < size - 1; i++) {
            static int index;

            if (items[i] == NULL) {
                index = i;

                do {
                    index++;
                } while (items[index] == NULL && index < size);

                items[i] = items[index];
                items[index] = NULL;
            }
        }

        int i = 0;
        while (i < maxSize && items[i] != NULL) {
            i++;
        }
        size = i;
    }
