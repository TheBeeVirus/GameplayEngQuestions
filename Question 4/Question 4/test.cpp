#include <iostream>
using std::cout;
using std::endl;

#include "ElevatorController.h"
using namespace GameCompanyProjectName;

#define SIM_RUN_TIME 10

int main()
{
    ElevatorController TestElevator;

    cout << TestElevator.getStringState() << endl;

    int timer = 0;
    int startTime = (int)time(NULL);

    TestElevator.summonButtonPushed(2, ElevatorMotor::Direction::Up);

    while (timer < SIM_RUN_TIME)
    {
        int tempTime = timer;
        timer = (int)time(NULL) - startTime;

        TestElevator.update();

        if (tempTime != timer)
        {
            cout << "\n-----------------------------------------------------------\n";
            cout << "Elevator State: " << TestElevator.getStringState() << endl;
            cout << "Elevator Floor: " << TestElevator.getCurrentFloor() << endl;
            TestElevator.test();
            cout << "-----------------------------------------------------------\n";
            cout << endl;
        }
    }
}