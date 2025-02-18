#ifndef ROBOT_OPERATOR_H
#define ROBOT_OPERATOR_H

#include <iostream>
#include "Encryption.h"

/**
 * @class RobotOperator
 * @brief Robot operatorunu temsil eden sinif.
 *
 * RobotOperator sinifi, robot operatorunun ozelliklerini ve islevlerini saglar.
 */
class RobotOperator {
private:
    int accessCode; ///< Sifrelenmis erisim kodu.
    std::string name; ///< Isim.
    std::string surname; ///< Soyisim.
    bool accessState; ///< Erisim durumu.

    /**
     * @brief Kodu sifreleme islemi.
     * @param code Sifrelenecek kod.
     * @return Sifrelenmis kod.
     */
    int encryptCode(int code);

    /**
     * @brief Sifrelenmis kodu cozme islemi.
     * @param encryptedCode Cozulecek sifrelenmis kod.
     * @return Cozulmus kod.
     */
    int decryptCode(int encryptedCode);

public:
    /**
     * @brief Parametreli constructor.
     * @param name Isim.
     * @param surname Soyisim.
     * @param code Erisim kodu.
     */
    RobotOperator(std::string name, std::string surname, int code);

    /**
     * @brief Girilen erisim kodunu kontrol eder.
     * @param enteredCode Kontrol edilecek erisim kodu.
     * @return Eger erisim kodu dogruysa true, degilse false.
     */
    bool checkAccessCode(int enteredCode);

    /**
     * @brief Operator bilgilerini ekrana yazdirma islemi.
     */
    void print();
};

#endif // ROBOT_OPERATOR_H
