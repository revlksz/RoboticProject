// 07.01.2024


/**
 * @file SonarSensor.h
 * @brief SonarSensor sinifinin implementasyonunu icerir.
 */

#include "SonarSensor.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <string>

 /**
  * @brief SonarSensor sinifinin costructor fonksiyonu.
  * @param robot NaoRobotAPI ornegine bir isaretci.
  */
SonarSensor::SonarSensor(NaoRobotAPI* robot) : robotAPI(robot), ranges { 1.5,1.5 } {}

/**
 * @brief Belirtilen sensorun mesafe bilgisini alir.
 * @param index Sensorun indis degeri.
 * @return Belirtilen sensorun mesafe bilgisi.
 *
 */
double SonarSensor::getRange(int index) {
    return ranges[index];
}

/**
 * @brief Mesafe degerlerinden maksimum olaný ve indisini dondurur.
 * @param index Indeks degeri, maksimum degerin indisini icerecektir.
 * @return Mesafe degerlerinden maksimum olan degeri.
 *
 * Maksimum degeri iceren verinin indisini, parantez icindeki degiskene atar.
 */
double SonarSensor::getMax(int& index) {
    double temp[2]; // Gecici olarak bir dizi olusturup getSonarRange'den alinacak degerleri bu dizi elemanlarýna atar.

    robotAPI->getSonarRange(temp[0], temp[1]); // Robotun sensorlerinden mesafe degerlerini alir.

    if (temp[0] == 0 || temp[1] == 0) return 0; // Bosa atama yapmadan doner.

    double max;
    (temp[0] >= temp[1]) ? (max = temp[0], index = 0) : (max = temp[1], index = 1); // Buyuk olaný max degiskenine atar.

    // Max degiskeni ile aldigimiz buyuk olan degeri, fonksiyona girilen index degerinde bulunan elemana atar.
    return max;
}

/**
 * @brief Mesafe degerlerinden minimum olaný ve indisini dondurur.
 * @param index Indeks degeri, minimum degerin indisini icerecektir.
 * @return Mesafe degerlerinden minimum olan degeri.
 *
 * Minimum degeri iceren verinin indisini, parantez icindeki degiskene atar.
 */
double SonarSensor::getMin(int& index) {
    double temp[2]; // Gecici olarak bir dizi olusturup getSonarRange'den alinacak degerleri bu dizi elemanlarýna atar.

    robotAPI->getSonarRange(temp[0], temp[1]); // Robotun sensorlerinden mesafe degerlerini alir.

    if (temp[0] == 0 || temp[1] == 0) return 0; // Bosa atama yapmadan doner.

    double min;
    (temp[0] >= temp[1]) ? (min = temp[1], index = 1) : (min = temp[0], index = 0); // Kucuk olaný min degiskenine atar.

    // Min degiskeni ile aldigimiz kucuk olan degeri, fonksiyona girilen index degerinde bulunan elemana atar.
    return min;
}

/**
 * @brief Robota ait guncel sensor mesafe degerlerini yukler.
 * @param _ranges Guncel sensor mesafe degerlerini iceren dizi.
 *
 */
void SonarSensor::updateSensor() {
    robotAPI->getSonarRange(ranges[0], ranges[1]);
}

/**
 * @brief Indeksi verilen sensor degerini dondurur.
 * @param index Dizi indeksi.
 * @return Indeksi verilen sensor degeri.
 *
 */
double SonarSensor::operator[](int index) {
    return ranges[index];
}

/**
 * @brief getState() fonksiyonunu kullanarak her bir sensorun mesafesini string olarak dondurur.
 * @return result: olusturulan sensor mesafelerinin yazili oldugu stringi dondurur.
 *
 */
std::string SonarSensor::getSensorValue()
{
    std::vector<string> temp;

    temp.push_back("[0] ");
    temp.push_back(to_string(getRange(0)));     // ilk sensorun gordugu mesafeyi string olarak temp vectorune atar
    temp.push_back(" m , [1] ");
    temp.push_back(to_string(getRange(1)));     // ikinci sensorun gordugu mesafeyi string olarak temp vectorune atar
    temp.push_back(" m.");

    std::string result;
    for (const auto& str : temp) {
        result += str;
    }

    //std::string result = std::accumulate(temp.begin(), temp.end(), " ");    //accumulate ile vectoru stringe atar

    return result;
}

/**
 * @class SonarSensor
 * @brief Sonar mesafe sensoru icin veri tutma ve yonetimini saglar.
 *
 * SonarSensor sinifi, robotun sonar mesafe sensorleri icin veri tutma ve yonetimini saglar.
 */
