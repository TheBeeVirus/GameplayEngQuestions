#pragma once
//==========================================================================================
//  ElevatorController.cpp
//
//  Description: Implements the ElevatorController interface.
//==========================================================================================

#include "ElevatorController.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

namespace GameCompanyProjectName {

    //==========================================================================================
    //  ElevatorController()
    //
    //  Description: Constructor that creates a instance of the ElevatorMotor and stores 
    //  it in Base. Creates an array of Floors based off Motor's Max Floors.
    //==========================================================================================

    ElevatorController::ElevatorController() : ElevatorControllerBase(new ElevatorMotor())
    {
        _time = (int)time(NULL);

        _floors = new Floor * [_elevatorMotor->maxFloors];

        for (int i = 0; i < _elevatorMotor->maxFloors; ++i)
        {
            _floors[i] = new Floor(i + 1, _elevatorMotor);
        }
    }

    //==========================================================================================
    //  ~ElevatorController()
    //
    //  Description: Cleans up some memory and destorys Motor and Floors.
    //==========================================================================================

    ElevatorController::~ElevatorController()
    {
        delete _elevatorMotor;

        for (int i = 0; i < _elevatorMotor->maxFloors; ++i)
        {
            delete _floors[i];
        }
    }

    //==========================================================================================
    //  floorButtonPushed()
    //
    //  Description: Checks to make sure it is a valid floor, and then adds it to Motor's Stack.
    //==========================================================================================

    void ElevatorController::floorButtonPushed(int destinationFloor)
    {
        if (destinationFloor <= _elevatorMotor->maxFloors && destinationFloor > 0)
        {
            if (_elevatorMotor->getCurrentFloor() == destinationFloor)
            {
                return;
            }

            ElevatorMotor::Direction newDirection = ElevatorMotor::Direction::Up;

            if ((destinationFloor - _elevatorMotor->getCurrentFloor()) < 0)
            {
                newDirection = ElevatorMotor::Direction::Down;
            }

            if (_elevatorMotor->checkCallStack())
            {
                _elevatorMotor->addFloorReachedListener(_floors[destinationFloor - 1]);
                _floors[destinationFloor - 1]->setDirection(newDirection);
                _floors[destinationFloor - 1]->setDestination(true);
            }
            else
            {
                _elevatorMotor->addFloorReachedListener(_floors[destinationFloor - 1]);
                _floors[destinationFloor - 1]->setDirection(newDirection);
                _floors[destinationFloor - 1]->setDestination(true);
                _elevatorMotor->setCurrentDirection(newDirection);
            }
        }
    }

    //==========================================================================================
    //  summonButtonPushed()
    //
    //  Description: Checks it is a Valid Floor option and then adds to Motor's call stack.
    //==========================================================================================

    void ElevatorController::summonButtonPushed(int summoningFloor, ElevatorMotor::Direction direction)
    {
        if (summoningFloor <= _elevatorMotor->maxFloors && summoningFloor > 0)
        {
            if (!_elevatorMotor->checkCallStack())
            {
                _elevatorMotor->setCurrentDirection(direction);
            }
            _elevatorMotor->addFloorReachedListener(_floors[summoningFloor - 1]);
            _floors[summoningFloor - 1]->setDirection(direction);
            _floors[summoningFloor - 1]->setDestination(true);
        }
    }

