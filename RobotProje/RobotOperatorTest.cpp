#include"RobotOperator.h"

/**
 * @brief Robot operatoru test fonksiyonu.
 *
 * Fonksiyon, bir robot operatoru olusturur ve kullanicidan bir erisim kodu girmesini ister.
 * Girilen erisim kodunu kontrol eder ve sonuca gore ekrana bilgileri ve erisim durumunu yazdirir.
 */
void robot_operator_test() {
    RobotOperator robot("John", "Doe", 1234); // Operator olusturuldu

    // Access code checking
    int enteredCode;
    std::cout << "Enter access code: ";
    std::cin >> enteredCode;

    if (robot.checkAccessCode(enteredCode)) {
        robot.print();
        std::cout << "Access granted!" << std::endl;
    }
    else {
        std::cout << "Access denied!" << std::endl;
    }
}
