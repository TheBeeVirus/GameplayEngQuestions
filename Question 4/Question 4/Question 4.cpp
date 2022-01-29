//==========================================================================================
//  Question 4.cpp
//
//  Description: Main() function that runs a simulation to test the ElevatorController.h
//  Class.
// 
//  Simulation Desctiption:
//  Start by summoning Elevator on Floor 2 and 4
//  Floor 2 is summoned first and going UP
//  Floor 4 is summoned afterwards, but going DOWN
//  When Elevator gets to Floor 2, it will OPEN and WAIT before closing
//  When Elevator CLOSES, Elevator will WAIT a few seconds before moving on
//  During CLOSE, Floor 2 user will Select FLOOR 8
//  Elevator will continue to Floor 8
//  Elevator should ignore Floor 4 because it is going DOWN and go to Floor 8
//  Elevator continues moving UP to Floor 8
//  When Elevator reaches Floor 8, it will Open and let Users a chance to leave
//  After Waiting, Elevator will close doors and Flip to DOWN mode
//  Elevator will return to Floor 4, stop, wait for user, then CLOSE doors
//  Floor 4 will select Floor 1, and Elevator will continue to Floor 1
//  When Elevator reaches Floor 1, it will Open, and let users out
//  After waiting, Elevator will CLOSE doors and check if any calls have been made.
//  Because Call Stack is empty, Elevator will switch to Idle
//  Simulation will now terminate program after
// 
//  Total Simulation time should be 170 seconds.
// 
// NOTE:  When Floor 2 and Floor 4 users select Floors, they spam the button like real life,
// so the floors are called multiple times just like normal users will spam press buttons.
// 
//==========================================================================================

#include <iostream>
using std::cout;
using std::endl;

#include "ElevatorController.h"
using namespace GameCompanyProjectName;

// Simulation run time in seconds.
#define SIM_RUN_TIME 170

int main()
{
    // Create Test Elevator from Class
    ElevatorController TestElevator;

    // Test Call get state
    cout << TestElevator.getStringState() << endl;

    // Start timer for simulation
    int timer = 0;
    int startTime = (int)time(NULL);

    // Simulate Users Selecting Summon Elevator on Floors 2 and 4
    TestElevator.summonButtonPushed(2, ElevatorMotor::Direction::Up);
    TestElevator.summonButtonPushed(4, ElevatorMotor::Direction::Down);

    // Start Simulation
    while (timer < SIM_RUN_TIME)
    {
        // Update Timer to current PC Time Tick
        int tempTime = timer;
        timer = (int)time(NULL) - startTime;

        // Updates Elevator simulation engine every loop cycle
        TestElevator.update();

        // Only update status every second NOT loop cycle
        if (tempTime != timer)
        {
            // Outputs Elevator's status and Calls Elevator's Test Function to get
            // Core functions and selects Floor 8 and Floor 1 when Test realizes
            // Floor 2 or Floor 4 users are inside and doors are closed.
            cout << "\n-----------------------------------------------------------\n";
            cout << "Elevator State: " << TestElevator.getStringState() << endl;
            cout << "Elevator Floor: " << TestElevator.getCurrentFloor() << endl;
            TestElevator.test();
            cout << "-----------------------------------------------------------\n";
            cout << endl;
        }
    }
 
    return 0;

} // End of Main