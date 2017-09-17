// AssignmentOperatorExample.cpp : Defines the entry point for the console application.
//

using namespace std;


int main()
{
	int number1, number2, array1[5], array2[5];

	// using "=" we can initialize a variable
	number1 = 1;

	// we can also use one variable to assign values to another variable
	number2 = number1;

	// the assignment operator can also initialize arrays
	for (int i = 0; i < 5; i++)
		array1[i] = i;

	/* unlike the number2 = number 1 example, performing a similar operation is not possible
	   array2 = array1;	(not a valid operation)
	*/

	// instead, we can use values from one array to modify the contents of the other
	for (int i = 0, j = 4; i < 5; i++, j--)
		array2[j] = array1[i];

	// the above loop assigns the values of array1 to array2 in reverse order

	// the "=" operator only accepts values of equal or convertable types (type casting), for example:
	double aDouble = number1;	// this works because there is no loss of valid information

	// this does not always work in the other direction, and some compilers may not accept this
	int anInteger = aDouble;	// note: this operation could result in mathematical inaccuracies as the fractional component of aDouble would be lost


	/// important note: "=" is not "=="
	// the following statement would not work as intended
	if (number1 = number2) {/*contents ommited*/}

	// the above conditional does not check equivocation as it assigns number2's value to number1

	// the correct version of the above statement is as follows:
	if (number1 == number2) {/*contents ommited*/}



    return 0;
}
