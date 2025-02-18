#include <iostream>
#include "NaoRobotAPI.h"
#include "ForceSensor.h"

using namespace std;

/**
 * @brief Test function for ForceSensor class.
 */
void force_sensor_test() {
    // Simüle edilmis bir NaoRobotAPI nesnesi olustur
    NaoRobotAPI* simulatedRobot = new NaoRobotAPI();

    // ForceSensor sinifinin bir nesnesi olustur ve NaoRobotAPI nesnesi ile iliskilendir
    ForceSensor* forceSensor = new ForceSensor(simulatedRobot);

    // Robotun ayakta oldugu varsayilarak kuvvet degerini guncelle
    forceSensor->updateSensor();

    // Sensörden alinan kuvvet degeri ekrana yazdiriliyor
    cout << "Initial Force: " << forceSensor->getForce() << " kg.f" << endl;

    // Robotun dusup dusmedigi kontrol ediliyor
    if (forceSensor->checkFall()) {
        cout << "Robot has fallen!" << endl;
    }
    else {
        cout << "Robot is still standing." << endl;
    }

    // Simulasyon sona erdiginde kullanilan bellegi serbest birak
    delete forceSensor;
    delete simulatedRobot;
}
