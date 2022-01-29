//
// Room.cpp
//
//
// This file declares Room Class.
//

#pragma once
#include <set>
using std::set;

//	3. Imagine a maze of interconnected rooms :
//		-Each room has a unique name, and can be connected to between zero and 
//			four other rooms through doors named north, south, east, and west.
//		- Rooms aren’t necessarily spatially coherent.If A is north of B, B might not be south of A.
//		- Doors aren’t necessarily bidirectional.If A can be reached from B, B might not be reachable from A.
//		- Rooms might connect to themselves.
//	3a.Write a class or struct declaration that shows the structure of a Room.Include a constructor(for classes)
//		or initialization function(for structs).

//	3b.Write a function to connect a new Room to an existing Room.

//	3c.Write a function to determine if any path exists between a starting room and an ending room with a given name.
//		You may add additional members and methods to your Room class or struct as needed.You don’t need to worry about 
//		finding the shortest path.It’s only necessary to determine if any path exists.
//		
//		Use this prototype :
//			bool Room::PathExistsTo(const char* endingRoomName);


namespace GameCompanyProjectName {

	enum class Door {NORTH, SOUTH, EAST, WEST};

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Room Class Declaration
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	class Room {
	public:
		Room(const char* name) {
			roomName = name;
		}

		// Room Connect function Given a Door and pointer to existing Room
		// Kind of like a linked list
		void Connect(Door door, Room* destRoom);

		// Check if connected to room with given name
		bool PathExistsTo(const char* endingRoomName);

	private:
		// Save Room's Name
		const char* roomName;

		// Pointers for each door for the room
		// Connect function will set these
		Room* northDoor = nullptr;
		Room* southDoor = nullptr;
		Room* eastDoor = nullptr;
		Room* westDoor = nullptr;

		// A Recursive function to loop through all four rooms, and store room name
		// to make sure loop stops if it revists the same room. Returns true if name
		// matches endingRoomName given by PathExistsTo
		bool PathExistsToLoop(const char* endingRoomName, set<const char*>* visited);
	};

} // End of GameCompanyProjectName