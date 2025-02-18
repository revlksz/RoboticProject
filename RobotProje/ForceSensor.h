// 07.01.2024


#ifndef FORCE_SENSOR_H
#define FORCE_SENSOR_H

#include "NaoRobotAPI.h"
#include "NaoRobotSensorInterface.h"
#include <string>

/**
 * @class ForceSensor
 * @brief Kuvvet sensoru icin veri tutma ve yonetimini saglar.
 *
 * ForceSensor sinifi, robotun kuvvet sensoru icin veri tutma ve yonetimini saglar.
 */
class ForceSensor : public NaoRobotSensorInterface {

private:
    double force; ///< Sensor tarafindan olculen kuvvet degeri.
    NaoRobotAPI* robotAPI; ///< NaoRobotAPI sinifi ile iletisim kurmak icin kullanilan nesne.

public:
    /**
     * @brief Parametreli constructor.
     * @param robot NaoRobotAPI nesnesi.
     */
    ForceSensor(NaoRobotAPI* robot);

    /**
     * @brief Sensoru gunceller.
     */
    void updateSensor();

    /**
     * @brief Sensor tarafindan olculen kuvvet degerini dondurur.
     * @return Kuvvet degeri.
     */
    double getForce();

    /**
     * @brief Dusme durumunu kontrol eder.
     * @return Eger dusme durumu varsa true, yoksa false.
     */
    bool checkFall();

    /**
     * @brief Robotun su anki bulundugu force sensor durumunu string olarak dondurur.
     */
    std::string getSensorValue()override;
};

#endif //FORCE_SENSOR_H
