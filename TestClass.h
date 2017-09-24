
#ifndef _TestClass_H_
#define _TestClass_H_

class TestClass {

public:

    TestClass();
    TestClass(int num, double dbl);

    ~TestClass();

    bool equals(TestClass x);

    //void
    // idea .equals(NULL);

protected:
    int number;
    double dblNumber;
    bool nullified;
};

#endif
