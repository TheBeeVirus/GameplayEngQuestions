#pragma once
//==========================================================================================
//  ElevatorController.h
//
//  Description: Declares the ElevatorController interface.
//==========================================================================================
#include "Floor.h"
#include "ElevatorControllerBase.h"
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

namespace GameCompanyProjectName
{
    // Subclass of ElevatorControllerBase
    class ElevatorController : public ElevatorControllerBase
    {
    private:
        Floor **_floors;
        int _time = 0;

    public:
        // Constructor
        ElevatorController();

        //Deconstructor
        ~ElevatorController();

        //Simulate Floor button being pressed
        void floorButtonPushed(int destinationFloor);

        //Simulate Floor summon button being pressed
        void summonButtonPushed(int summoningFloor, ElevatorMotor::Direction direction);

        // Run Update for simulation (Calls ElevatorMotor Step Simulation)
        void update();

        // Returns Elevator Motor's current State (Idle, Moving, Opening, Closing, Etc...)
        ElevatorMotor::ElevatorState getElevatorState() const;

        // Returns the max floors the elevator has.
        int getMaxFloors() const;

        // Returns the state as a String for Cout put.
        std::string getStringState() const;

        // Returns current Floor the Motor is at.
        int getCurrentFloor() const;

        // Just for testing a simulation from Main.
        void test();
    };

} // End GameCompanyProjectName
