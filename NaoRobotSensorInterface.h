// 07.01.2024

#ifndef NaoRobot_SensorInterface_H
#define NaoRobot_SensorInterface_H

#include "SensorInterface.h"
#include "NaoRobotAPI.h"

class NaoRobotSensorInterface : public SensorInterface
{
protected:
	NaoRobotAPI* robotAPI;	///< robotun adresini tutan pointer.

public:
	/**
	* @brief NaoRobotSensorInterface default constructor fonksiyonu.
	*/
	NaoRobotSensorInterface() : robotAPI(nullptr) {}

	/**
	* @brief NaoRobotSensorInterface parametreli constructor fonksiyonu.
	*/
	NaoRobotSensorInterface(NaoRobotAPI* robot): robotAPI(robot){}
};

#endif // !NaoRobot_SensorInterface_H