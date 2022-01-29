#include <iostream>
using std::cout;
using std::endl;

#include "AllDigitsUnique.h"
using namespace GameCompanyProjectName;

void testAllDigitsUnique();

int main()
{
	testAllDigitsUnique();

}

void testAllDigitsUnique() {

	cout << endl << "==========================================" << endl;

	cout << "  GameCompanyProjectName US Programming Test: Question 1\n";

	cout << "==========================================" << endl << endl;

	cout << "Testing 48778584: " << AllDigitsUnique(48778584) << endl;
	cout << "Testing 17308459: " << AllDigitsUnique(17308459) << endl;
	cout << "Testing 0: " << AllDigitsUnique(0) << endl;
	cout << "Testing 564: " << AllDigitsUnique(564) << endl;
	cout << "Testing 564: " << AllDigitsUnique(564) << endl;
	cout << "Testing 11: " << AllDigitsUnique(11) << endl << endl;

	cout << "Press any key to continue..." << endl;

	system("pause>0");
}
