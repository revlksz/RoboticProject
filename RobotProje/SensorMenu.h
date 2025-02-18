// 07.01.2024

#ifndef Sensor_Menu_H
#define Sensor_Menu_H

#include <iostream>
#include "NaoRobotAPI.h"
#include "SonarSensor.h"
#include "BumperSensor.h"
#include "ForceSensor.h"
#include "Menu.h"


/**
 * @brief Sensorlerle ilgili islemleri gerceklestiren menu sinifi.
 *
 * Bu sinif, BumperSensor, SonarSensor ve ForceSensor ozelliklerini kullanarak
 * sensorlerle ilgili cesitli islemleri gerceklestirir.
 */
class SensorMenu : Menu
{
private:
	BumperSensor* bumper_sensor;
	SonarSensor* sonar_sensor;
	ForceSensor* force_sensor;
protected:
	SensorMenu()
	{
		//robot_control->set_sensor();
		bumper_sensor = new BumperSensor(robot_control->get_robot());
		sonar_sensor = new SonarSensor(robot_control->get_robot());
		force_sensor = new ForceSensor(robot_control->get_robot());
		//robot_control->unset_sensor();
	}


	/**
	 * @brief Force sensoru ile degme durumunu kontrol eder.
	 */
	void touch_checking() {
		if (bumper_sensor->checkTouch() == true)	std::cout << "Touched!" << std::endl;
		else std::cout << "Not Touched!" << std::endl;
	}

	/**
	 * @brief Force sensoru ile dusme durumunu kontrol eder.
	 */
	void fall_checking() {
		if(force_sensor->checkFall() == true)	std::cout << "Fallen!" << std::endl;
		else if(force_sensor->checkFall() == false) std::cout << "Not Fallen!" << std::endl;

	}

	/**
	 * @brief Sonar sensorunden alinan minimum mesafeyi yazdirir.
	 */
	void min_distance() {
		int index1;
		std::cout << "Min Distance : " << sonar_sensor->getMin(index1) << " ";
		if (index1 == 0) std::cout << "Left Sensor is returning minimum distance!" << std::endl;
		else if(index1 == 1) std::cout << "Right Sensor is returning minimum distance!" << std::endl;
	}

	/**
	 * @brief Sonar sensorunden alinan maksimum mesafeyi yazdirir.
	 */
	void max_distance() {
		int index2;
		std::cout << "Max Distance : " << sonar_sensor->getMax(index2) << " ";
		if (index2 == 0) std::cout << "Left Sensor is returning maximum distance!" << std::endl;
		else if (index2 == 1) std::cout << "Right Sensor is returning maximum distance!" << std::endl;
	}

	void Record_Sensor()
	{
		robot_control->recordSensor(bumper_sensor->getSensorType());
		robot_control->recordSensor(force_sensor->getSensorType());
		robot_control->recordSensor(sonar_sensor->getSensorType());
	}

	void Print_Sensor()
	{
		static string type1 = bumper_sensor->getSensorType();
		robot_control->printSensor(type1);
		static string type2 = force_sensor->getSensorType();
		robot_control->printSensor(type2);
		static string type3 = sonar_sensor->getSensorType();
		robot_control->printSensor(type3);

	}

	void Add_Sensor()
	{
		robot_control->addSensor(bumper_sensor);
		robot_control->addSensor(force_sensor);
		robot_control->addSensor(sonar_sensor);

	}

	/**
	 * @brief Sensor menusunu konsola yazdirir.
	 */
	void printSensorMenu()const 
	{																				
		std::cout << "\nSensor Menu\n1. Touch Checking\n2. Fall Checking\n3. Min Distance\n4. Max Distance\n5. Record Sensor\n6. Print Sensor\n7. Add Sensor\n8. Back\nChoose one: ";

	}
};

#endif