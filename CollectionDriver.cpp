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

    assert TestClassArray.isEmpty();
    cout << "isEmpty() executed successfully" << endl;

    assert TestClassArray.insert(obj1);
    cout << "insert() executed successfully" << endl;

    assert !TestClassArray.notContained(obj1);
    assert !TestClassArray.notContained(obj2);
    cout << "notContained() executed successfully" << endl;

    assert TestClassArray.insert(obj2);
    TestClassArray.remove(obj1);
    assert TestClassArray.notContained(obj1)
    assert !TestClassArray.isEmpty();
    assert TestClassArray.insert(obj3);
    assert TestClassArray.insert(obj3);
    assert TestClassArray.insert(obj4);
    assert !TestClassArray.insert(obj1);
    TestClassArray.remove(obj3);
    assert TestClassArray.notContained(obj3);
    cout << "remove() executed successfully" << endl;

    TestClassArray.makeEmpty();
    assert TestClassArray.isEmpty();
    cout << "makeEmpty() executed successfully" << endl;

    TestClassArray.insert(obj1);
    TestClassArray.insert(obj2);
    TestClassArray.insert(obj3);
    TestClassArray.insert(obj4);
    TestClassArray.removeRandom();
    assert (TestClassArray.notContained(obj1) || TestClassArray.notContained(obj2) || TestClassArray.notContained(obj3) || TestClassArray.notContained(obj4));
    cout << "removeRandom() executed successfully" << endl;




    return 0;
}
