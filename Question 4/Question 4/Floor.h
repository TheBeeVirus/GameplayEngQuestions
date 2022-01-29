#pragma once
//==========================================================================================
//  Floor.h
//
//  Description: Declares the Floor interface. Extends IFloorEventListener
//==========================================================================================
#include "IFloorEventListener.h"
#include "ElevatorMotor.h"

namespace GameCompanyProjectName
{
    class Floor : public IFloorEventListener
    {
    private:
        bool _summonButton = false;
        bool _isDestination = false;
        bool _visited = false;
        ElevatorMotor::Direction _direction = ElevatorMotor::Direction::None;
        int _floorNumber = 0;
        ElevatorMotor *_elevatorMotor;

    public:
        // Floor constructor
        Floor(int floorNumber, ElevatorMotor *elevatorMotor) : _floorNumber(floorNumber),
                                                               _elevatorMotor(elevatorMotor) {}

        // When floorReached called from motor, check if valid floor for elevator
        // to stop, and going the same direction as elevator.  If same direction
        // then stop elevator, else keep going in direction.
        void floorReached(int currentFloor)
        {

            if (currentFloor == _floorNumber)
            {

                if (_isDestination)
                {

                    if (_direction == _elevatorMotor->getCurrentDirection())
                    {
                        //_elevatorMotor->removeFloorReachedListener(this);
                        _elevatorMotor->setState(ElevatorMotor::ElevatorState::Stop);
                        _summonButton = false;
                        _isDestination = false;
                        _visited = true;
                        _direction = ElevatorMotor::Direction::None;
                    }
                }
            }
        }

        // Change floor's direction
        void setDirection(ElevatorMotor::Direction direction)
        {
            _direction = direction;
        }

        // Get floor's direction
        ElevatorMotor::Direction getDirection()
        {
            return _direction;
        }

        // Set if the floor is a destination for the elevator to stop at
        void setDestination(bool destination)
        {
            _isDestination = destination;
        }

        // Return ture if this is a floor location to stop at
        bool isDestination() const
        {
            return _isDestination;
        }

        // If Elevator stopped at this floor, allow control to remove
        // floor.
        bool isVisited() const { return _visited; }

        // Set if the floor has been visited or not
        void setVisited(bool visited) { _visited = visited; }
    };

} // End GameCompanyProjectName
