// function definitions for the Collection Class
// // Created by Samuel Scott on 9/22/2017 @ 16:37

#include "Collection.h"



template <class T>
Collection<T>::Collection(int maxSize) {
    this->maxSize = maxSize;
    size = 0;
    /*this->type*/ items[maxSize];
}

template <class T>
bool notContained(T x) {
    for (int i = 0; i < maxSize; i++) {
        if (x.equals(items[i])) return false;
    }
    return true;
}

template <class T>
void removeRandom(T x) {
    // the following code for generating random numbers within a range
        // originates from "https://stackoverflow.com/questions/7560114/random-number-c-in-some-range"
        // and was created by Morgan Stanley, known as "Cubbi" on stackoverflow
    // this code does make use of the "random" class
}
