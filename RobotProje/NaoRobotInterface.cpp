#include"NaoRobotInterface.h"
//Fethiye Nur Bağbozan
//152120201052
//07.01.2024
//NaoRobotAPI* NaoRobotInterface::getRobot() {
//	return robotAPI;
//}
/**
	* @brief Robotu sola dondurur.
	*/


NaoRobotInterface::NaoRobotInterface() : robotAPI(new NaoRobotAPI()) {
	robotAPI->connect();
}

/**
 * @brief RobotControl sinifinin destructor fonksiyonu.
 *
 * robotAPI'yi baglantisini keser ve robotAPI nesnesini siler.
 */
NaoRobotInterface::~NaoRobotInterface() {
	robotAPI->disconnect();
	delete robotAPI;
}
void NaoRobotInterface::turnLeft()  {
	robotAPI->turnRobot(LEFT);
}
void NaoRobotInterface::turnRight() {
	robotAPI->turnRobot(RIGHT);

}
/**
	* @brief Robotu ileriye dogru hareket ettirir
	*/
void NaoRobotInterface::forward() {
	robotAPI->moveRobot(FORWARD);
}
/**
	* @brief Robotu geriye dogru hareket ettirir
	*/
void NaoRobotInterface::backward() {
	robotAPI->moveRobot(BACKWARD);
}
/**
	* @brief Robotu sola dogru hareket ettirir
	*/
void NaoRobotInterface::moveLeft() {
	turnLeft();
	forward();
}
/**
	* @brief Robotu sağa dogru hareket ettirir
	*/
void NaoRobotInterface::moveRight() {
	turnRight();
	forward();
}
/**
	* @brief Robotu durdurur
	*/
void NaoRobotInterface::stop() {

}

/**
	* @brief Robotun bulunduğu konumu yazdırır
	*/
void NaoRobotInterface::print() {
	double x = robotAPI->getX();
	double y = robotAPI->getY();
	double th = robotAPI->getTh();

	std::cout << "Robotun Pozisyonu: X=" << x << " Y=" << y << std::endl;
	std::cout << "Robotun Dönüş Açısı: " << th << " derece" << std::endl;
}