   //==========================================================================================
   //  update()
   //
   //  Description: Updates simulation and calls Motor's update simulation "step()". Also,
   //  updates deltaTime.
   //==========================================================================================
    void ElevatorController::update()
    {
        int clockUpdate = (int)time(NULL);
        int deltaTime = clockUpdate - _time;
        _time = clockUpdate;

        _elevatorMotor->step((float)deltaTime);
        for (int iFloor = 0; iFloor < _elevatorMotor->maxFloors; ++iFloor)
        {
            if (_floors[iFloor]->isVisited())
            {
                _elevatorMotor->removeFloorReachedListener(_floors[iFloor]);
                _floors[iFloor]->setVisited(false);

                if (_elevatorMotor->checkCallStack())
                {
                    ElevatorMotor::Direction currDir = _elevatorMotor->getCurrentDirection();
                    bool continueDirection = false;

                    if (currDir == ElevatorMotor::Direction::Up)
                    {
                        for (int i = iFloor; i < _elevatorMotor->maxFloors; ++i)
                        {
                            if (_floors[i]->isDestination())
                            {
                                continueDirection = true;
                            }
                        }
                    }
                    else {
                        for (int i = iFloor; i == 0; --i)
                        {
                            if (_floors[i]->isDestination())
                            {
                                continueDirection = true;
                            }
                        }
                    }

                    if (!continueDirection)
                    {
                        _elevatorMotor->toggleDirection();
                    }


                }
                else {
                    _elevatorMotor->setState(ElevatorMotor::ElevatorState::Stop);
                }


            }
        }
    }

    //==========================================================================================
    //  getElevatorState()
    //
    //  Description: Returns Elevator's current state.
    //==========================================================================================

    ElevatorMotor::ElevatorState ElevatorController::getElevatorState() const
    {
        return _elevatorMotor->getState();
    }

    //==========================================================================================
    //  getMaxFloors()
    //
    //  Description: Returns the max floors allowed.
    //==========================================================================================

    int ElevatorController::getMaxFloors() const
    {
        return _elevatorMotor->maxFloors;
    }


    //==========================================================================================
    //  getStringState()
    //
    //  Description: Converts State to printable string.
    //==========================================================================================

    std::string ElevatorController::getStringState() const
    {
        switch (_elevatorMotor->getState())
        {
        case ElevatorMotor::ElevatorState::Idle:
            return "Idle";
            break;
        case ElevatorMotor::ElevatorState::Moving:
            return "Moving";
            break;
        case ElevatorMotor::ElevatorState::Opening:
            return "Opening";
            break;
        case ElevatorMotor::ElevatorState::Closing:
            return "Closing";
            break;
        case ElevatorMotor::ElevatorState::Open:
            return "Open";
            break;
        case ElevatorMotor::ElevatorState::Closed:
            return "Closed";
            break;
        case ElevatorMotor::ElevatorState::Stop:
            return "Stop";
            break;
        default:
            break;
        }

        return "Unknown";
    }


    //==========================================================================================
    //  getCurrentFloor()
    //
    //  Description: returns current floor.
    //==========================================================================================

    int ElevatorController::getCurrentFloor() const { return _elevatorMotor->getCurrentFloor(); }


    //==========================================================================================
    //  test()
    //
    //  Description: Just added for easy testing during Main().
    //==========================================================================================

    void ElevatorController::test()
    {
        int testDirection = (int)ElevatorControllerBase::_elevatorMotor->getCurrentDirection();

        std::cout << "Direction:  " << testDirection << endl;

        for (int i = 0; i < _elevatorMotor->maxFloors; ++i)
        {
            int testFloorDirection = (int) _floors[i]->getDirection();

            cout << "Floor " << i + 1 << ":  " << _floors[i]->isDestination() << "    Direction: " << testFloorDirection << endl;
        }

        if (ElevatorControllerBase::_elevatorMotor->getCurrentFloor() == 2) {
            if (_elevatorMotor->getState() == ElevatorMotor::ElevatorState::Closed)
            {
                floorButtonPushed(8);
                cout << "Floor 2 has selected Floor 8" << endl;
            }
        }

        if (ElevatorControllerBase::_elevatorMotor->getCurrentFloor() == 4) {
            if (_elevatorMotor->getState() == ElevatorMotor::ElevatorState::Closed)
            {
                floorButtonPushed(1);
                cout << "Floor 4 has selected Floor 1" << endl;
            }
        }
    }
 
} // End GameCompanyProjectName