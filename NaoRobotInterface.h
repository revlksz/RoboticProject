#pragma once
//Fethiye Nur Baðbozan 
//152120201052
//07.01.2024

#include"NaoRobotAPI.h"
#include"Pose.h"
#include"RobotInterface.h"
class NaoRobotInterface : virtual public RobotInterface
{
protected:
	NaoRobotAPI* robotAPI;
public:

	~NaoRobotInterface();
	/**
	* @brief parametresiz constructor
	*/
	NaoRobotInterface();
	/**
	* @brief parameetreli constructor
	*/
	NaoRobotInterface(NaoRobotAPI* robot) : robotAPI(robot) {}
	/**
	* @brief parametresiz constructor
	*/
	NaoRobotInterface() :robotAPI(nullptr) {}
	/**
	* @brief parameetreli constructor
	*/
	NaoRobotInterface(NaoRobotAPI* robot) : robotAPI(robot) {}
	/**
	* @brief Robot nesnesine eriþim iþlemi
	*/
	//NaoRobotAPI* getRobot();
	/**
	* @brief Robotu sola dondurma islemi.
	*/
	void turnLeft();
	/**
	* @brief Robotu saða dondurma islemi.
	*/
	void turnRight();
	/**
	* @brief Robotu ileriye dogru hareket ettirme islemi
	*/
	void forward();
	/**
	* @brief Robotu geriye dogru hareket ettirme islemi
	*/
	void backward();
	/**
	* @brief Robotu sola dogru hareket ettirme islemi
	*/
	void moveLeft();
	/**
	* @brief Robotu saða dogru hareket ettirme islemi
	*/
	void moveRight();
	/**
	* @brief Robotu durdurma islemi
	*/
	void stop();
	/**
	* @brief Robotun pozisyonunu dondurma islemi
	*/
	//virtual Pose* getPose() = 0;
	/**
	* @brief Robotun mevcut konumunu yazdýrma islmei
	*/
	void print();

	NaoRobotAPI* get_robot() { return robotAPI; }
};