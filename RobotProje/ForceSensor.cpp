// 07.01.2024

/**
 * @file ForceSensor.h
 * @brief ForceSensor sinifi icin baslik dosyasi.
 */

#include "ForceSensor.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

/**
 * @brief ForceSensor sinifinin costructor fonksiyonu.
 * @param robot NaoRobotAPI ornegine bir isaretci.
 */
ForceSensor::ForceSensor(NaoRobotAPI* robot) : robotAPI(robot), force(0.0) {}

/**
 * @brief Sensor degerini gunceller, mevcut foot kuvvetini robot API'sinden alarak.
 */
void ForceSensor::updateSensor() {
    force = robotAPI->getFootForce();  // Guncel sensor degerlerini robottan 'force' degiskenine yukkler.
}

/**
 * @brief Sensorden mevcut kuvvet degerini alir.
 * @return Sensor kuvvet degeri.
 */
double ForceSensor::getForce() {
    return force;  // Sensor kuvvet degerini dondurur.
}

/**
 * @brief Belirli bir dusme esigine gore robotun dusup dusmedigini kontrol eder.
 * @return Eger robot dustuyse true, aksi halde false.
 */
bool ForceSensor::checkFall() {
    const double fallThreshold = 1;  // Robotun yaklasik olarak 5-6 kilogramlýk foot kuvveti bulunmaktadir; bu degerin altinda ise robot dusmus kabul edilir
    if (getForce() > fallThreshold) {
        return true;  // Eger kuvvet degeri dusme esiginin altindaysa true dondurur
    }
    else {
        return false;  // Eger kuvvet degeri dusme esiginin ustunde veya esitse false dondurur
    }
}

/**
 * @brief getForce() fonksiyonunu kullanarak force durumunu string olarak dondurur.
 * @return result: olusturulan sensor durumunu dondurur.
 *
 */
std::string ForceSensor::getSensorValue()
{
    std::vector<string> temp;
    temp.push_back(to_string(getForce()));  // alinan force degerini stringe cevirip temp vectorune atar
    temp.push_back(" kg.f");

    std::string result;
    for (const auto& str : temp) {
        result += str;
    }

    //std::string result = accumulate(temp.begin(), temp.end(), "");

    return result;
}
