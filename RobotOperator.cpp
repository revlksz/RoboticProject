/**
 * @file RobotOperator.cpp
 * @brief RobotOperator sinifi icin uygulama dosyasi.
 */
#pragma once
#include "RobotOperator.h"

/**
 * @brief RobotOperator sinifi, robot operatorlerinin bilgilerini ve erisim kontrolunu yonetir.
 */
int RobotOperator::encryptCode(int code) {
    Encryption encryption;
    return encryption.encrypt(code);
}

/**
 * @brief Sifrelenmis bir kodu cozen fonksiyon.
 * @param encryptedCode1 Cozulecek sifrelenmis kod.
 * @return Cozulen kod.
 */
int RobotOperator::decryptCode(int encryptedCode1) {
    Encryption encryption;
    return encryption.decrypt(encryptedCode1);
}

/**
 * @brief RobotOperator sinifinin constructor'i.
 * @param name Operatorun adi.
 * @param surname Operatorun soyadi.
 * @param code Erisim kodu.
 */
RobotOperator::RobotOperator(std::string name, std::string surname, int code) {
    this->name = name;
    this->surname = surname;
    this->accessCode = encryptCode(code); // Sifrelenmis kodu sakla
    this->accessState = false; // Baslangicta erisim reddedildi
}

/**
 * @brief Girilen bir kodun erisim koduyla eslesip eslesmedigini kontrol eden fonksiyon.
 * @param enteredCode Kontrol edilecek kod.
 * @return Eger eslesiyorsa true, aksi takdirde false.
 */
bool RobotOperator::checkAccessCode(int enteredCode) {
    // Girilen kodun, saklanan cozulmus erisim koduyla eslesip eslesmedigini kontrol et
    int encryptedCode2 = encryptCode(enteredCode);
    if (encryptedCode2 == accessCode) {
        accessState = true;
    }
    return encryptedCode2 == accessCode;
}

/**
 * @brief Operator bilgilerini ekrana yazdiran fonksiyon.
 */
void RobotOperator::print() {
    std::cout << "Operator Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Access Status: ";
    if (accessState) {
        std::cout << "Access Granted" << std::endl;
    }
    else {
        std::cout << "Access Denied" << std::endl;
    }
}
