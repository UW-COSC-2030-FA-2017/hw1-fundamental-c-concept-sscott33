// function definitions for the Collection Class
// // Created by Samuel Scott on 9/22/2017 @ 16:37

#include "Collection.h"

struct driverObj {};


template <class T> Collection<driverObj>::Collection(int maxSize) {
    this->maxSize = maxSize;
    size = 0;
    this->type items[maxSize];
}

// unncomment main() to check for syntax errors when compiling this file
int main() {
    return 0;
}
