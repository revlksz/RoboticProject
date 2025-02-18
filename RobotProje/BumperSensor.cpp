// 07.01.2024

/**
 * @file BumperSensor.h
 * @brief BumperSensor sinifinin implementasyonunu icerir.
 */

#include "BumperSensor.h"
#include <iostream>
#include <vector>
#include <string>

 /**
  * @brief BumperSensor sinifinin costructor fonksiyonu.
  * @param robot NaoRobotAPI ornegine bir isaretci.
  */
BumperSensor::BumperSensor(NaoRobotAPI* robot) : robotAPI(robot), states{ false,false,false,false } {}

 /**
  * @brief Belirtilen sensorun durumunu alir.
  * @param index Sensorun indis degeri.
  * @return Belirtilen sensorun durumu.
  *
  */
bool BumperSensor::getState(int index) const {
    return this->states[index];
}

/**
 * @brief Sensoru gunceller ve guncel ayak tampon durumlarini icerir.
 * @param _states Guncellenmis sensor durumlarini iceren dizi.
 */
void BumperSensor::updateSensor() 
{
    robotAPI->getFootBumpers(states[0], states[1], states[2], states[3]);
}

/**
 * @brief Tum sensorlerin temas durumuna bakarak, en az bir temas varsa true yoksa false dondurur.
 * @return True: En az bir sensor temas etmisse, False: Temas yoksa.
 *
 */
bool BumperSensor::checkTouch() {
    for (auto j = 0; j < 4; j++) {
        if (this->states[j] == true) return true;
    }
    return false;
}


/**
 * @brief getState() fonksiyonunu kullanarak her bir sensorun durumunu string olarak dondurur.
 * @return result: olusturulan sensor durumlarini dondurur.
 *
 */
std::string BumperSensor::getSensorValue() {
    std::vector<std::string> temp;

    for (int i = 0; i < 3; i++) {
        temp.emplace_back("[" + std::to_string(i) + "] ");
        temp.emplace_back(getState(i) ? "touching, " : "not touching, ");
    }

    temp.emplace_back("[4] ");
    temp.emplace_back(getState(4) ? "touching." : "not touching.");

    std::string result;
    for (const auto& str : temp) {
        result += str;
    }

    //// accumulate: vector icinde bulunan degerleri ilk inputtan ikinci inputa kadar, araya ucuncu inputtaki stringi koyarak atar verilen stringe atar.
    //std::string result = std::accumulate(temp.begin(), temp.end(), std::string(""));

    return result;
}

/**
 * @class BumperSensor
 * @brief Robotun her iki ayaginin on kisminda yer alan ayak tampon sensorleri icin veri ve islemleri yonetir.
 *
 * BumperSensor sinifi, robotun ayak tampon sensorleri ile ilgili veri ve islemleri yonetir.
 * Bu sensorler, her bir bacakta iki adet olup, normalde false iken, bir engelle temas etmeleri durumunda true olurlar.
 */
