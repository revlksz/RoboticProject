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
	NaoRobotInterface();

	~NaoRobotInterface();
	/**
	* @brief parametresiz constructor
	*/
	//NaoRobotInterface() :robotAPI(nullptr) {}
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
	void turnLeft() override;
	/**
	* @brief Robotu saða dondurma islemi.
	*/
	void turnRight()override;
	/**
	* @brief Robotu ileriye dogru hareket ettirme islemi
	*/
	void forward()override;
	/**
	* @brief Robotu geriye dogru hareket ettirme islemi
	*/
	void backward()override;
	/**
	* @brief Robotu sola dogru hareket ettirme islemi
	*/
	void moveLeft()override;
	/**
	* @brief Robotu saða dogru hareket ettirme islemi
	*/
	void moveRight()override;
	/**
	* @brief Robotu durdurma islemi
	*/
	void stop()override;
	/**
	* @brief Robotun pozisyonunu dondurma islemi
	*/
	Pose* getPose();
	/**
	* @brief Robotun mevcut konumunu yazdýrma islmei
	*/
	void print();
};