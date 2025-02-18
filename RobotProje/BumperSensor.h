// 07.01.2024

#ifndef BumperSensor_H
#define BumperSensor_H

#include "NaoRobotSensorInterface.h"
#include "NaoRobotAPI.h"
#include <iostream>

/**
 * @class BumperSensor
 * @brief Bumper sensoru icin veri tutma ve yonetimini saglar.
 *
 */
class BumperSensor : public NaoRobotSensorInterface
{
private:
    bool states[4]; ///< Sensorlerin temas durumlarini iceren dizi.
    NaoRobotAPI* robotAPI; ///< NaoRobotAPI sinifi ile iletisim kurmak icin kullanilan nesne.

public:
    /**
     * @brief constructor.
     *
     * States dizisine inputtaki _states degerleri atanir ve robotAPI pointer'a inputtaki pointer atanir.
     */
    BumperSensor(NaoRobotAPI* _robotAPI);

    /**
     * @brief Belirtilen indeksteki sensorun temas durumunu alir.
     * @param index Sensorun indis degeri.
     * @return Belirtilen sensorun temas durumu.
     */
    bool getState(int index) const;

    /**
     * @brief Robota ait güncel sensor temas degerlerini yukler.
     */
    void updateSensor()override;

    /**
     * @brief Tum temas durumlarýna bakarak, en az bir temas varsa true, yoksa false dondurur.
     * @return En az bir temas varsa true, yoksa false.
     */
    bool checkTouch();

    /**
     * @brief Robotun su anki bulundugu bumper sensor durumunu string olarak dondurur.
     */
    std::string getSensorValue()override;
};

#endif // BumperSensor_H
