
#include <iostream>
using std::cout;
using std::endl;

#include "SortLetters.h"
using namespace GameCompanyProjectName;

void TestSortLetters();

int main()
{
    TestSortLetters();

} // End of main

void TestSortLetters() {

    cout << endl << "==========================================" << endl;

    cout << "  GameCompanyProjectName US Programming Test: Question 2\n";

    cout << "==========================================" << endl << endl;

    char* inputStr = _strdup("trion world network");
    SortLetters(inputStr, " oinewkrtdl");

    char* inputStr2 = _strdup("ABCBB");
    SortLetters(inputStr2, "ABC");

    char* inputStr3 = _strdup("A");
    SortLetters(inputStr3, "A");

    char* inputStr4 = _strdup("Visual Studio 2019");
    SortLetters(inputStr4, "iad9lSV1u s02to");

    cout << "Test trion world network: '" << inputStr << "'" << endl;
    cout << "ABCBB: '" << inputStr2 << "'" << endl;
    cout << "A: '" << inputStr3 << "'" << endl;
    cout << "Visual Studio 2019: '" << inputStr4 << "'" << endl;

    cout << "Press any key to continue..." << endl;

    system("pause>0");

} // End of TestSortLetters
