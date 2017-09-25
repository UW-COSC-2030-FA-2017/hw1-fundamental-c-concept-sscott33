

#include "TestClass.h"

// default constructor (to be used to determine the "emptiness" of an element of the aray)
TestClass::TestClass() {
    number = 0;
    dblNumber = 0;
    nullified = true;
}

// constructor of a "defined" object
TestClass::TestClass(int num, double dbl) {
    number = num;
    dblNumber = dbl;
    nullified = false;
}

// destructor (still not sure how to use this)
TestClass::~TestClass() {
    // the compiler does not like the next two lines when they're uncommented
    // delete number;
    // delete dblNumber;
}

bool TestClass::equals(TestClass x) {
    // return a value reflecting the equivalence of this object to another based on the information contained
    return (number == x.number) && (dblNumber == x.dblNumber) && (nullified == x.nullified);
}
