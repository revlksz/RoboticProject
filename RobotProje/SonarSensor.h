// 07.01.2024

#ifndef SonarSensor_H
#define SonarSensor_H

#include "NaoRobotAPI.h"
#include "NaoRobotSensorInterface.h"
#include <string>

/**
 * @class SonarSensor
 * @brief Sonar mesafe sensoru icin veri tutma ve yonetimini saglar.
 *
 */
class SonarSensor : public NaoRobotSensorInterface
{
private:
    double ranges[2]; ///< Sensorlerin olctugu mesafe degerlerini iceren dizi.
    NaoRobotAPI* robotAPI; ///< NaoRobotAPI sinifi ile iletisim kurmak icin kullanilan nesne.

public:
    /**
     * @brief constructor.
     *
     * Ranges dizisine inputtaki dizi degerleri atanir ve robotAPI isaretcisine inputtan gelen pointer atanir.
     */
    SonarSensor(NaoRobotAPI* _robotAPI);

    /**
     * @brief Belirtilen sensorun mesafe bilgisini alir.
     * @param index Sensorun indis degeri.
     * @return Belirtilen sensorun mesafe bilgisi.
     */
    double getRange(int index);

    /**
     * @brief Mesafe degerlerinden maksimum olaný ve indisini dondurur.
     * @param index Indeks degeri, maksimum degerin indisini icerecektir.
     * @return Mesafe degerlerinden maksimum olan degeri.
     */
    double getMax(int& index);

    /**
     * @brief Mesafe degerlerinden minimum olaný ve indisini dondurur.
     * @param index Indeks degeri, minimum degerin indisini icerecektir.
     * @return Mesafe degerlerinden minimum olan degeri.
     */
    double getMin(int& index);

    /**
     * @brief Robota ait guncel sensor mesafe degerlerini yukler.
     * @param ranges Guncel sensor mesafe degerlerini iceren dizi.
     */
    void updateSensor()override;

    /**
     * @brief Indeksi verilen sensor degerini dondurur.
     * @param i Dizi indeksi.
     * @return Indeksi verilen sensor degeri.
     */
    double operator[](int i);

    /**
     * @brief Robotun su anki bulundugu sonar sensor durumunu string olarak dondurur.
     */
    std::string getSensorValue() override;
};

#endif // SonarSensor_H
