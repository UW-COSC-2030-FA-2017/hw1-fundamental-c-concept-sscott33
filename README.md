This project was created by Samuel Scott.

This project makes use of modified code for generating random numbers within a range and the unmodified version originates from "https://stackoverflow.com/questions/7560114/random-number-c-in-some-range". It was created by Morgan Stanley, known as "Cubbi" on stackoverflow.

//////////////// Begin Morgan Stanley's Code ////////////////
```c++
#include <iostream>
#include <random>
int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    for(int n=0; n<40; ++n)
        std::cout << distr(eng) << ' '; // generate numbers
}
```
///////////////// End Morgan Stanley's Code /////////////////
