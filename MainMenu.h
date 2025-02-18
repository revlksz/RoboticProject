#pragma once
#include "ConnectionMenu.h"
#include "MotionMenu.h"
#include "SensorMenu.h"

/**
 * @brief Ana menu sinifi.
 *
 * Bu sinif, baglanti, hareket ve sensor menulerini icerir. Kullanýcýya menu seceneklerini sunar ve
 * kullanicinin secimine gore ilgili alt menuyu calistirir.
 */
class MainMenu : protected ConnectionMenu, protected MotionMenu, protected SensorMenu
{
private:
    int menuNumber; ///< Kullanicinin sectigi menu numarasi.

public:
    /**
     * @brief Ana menuyu baslatan fonksiyon.
     *
     * Kullaniciya ana menu seceneklerini sunar ve secilen menuyu calistirir.
     */
    void start()
    {
        int access_code = 1881;     // belirlenen erisim kodu
        static int input_access;
        while (true)
        {
            printAccessMenu();
            std::cin >> input_access;
            if (input_access == access_code)
            {
                std::cout << "Access granted!\n";
                break;
            }
            std::cout << "Access denied!\n";
        }
        while (1)
        {
            printMainMenu();
            std::cin >> menuNumber;
            switch (menuNumber)
            {
            case 1:
                get_connection_menu();
                break;
            case 2:
                get_motion_menu();
                break;
            case 3:
                get_sensor_menu();
                break;
            case 4:
                return;
                break;
            }
        }
    }

    /**
     * @brief Baglanti menusunu baslatan fonksiyon.
     *
     * Kullaniciya baglanti menu seceneklerini sunar ve secilen islemi gerceklestirir.
     */
    void get_connection_menu()
    {
        while (1)
        {
            printConnectionMenu();
            std::cin >> menuNumber;

            switch (menuNumber)
            {
            case 1:
                connect_robot();
                break;
            case 2:
                disconnect_robot();
                break;
            case 3:
                return;
                break;
            default:
                break;
            }
        }
    }

    /**
     * @brief Hareket menusunu baslatan fonksiyon.
     *
     * Kullaniciya hareket menu seceneklerini sunar ve secilen hareketi gerceklestirir.
     */
    void get_motion_menu()
    {
        while (1)
        {
            printMotionMenu();
            std::cin >> menuNumber;
            switch (menuNumber)
            {
            case 1:
                back();
                break;
            case 2:
                forward();
                break;
            case 3:
                MoveLeft();
                break;
            case 4:
                MoveRight();
                break;
            case 5:
                TurnLeft();
                break;
            case 6:
                TurnRight();
                break;
            case 7:
                stop();
                break;
            case 8:
                Get_Pose();
                break;
            case 9:
                Add_To_Path();
                break;
            case 10:
                Clear_Path();
                break;
            case 11:
                Record_Path();
                break;
            case 12:
                return;
                break;
            default:
                break;
            }
        }
    }

    /**
     * @brief Sensor mensunu baslatan fonksiyon.
     *
     * Kullaniciya sensor menu seceneklerini sunar ve secilen islemi gerceklestirir.
     */
    void get_sensor_menu()
    {
        while (1)
        {
            printSensorMenu();
            std::cin >> menuNumber;
            switch (menuNumber)
            {
            case 1:
                touch_checking();
                break;
            case 2:
                fall_checking();
                break;
            case 3:
                min_distance();
                break;
            case 4:
                max_distance();
                break;
            case 5:
                Record_Sensor();
                break;
            case 6:
                Print_Sensor();
            case 7:
                Add_Sensor();
                break;
            case 8:
                return;
                break;
            default:
                break;
            }
        }
    }

    /**
     * @brief Ana menuyu ekrana yazdiran fonksiyon.
     */
	void printMainMenu()const {
		std::cout << "\nMain Menu\n1.Connection\n2.Motion\n3.Sensor\n4.Quit" << std::endl;
	}

    /**
     * @brief Access kodu isteyen fonksiyon.
     */
    void printAccessMenu()
    {
        std::cout << "Enter Access Code : ";
    }
};

