

#include "TestClass.h"

TestClass::TestClass() {
    number = 0;
    dblNumber = 0;
    nullified = true;
}

TestClass::TestClass(int num, double dbl) {
    number = num;
    dblNumber = dbl;
    nullified = false;
}

TestClass::~TestClass() {
    // delete number;
    // delete dblNumber;
}

bool TestClass::equals(TestClass x) {
    return (number == x.number) && (dblNumber == x.dblNumber) && (nullified == x.nullified);
}
