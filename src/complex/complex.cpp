#include <iostream>
#include <complex>
#include <string>

using namespace std;
using compFloat = complex<float>;

bool quit(int &constant);
void calculateRoots(int &a, int &b, int &c);
void manipulateRoots(compFloat &root1, compFloat &root2, int a, int b);
void outputRoot1(compFloat &root1);
void outputRoot2(compFloat &root1);
void outputReal(compFloat &root);
void outputImag(compFloat &root);
bool realConditionsMet(compFloat &root);

int main()
{
	// calculation loop
	while (1)
	{
		// quadratic equation constants
		int a, b, c;

		// input a
		cout << "Please Enter Integer a or \"q\" to Quit: ";
		// if input is q, break
		if (quit(a))
			break;

		// input b
		cout << "Please Enter Integer b or \"q\" to Quit: ";
		// if input is q, break
		if (quit(b))
			break;

		// input c
		cout << "Please Enter Integer c or \"q\" to Quit: ";
		// if input is q, break
		if (quit(c))
			break;

		// calculate roots
		calculateRoots(a, b, c);

	}
	return 0;
}

bool quit(int &constant)
{
	// accept input from user
	string input;
	cin >> input;

	// quit if input is "q" otherwise store the input as an integer
	if (input == "q")
		return true;
	else
		constant = stoi(input);

	return false;
}

void calculateRoots(int &a, int &b, int &c)
{
	auto discriminant = (b * b) - 4 * a * c; // calculate the discriminant

	auto cRoot1 = sqrt(compFloat(discriminant, 0)); // apply the square root

	auto cRoot2 = cRoot1; // clone the result in order to have two potential roots

	manipulateRoots(cRoot1, cRoot2, a, b); // complete the calculation for both potential roots

	outputRoot1(cRoot1); // output the first root

	if (cRoot1 != cRoot2) // if there is a second root output it as well
		outputRoot2(cRoot2);

	cout << endl;
}

void manipulateRoots(compFloat &root1, compFloat &root2, int a, int b)
{
	auto b2 = compFloat(b, 0); // convert b to a complex number

	// add / subtract the square root from -b for both roots
	root1 = -b2 + root1;
	root2 = -b2 - root2;

	// divide both roots by 2*a
	root1 /= 2 * a;
	root2 /= 2 * a;
}

void outputRoot1(compFloat &root1)
{
	// output the first root
	cout << "x1 = ";

	outputReal(root1); // output the real part of the root

	outputImag(root1); // output the imaginary part of the root
}

void outputRoot2(compFloat &root2)
{
	// output the first root
	cout << "x2 = ";

	outputReal(root2); // output the real part of the root

	outputImag(root2); // output the imaginary part of the root
}

void outputReal(compFloat &root)
{
	// if conditions are met, output the real part
	if (realConditionsMet(root))
		cout << root.real() << " ";
}

void outputImag(compFloat &root)
{
	// if the conditions are met, output the imaginary part
	if (root.imag() != 0)
	{
		if (root.imag() > 0)
			cout << "+"; // output a plus if the imaginary part is positive

		cout << root.imag() << "j"; // output a "j" to denote the imaginary part
	}
	cout << endl;
}

bool realConditionsMet(compFloat &root){
	// the conditions necessary for outputting the real part of the root
	return (root.real() == 0 && root.imag() == 0) || root.real() != 0;
}
