#include "RobotControl.h"
#include <iostream>

using namespace std;

/**
 * @brief Test function for RobotControl class.
 */
void robot_control_test() {
    // Test RobotControl class
    RobotControl robot;

    // Test basic movements
    robot.forward();
    cout << "Moving forward...\n";
    robot.print();

    robot.backward();
    cout << "Moving backward...\n";
    robot.print();

    robot.turnLeft();
    cout << "Turning left...\n";
    robot.print();

    robot.turnRight();
    cout << "Turning right...\n";
    robot.print();

    robot.stop();
    cout << "Stopping...\n";
    robot.print();

    // Test sidestepping
    robot.moveLeft();
    cout << "Sidestepping to the left...\n";
    robot.print();

    robot.moveRight();
    cout << "Sidestepping to the right...\n";
    robot.print();
}
