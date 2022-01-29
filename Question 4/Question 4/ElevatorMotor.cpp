//==========================================================================================
//  ElevatorMotor.cpp
//
//  Description: Implements the ElevatorMotor interface.
//==========================================================================================
#include "ElevatorMotor.h"


namespace GameCompanyProjectName
{
    //==========================================================================================
    //  getCurrentDirection()
    //
    //  Description: Returns Motor's current direction
    //==========================================================================================

    ElevatorMotor::Direction ElevatorMotor::getCurrentDirection() const
    {
        return _direction;
    }


    //==========================================================================================
    //  setCurrentDirection()
    //
    //  Description: Sets Motor's current direction
    //==========================================================================================

    void ElevatorMotor::setCurrentDirection(Direction direction)
    {
        _direction = direction;
    }


    //==========================================================================================
    //  getCurrentFloor()
    //
    //  Description: Returns Motor's current floor number.
    //==========================================================================================

    int ElevatorMotor::getCurrentFloor() const
    {
        return _currentFloor;
    }


    //==========================================================================================
    //  getState()
    //
    //  Description: Returns Motor's current state. (Idle, Moving, Open, Close, Opening, etc..)
    //==========================================================================================

    ElevatorMotor::ElevatorState ElevatorMotor::getState() const
    { 
        return _state; 
    }


    //==========================================================================================
    //  setState()
    //
    //  Description: Change the Motor's state.
    //==========================================================================================

    void ElevatorMotor::setState(ElevatorState state)
    {
        _state = state;
    }

    //==========================================================================================
    //  step()
    //
    //  Description: Used to update simulation and update all the states.
    //==========================================================================================
    void ElevatorMotor::step(float deltaSeconds)
    {
        _time += deltaSeconds;

        switch (_state)
        {
        case ElevatorState::Idle:
            if (_doorsOpen)
            {
                _state = ElevatorState::Closing;
            }

            if (checkCallStack())
            {
                _state = ElevatorState::Moving;
            }

            _time = 0.0f;

            break;
        case ElevatorState::Moving:
            if (_doorsOpen)
            {
                _state = ElevatorState::Closing;
            }

            Moving();

            break;
        case ElevatorState::Opening:
            if (_time > _doorSpeed)
            {
                _time = 0.0f;
                _state = ElevatorState::Open;
                _doorsOpen = true;
            }
            break;
        case ElevatorState::Closing:
            if (_time > _doorSpeed)
            {
                _time = 0.0f;
                _state = ElevatorState::Closed;
                _doorsOpen = false;
            }
            break;
        case ElevatorState::Open:
            if (_time > _waitTime)
            {
                _time = 0.0f;
                _state = ElevatorState::Closing;
            }
            break;
        case ElevatorState::Closed:
            if (_time > _waitTime)
            {
                _time = 0.0f;
                _state = ElevatorState::Idle;
            }
            break;
        case ElevatorState::Stop:
            _state = ElevatorState::Opening;
            _time = 0.0f;
            break;

        default:
            break;
        }
    }

    //==========================================================================================
    //  addFloorReachedListener()
    //
    //  Description: Add a floor to the call stack.
    //==========================================================================================

    void ElevatorMotor::addFloorReachedListener(IFloorEventListener* listener)
    {
        _floorReachedEventListeners.insert(listener);
    }

    //==========================================================================================
    //  removeFloorReachedListener()
    //
    //  Description: Removes a given floor from the call stack.
    //==========================================================================================
    void ElevatorMotor::removeFloorReachedListener(IFloorEventListener* listener)
    {
        _floorReachedEventListeners.erase(listener);
    }

    //==========================================================================================
    //  notifyReachedFloor()
    //
    //  Description: Calls each floors to check if floor is valid to be removed from stack.
    //  Floor will then tell motor to stop if it is requested.
    //==========================================================================================
    void ElevatorMotor::notifyReachedFloor(int floor)
    {
        for (auto listener : _floorReachedEventListeners)
        {
            listener->floorReached(floor);
        }
    }

    //==========================================================================================
    //  checkCallStack()
    //
    //  Description: Used to check if there are any floors that need to be visited. Returns
    //  false if empty.
    //==========================================================================================
    bool ElevatorMotor::checkCallStack()
    {
        return !_floorReachedEventListeners.empty();
    }

   //==========================================================================================
   //  toggleDirection()
   //
   //  Description: Changes the motors direction.
   //==========================================================================================
    void ElevatorMotor::toggleDirection() {
        if (_direction == Direction::Up)
        {
            _direction = Direction::Down;
        }
        else {
            _direction = Direction::Up;
        }
    }

    //==========================================================================================
    //  Moving()
    //
    //  Description: Helper function for step(). Help the readablity of step() and move logic
    //  out to its own function.
    //==========================================================================================
    void ElevatorMotor::Moving()
    {
        if (_direction == Direction::None)
        {
            _state = ElevatorState::Idle;
            return;
        }
        else if (_direction == Direction::Up)
        {

            if (_currentFloor == maxFloors || _floorReachedEventListeners.empty())
            {
                _direction = Direction::Down;
                _state = ElevatorState::Idle;
            }

            if (_time > _speedPerFloor)
            {
                if (_currentFloor < maxFloors)
                {
                    _currentFloor++;
                    _time = 0.0;
                    notifyReachedFloor(_currentFloor);
                }
            }
        }
        else if (_direction == Direction::Down)
        {
            if (_currentFloor == 1 || _floorReachedEventListeners.empty())
            {
                _direction = Direction::Up;
                _state = ElevatorState::Idle;
            }

            if (_time > _speedPerFloor)
            {
                if (_currentFloor > 0)
                {
                    _currentFloor--;
                    _time = 0.0;
                    notifyReachedFloor(_currentFloor);
                }
            }
        }
    }

} // End GameCompanyProjectName
