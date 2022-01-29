#pragma once
//==========================================================================================
//  ElevatorMotor.h
//
//  Description: Declares the ElevatorMotor interface.
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

#include <unordered_set>
#include <functional>
#include "IFloorEventListener.h"

namespace GameCompanyProjectName
{

    class ElevatorMotor
    {
    public:
        enum class Direction
        {
            Up = 1,
            None = 0,
            Down = -1
        };

        enum class ElevatorState
        {
            Idle,
            Moving,
            Opening,
            Closing,
            Open,
            Closed,
            Stop
        };

        const int maxFloors = 10;

    private:
        std::unordered_set<IFloorEventListener *> _floorReachedEventListeners;
        Direction _direction = Direction::None;
        ElevatorState _state = ElevatorState::Idle;
        bool _doorsOpen = false;
        int _currentFloor = 1;
        int _speedPerFloor = 5;
        int _doorSpeed = 3;
        int _waitTime = 5;
        float _time = 0.0;

    public:
        // Returns Motors current direction
        ElevatorMotor::Direction getCurrentDirection() const;

        // Sets Motors current direction
        void setCurrentDirection(Direction direction);

        // Returns Motors current floor
        int getCurrentFloor() const;

        // Returns motor's current state (Idle, Moving, Opening, Open, etc...)
        ElevatorState getState() const;

        // Set motor's current state
        void setState(ElevatorState state);

        // Advances the simulation by deltaSeconds seconds
        virtual void step(float deltaSeconds);

        // Add a floor to Motor's stack
        void addFloorReachedListener(IFloorEventListener* listener);

        // Removes a floor from Motor's stack
        void removeFloorReachedListener(IFloorEventListener* listener);

        // called when the car has reached a particular floor
        virtual void notifyReachedFloor(int floor);

        // Check if call stack is empty or not. False is empty.
        bool checkCallStack();

        // Change Motor's Direction
        void toggleDirection();

    private:
        // Extra function for step function, moved logic out of step.
        // easier on the eyes.
        void Moving();

    };

} // End GameCompanyProjectName
