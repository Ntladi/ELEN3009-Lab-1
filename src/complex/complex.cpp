#include <iostream> // contains the definition of cout, endl
#include <complex> // contains the complex class definition

using namespace std; // cout, endl, complex are all part of this namespace

int main()
{
	auto num1 = complex<float> { 2.0, 2.0 }; // use auto for type deduction
	auto num2 = complex<float> { 4.0, -2.0 }; // use uniform initialization syntax (curly braces)

	auto answer = num1 * num2; // type deduced for 'answer' is: complex<float>

	cout << "The answer is: " << answer << endl;
	cout << "Or in a more familiar form: " << answer.real() << " + "
			<< answer.imag() << "j" << endl << endl;

	// answer++;

	// the commented piece of code does not work because the ++ operator has not been
	// overloaded within the method definition of the complex class.
	// This means that the operator will cause a compile time error
	// rather than incrementing the complex number as intended.

	return 0;
}
