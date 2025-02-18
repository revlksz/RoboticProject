#pragma once

#include "RobotControl.h"
#include "Record.h"

/**
 * @brief Temel menu sinifi.
 *
 * Bu sinif, temel menu islevselligini saglar ve bu menulerin ortak ozelliklerini icerir.
 */
class Menu
{
protected:
    RobotControl* robot_control; ///< Robot kontrol nesnesi.
    Record* record;             ///< Kayit nesnesi.
    Pose* pose;                 ///< Pozisyon nesnesi.

public:
    /**
     * @brief Menu sinifinin constructor fonksiyonu.
     *
     * Constructor fonksiyon, robot kontrol, kayit ve pozisyon nesnelerini olusturur.
     */
    Menu() : robot_control(new RobotControl()), record(new Record()), pose(new Pose()) {}
};
