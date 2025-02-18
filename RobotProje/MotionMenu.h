#pragma once
#include <iostream>
#include "NaoRobotAPI.h"
#include "RobotControl.h"
#include "RobotOperator.h"
#include "Pose.h"
#include "Path.h"
#include "Menu.h"


/**
 * @brief Robotun hareketlerini kontrol eden menu sinifi.
 *
 * Bu sinif, robotun cesitli hareketlerini gerceklestiren fonksiyonlarý icerir.
 * Hareketler gerceklestirildikten sonra pozisyon bilgileri guncellenir.
 */
class MotionMenu:protected Menu
{
protected:

	/**
	 * @brief Robotu geriye dogru hareket ettirir.
	 */
	void back()
	{
		robot_control->backward();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Robotu ileriye dogru hareket ettirir.
	 */
	void forward() 
	{
		robot_control->forward();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Robotu sola dondurur.
	 */
	void TurnLeft() 
	{
		robot_control->turnLeft();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Robotu saga dondurur.
	 */
	void TurnRight() 
	{
		robot_control->turnRight();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Robotu sola kaydirir.
	 */
	void MoveLeft()
	{
		robot_control->moveLeft();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Robotu saga kaydirir.
	 */
	void MoveRight()
	{
		robot_control->moveRight();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Robotun mevcut konumunu dosyaya kaydeder.
	 * @brief Robotun durmasini saglar.
	 */
	void stop()
	{
		robot_control->stop();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	void Get_Pose()
	{
		robot_control->getPose();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	void Add_To_Path()
	{
		robot_control->addToPath();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme

	}

	void Clear_Path()
	{
		robot_control->clearPath();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme

	}

	void Record_Path()
	{
		robot_control->recordPath();
		pose->setPose(robot_control->getPose().getX(), robot_control->getPose().getY(), robot_control->getPose().getTh());	// her hareketinden sonra pozisyonu update etme
	}

	/**
	 * @brief Baslangic noktasindan mevcut konuma kadar olan mesafeyi hesaplar ve ekrana yazdirir.
	 */

	/**
	 * @brief Hareket menusunu ekrana yazdirir.
	 */
	void printMotionMenu()const{																									//			**			*				*				*					*
		std::cout << "\nMotion Menu\n1. Move Back\n2. Move Forward\n3. Move Left\n4. Move Right\n5. Turn Left\n6. Turn Right\n7. Stop\n8. Get Pose\n9. Add to Path\n10. Clear Path\n11. Record Path to File\n12. Back\nChoose one: ";

	}
};

