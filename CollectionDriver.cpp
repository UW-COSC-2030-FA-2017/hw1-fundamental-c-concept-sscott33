// driver to test the Collection class
// created by Samuel Scott on 9/23/2017 at 15:40

//#include <cassert>
    // assert statements never seemed to work
#include "Collection.cpp"
#include "TestClass.cpp"
    // the class created to represent an arbitrary object type for use in this driver
#include <iostream>


int main() {

    // create objects that can be used to test the Collection class
    TestClass obj1(0,0);
    TestClass obj2(10,2.5);
    TestClass obj3(4,5.5);
    TestClass obj4(8,8);

    // create a Collection for type TestClass that can contain 4 TestClass objects
    Collection<TestClass> TestClassArray(4);

////////////////////////////////////////////////////////////
    // check the isEmpty() function
    // (array not yet populated)
    if (TestClassArray.isEmpty()) {
        cout << "isEmpty() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "isEmpty() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }

////////////////////////////////////////////////////////////
    // check the insert() function
    if (TestClassArray.insert(obj1)) {
        cout << "insert() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "insert() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }

////////////////////////////////////////////////////////////
    // check the notContained() function
    if (!TestClassArray.notContained(obj1) && TestClassArray.notContained(obj2)) {
        cout << "notContained() executed successfully" << endl;
        cout << endl;
    }
    else {
        cout << "notContained() failed to execute successfully" << endl;
        cout << endl;
        exit(0);
    }

////////////////////////////////////////////////////////////
    // test the remove() function
    // (obj1 is already in the array)
    if (TestClassArray.insert(obj2)) {

        // check removal of one object
        TestClassArray.remove(obj1);

        // confirm removal and populate the rest of the array
        if (TestClassArray.notContained(obj1)
        && !TestClassArray.isEmpty()
        && TestClassArray.insert(obj3)
        && TestClassArray.insert(obj3)
        && TestClassArray.insert(obj4)
        && !TestClassArray.insert(obj1))    // array should be full; obj1 should not be added
        {
            // check the removal of multiple objects
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

////////////////////////////////////////////////////////////
    // check makeEmpty() function
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

////////////////////////////////////////////////////////////
    // check removeRandom() function

    // fill the array
    TestClassArray.insert(obj1);
    TestClassArray.insert(obj2);
    TestClassArray.insert(obj3);
    TestClassArray.insert(obj4);

    // remove a random object from the array
    TestClassArray.removeRandom();

    // confirm
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
