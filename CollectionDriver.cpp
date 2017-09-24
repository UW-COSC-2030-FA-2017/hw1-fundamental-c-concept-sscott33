// driver to test the Collection class
// created by Samuel Scott on 9/23/2017 at 15:40

#include <cassert>
#include "Collection.cpp"
#include "TestClass.cpp"
#include <iostream>


int main() {

    TestClass obj1(0,0);
    TestClass obj2(10,2.5);
    TestClass obj3(4,5.5);
    TestClass obj4(8,8);

    Collection<TestClass> TestClassArray(4);

    if (TestClassArray.isEmpty()) {
        cout << "isEmpty() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "isEmpty() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }

    if (TestClassArray.insert(obj1)) {
        cout << "insert() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "insert() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }


    if (!TestClassArray.notContained(obj1) && TestClassArray.notContained(obj2)) {
        cout << "notContained() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "notContained() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }


    // obj1 is already in the array
    if (TestClassArray.insert(obj2)) {
        TestClassArray.remove(obj1);

        if (TestClassArray.notContained(obj1)
        && !TestClassArray.isEmpty()
        && TestClassArray.insert(obj3)
        && TestClassArray.insert(obj3)
        && TestClassArray.insert(obj4)
        && !TestClassArray.insert(obj1))
        {
            TestClassArray.remove(obj3);

            if (TestClassArray.notContained(obj3)) {
                cout << "remove() executed successfully" << endl;
                cout << endl;
            }
            else {
                cout << "remove() failed to execute successfully" << endl;
                cout << endl;
                exit(0);
            }

        }
    }


    TestClassArray.makeEmpty();
    if (TestClassArray.isEmpty()) {
        cout << "makeEmpty() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "makeEmpty() failed execute successfully" << endl;
        cout << endl;
        exit(0);
    }

    TestClassArray.insert(obj1);
    TestClassArray.insert(obj2);
    TestClassArray.insert(obj3);
    TestClassArray.insert(obj4);
    TestClassArray.removeRandom();
    if (TestClassArray.notContained(obj1) || TestClassArray.notContained(obj2) || TestClassArray.notContained(obj3) || TestClassArray.notContained(obj4)) {
        cout << "removeRandom() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "removeRandom() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }





    return 0;
}
