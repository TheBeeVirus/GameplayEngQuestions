// Question 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;

#include "Room.h"
using namespace GameCompanyProjectName;

void testRooms();

int main()
{
	testRooms();
}

void testRooms() {

	cout << endl << "==========================================" << endl;

	cout << "  GameCompanyProjectName US Programming Test: Question 3\n";

	cout << "==========================================" << endl << endl;

	// Create Rooms to play with 
	Room A("A");
	Room B("B");
	Room C("C");
	Room D("D");
	Room E("E");
	Room F("F");
	Room G("G");
	Room H("H");
	Room I("I");
	Room J("J");
	Room K("K");
	Room L("L");

	// Create a circle link
	// A -> B <-> C
	// |	|     |  
	// D <- E  -> F
	
	A.Connect(Door::NORTH, &B);
	A.Connect(Door::SOUTH, &D);
	B.Connect(Door::EAST, &C);
	B.Connect(Door::SOUTH, &E);
	C.Connect(Door::SOUTH, &B);
	C.Connect(Door::WEST, &F);
	D.Connect(Door::WEST, &A);
	E.Connect(Door::NORTH, &D);
	E.Connect(Door::SOUTH, &B);
	E.Connect(Door::EAST, &F);
	F.Connect(Door::SOUTH, &C);

	cout << "A to B test: " << A.PathExistsTo("B") << endl;
	cout << "A to F test: " << A.PathExistsTo("F") << endl;
	cout << "C to F test: " << C.PathExistsTo("F") << endl;
	cout << "D to C test: " << D.PathExistsTo("C") << endl;
	cout << "E to A test: " << E.PathExistsTo("A") << endl;

	// Add a few Dead ends
	// A -> B <-> C
	// |	|     |  
	// D <- E  -> F
	// |          v
	// G -> H <- I
	// ^	v       
	// J    K  -> L
	//

	D.Connect(Door::NORTH, &G);
	F.Connect(Door::NORTH, &I);
	G.Connect(Door::NORTH, &H);
	G.Connect(Door::SOUTH, &D);
	H.Connect(Door::SOUTH, &K);
	I.Connect(Door::EAST, &H);
	J.Connect(Door::WEST, &G);
	K.Connect(Door::WEST, &L);

	cout << endl << "Test False... :" << endl;

	cout << "A to J test: " << A.PathExistsTo("J") << endl;
	cout << "K to A test: " << K.PathExistsTo("A") << endl;
	cout << "L to F test: " << L.PathExistsTo("F") << endl;
	cout << "I to G test: " << I.PathExistsTo("G") << endl;
	cout << "C to J test: " << C.PathExistsTo("J") << endl;

}