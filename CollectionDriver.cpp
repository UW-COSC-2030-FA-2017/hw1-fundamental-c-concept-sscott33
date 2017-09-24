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

    cout << TestClassArray.isEmpty();
    cout << endl;
    // cout << "isEmpty() executed successfully" << endl;
    //
    cout << TestClassArray.insert(obj1);
    cout << endl;
    // cout << "insert() executed successfully" << endl;
    //
    cout << !TestClassArray.notContained(obj1);
    cout << TestClassArray.notContained(obj2);
    cout << endl;
    // cout << "notContained() executed successfully" << endl;
    //
    cout << TestClassArray.insert(obj2);
    TestClassArray.remove(obj1);
    cout << TestClassArray.notContained(obj1);
    cout << !TestClassArray.isEmpty();
    cout << TestClassArray.insert(obj3);
    cout << TestClassArray.insert(obj3);
    cout << TestClassArray.insert(obj4);
    cout << !TestClassArray.insert(obj1);
    TestClassArray.remove(obj3);
    cout << TestClassArray.notContained(obj3);
    cout << endl;
    // // cout << "remove() executed successfully" << endl;
    // //
    TestClassArray.makeEmpty();
    cout << TestClassArray.isEmpty();
    cout << endl;
    // // cout << "makeEmpty() executed successfully" << endl;
    // //
    TestClassArray.insert(obj1);
    TestClassArray.insert(obj2);
    TestClassArray.insert(obj3);
    TestClassArray.insert(obj4);
    TestClassArray.removeRandom();
    cout << (TestClassArray.notContained(obj1) || TestClassArray.notContained(obj2) || TestClassArray.notContained(obj3) || TestClassArray.notContained(obj4));
    cout << endl;
    // // cout << "removeRandom() executed successfully" << endl;
    //



    return 0;
}
