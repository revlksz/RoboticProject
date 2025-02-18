#pragma once
#include "Pose.h"
#include "SensorInterface.h"
#include <vector>
class  RobotInterface 
{
private:

	int status;
	std::vector<SensorInterface*> sensorList;
	
public:
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void forward() = 0;
	virtual void backward() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void stop()=0;
	
	virtual void print()=0;
	void updateSensors() {
		for (SensorInterface* sensor : sensorList) {
			sensor->updateSensor();
		}
	}
	void addSensor(SensorInterface* sensor)
	{
		sensorList.push_back(sensor);
	}

};

