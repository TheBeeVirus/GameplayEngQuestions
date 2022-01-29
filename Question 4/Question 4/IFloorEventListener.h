#pragma once
//==========================================================================================
//  IFloorEventListener.h
//
//  Description: Declares the IFloorEventListener interface.
//==========================================================================================

//  4. Design an elevator controller for a building of ten floors(including the ground floor).
//
//  You will need to complete the supplied ElevatorMotor class by writing implementations of the given methods,
//      getCurrentFloor, getCurrentDirection, setCurrentDirection and step.Your ElevatorController class should
//      implement the interface in ElevatorControllerBase and should defer to the completed ElevatorMotor class
//      for all movementand tracking of position.
//
//  Design your controller to achieve the following goals(listed in order of priority, first being highest
//      priority) to minimize user irritationand /or ensure proper function :
//
//          1.	At no time should an idle elevator be unresponsive to summon calls or when a floor button
//              is pressed.
//
//          2.	At no time should a running elevator car attempt to go below or above the lowest, highest
//              floor respectively.
//
//          3.	For an embarking user, the maximum time for the user to pick a destination floor after
//              boarding the elevator car is 5 seconds.After which, the car can switch to moving.
//
//          4.	For an individual user, minimize the time between boarding an elevator carand reaching the
//              destination floorand disembarking.
//
//          5.	For an individual user, minimize the time between summoning an elevator carand embarking.

namespace GameCompanyProjectName
{
    class IFloorEventListener
    {
    public:
        virtual void floorReached(int) = 0;
    };

} // End GameCompanyProjectName
