//
// Room.cpp
//
//
// This file is the implementation of Room Class Functions.
//

#include "Room.h"

namespace GameCompanyProjectName {
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Room Class Implementation
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// Room Connect function Given a Door and pointer to existing Room
	// Example connection
	//		A North: B			
	//		B South: C
	//		C North: C
	//		C East: A
	//
	void Room::Connect(Door door, Room* destRoom) {
		switch (door) {
		case(Door::NORTH):
			northDoor = destRoom;
			break;
		case(Door::SOUTH):
			southDoor = destRoom;
			break;
		case(Door::EAST):
			eastDoor = destRoom;
			break;
		case(Door::WEST):
			westDoor = destRoom;
			break;
		}

	}

	bool Room::PathExistsTo(const char* endingRoomName) {
		// Create a set list of names of rooms that has been visited
		// This is to help with knowing when to exit loop
		set<const char*> visited;

		// Start a loop by calling a recursive function,
		// function will return true if it finds 
		// ending room else it returns false
		return PathExistsToLoop(endingRoomName, &visited);
	}

	bool Room::PathExistsToLoop(const char* endingRoomName, set<const char*>* visited) {

		// Compare Ending Room with Current Rooms Name
		// if equal, then room is found and return true
		if (strcmp(endingRoomName, roomName) == 0) {
			return true;
		}

		// Check if room is in Visited list, then we checked all doors already and
		// room doesn't lead to ending room, so exit false
		if (visited->find(roomName) != visited->end()) {
			return false;
		}

		// Room is new, so add room to Visited List so it cannot be searched again
		visited->emplace(roomName);

		// Check each Door this room leads to by calling self function recursively.
		// Double check just incase door is not assigned to anything
		return ((northDoor && northDoor->PathExistsToLoop(endingRoomName, visited)) ||
				(southDoor && southDoor->PathExistsToLoop(endingRoomName, visited)) ||
				(eastDoor && eastDoor->PathExistsToLoop(endingRoomName, visited)) ||
				(westDoor && westDoor->PathExistsToLoop(endingRoomName, visited)));
	}

} // End of GameCompanyProjectName