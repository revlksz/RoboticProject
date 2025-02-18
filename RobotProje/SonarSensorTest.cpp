//#include "SonarSensor.h"
//#include <iostream>
//
///**
// * @brief Test function for SonarSensor class.
// */
//
//void sonar_sensor_test() {
//    NaoRobotAPI* robot = nullptr;
//    double range[2] = { 4.1,5.3 };
//    SonarSensor sonar_sensor(range,robot); // Varsayilan olarak ranges dizisine 0.0 degerleri atanacak.
//
//    std::cout << "SONAR TEST\n----------------" << std::endl;
//
//    for (int i = 0; i < 2; i++) {
//        std::cout << "Range " << i + 1 << " is " << sonar_sensor.getRange(i) << std::endl; // Range degerlerini getRange fonksiyonuyla ekrana yazdirir.
//
//        std::cout << "Range[" << i + 1 << "] using operator[]: " << sonar_sensor[i] << std::endl; // Range degerlerini operator kullanarak ekrana yazdirir.
//    }
//
//    double arr[2] = { 0.4, 6.2 };
//    sonar_sensor.updateSensor(arr); // Sensorleri robotun getSonarRange fonksiyonunu kullanarak gunceller.
//
//    std::cout << "\nSensors are updated! \n" << std::endl;
//
//    for (int i = 0; i < 2; i++) // Range degerlerini ekrana yazdirir.
//    {
//        std::cout << "Range " << i << " is " << sonar_sensor.getRange(i) << std::endl;
//        std::cout << "Range[" << i + 1 << "] using operator[]: " << sonar_sensor[i] << std::endl;
//    }
//
//    int max;
//    std::cout << "\nMax value : " << sonar_sensor.getMax(max) << std::endl; // Max degerini ekrana yazdirir.
//    std::cout << "Max value index : " << max << std::endl << std::endl; // Max degerinin index numarasini ekrana yazdirir.
//
//    int min;
//    std::cout << "Min value : " << sonar_sensor.getMin(min) << std::endl; // Min degerini ekrana yazdirir.
//    std::cout << "Min value index : " << min << std::endl << std::endl; // Min degerinin index numarasini ekrana yazdirir.
//
//    for (int i = 0; i < 2; i++) {
//        std::cout << "Range " << i + 1 << " is " << sonar_sensor.getRange(i) << std::endl; // Range degerlerini getRange fonksiyonuyla ekrana yazdirir.
//
//        std::cout << "Range[" << i + 1 << "] using operator[]: " << sonar_sensor[i] << std::endl; // Range degerlerini operator kullanarak ekrana yazdirir.
//    }
//  
//}
//    /**
//    * @brief NaoRobotAPI sinifinin getSonarRange fonksiyonunun test implementasyonu.
//    * @param left Sol sensor degeri.
//    * @param right Sag sensor degeri.
//    */
//void NaoRobotAPI::getSonarRange(double& left, double& right) {
//    // Test icin sabit degerler atanir.
//    left = 7.7;
//    right = 8.8;
//}
//
