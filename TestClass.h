
#ifndef _TestClass_H_
#define _TestClass_H_

class TestClass {

public:

    // constructors
    TestClass();
        // bool nullified == true
    TestClass(int num, double dbl);
        // bool nullified == false

    ~TestClass();


    /*** Accessors ***/
    
    // function to check information based equivalence
    bool equals(TestClass x);

protected:
    // member variables
    int number;
    double dblNumber;

    // since the above two values have to be numbers, a value to reflect the state of the object's definition is needed
    bool nullified;
};

#endif
