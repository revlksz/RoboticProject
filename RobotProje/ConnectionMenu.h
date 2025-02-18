#pragma once
#include <iostream>
#include "NaoRobotAPI.h"
#include "SonarSensor.h"
#include "BumperSensor.h"
#include "ForceSensor.h"
#include "RobotControl.h"
#include "Menu.h"


class ConnectionMenu : protected Menu
{
protected:

	void connect_robot() {
		std::cout << "robot connected"<<std::endl;
		robot_control = new RobotControl();
	}
	void disconnect_robot() {
		std::cout << "robot disconnected"<<std::endl;
		delete robot_control;
	}
	void printConnectionMenu()const {
		std::cout << "\nConnection Menu\n1. Open Access\n2. Close Access\n3.Back\nChoose one: ";
	}
};	

