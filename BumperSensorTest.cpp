//#include "BumperSensor.h"
//#include <iostream>
//
///**
// * @brief Test function for BumperSensor class.
// */
//void BumperSensorTest() {
//
//    NaoRobotAPI* robot = nullptr;
//    bool state[4] = { false,true,false,true };
//    BumperSensor bumper_sensor(state,robot); // Varsayilan olarak states{false,false,false,false} seklinde atanacak.
//
//    std::cout << "BUMPER TEST\n-------------------" << std::endl;
//
//    for (int i = 0; i < 4; i++) {
//        // Ilk statelerin degerini ekrana yazdirir.
//        std::cout << "State " << i + 1 << " is " << bumper_sensor.getState(i) << std::endl;
//    }
//
//    if (bumper_sensor.checkTouch() == true) {
//        std::cout << "Touched!" << std::endl; // Sensor tetiklenmesini kontrol edip ekrana yazdirir.
//    }
//    else {
//        std::cout << "Not touched!" << std::endl;
//    }
//
//    bool arr[4] = { true, true, true, true };
//    bumper_sensor.updateSensor(arr); // getFootBumper'dan gelen degerleri states dizisine atar.
//
//    for (int i = 0; i < 4; i++) {
//        // Degisen statelerin degerini ekrana yazdirir.
//        std::cout << "State " << i + 1 << " is " << bumper_sensor.getState(i) << std::endl;
//    }
//
//    if (bumper_sensor.checkTouch() == true) {
//        std::cout << "Touched!" << std::endl; // Sensor tetiklenmesini kontrol edip ekrana yazdirir.
//    }
//    else {
//        std::cout << "Not touched!" << std::endl;
//    }
//
//}
//    /**
//    * @brief NaoRobotAPI sinifinin getFootBumpers fonksiyonunun test implementasyonu.
//    * @param leftFoot_left Sol ayak sol sensor degeri.
//    * @param leftFoot_right Sol ayak sag sensor degeri.
//    * @param rightFoot_left Sag ayak sol sensor degeri.
//    * @param rightFoot_right Sag ayak sag sensor degeri.
//    */
//void NaoRobotAPI::getFootBumpers(bool& leftFoot_left, bool& leftFoot_right, bool& rightFoot_left, bool& rightFoot_right) {
//    // Test icin sabit degerler atanir.
//    leftFoot_left = true;
//    leftFoot_right = true;
//    rightFoot_left = false;
//    rightFoot_right = false;
//}