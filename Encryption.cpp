/**
 * @file Encryption.cpp
 * @brief Sifreleme sinifinin uygulama dosyasi.
 */

#include "Encryption.h"
#include <iostream>
#include <iomanip>

 /**
  * @brief Sayiyi sifrelemek icin kullanilan fonksiyon.
  *
  * Sayinin her bir basamagini (rakamini) sifreler.
  *
  * @param number Sifrelenecek olan sayi.
  * @return Sifrelenmis sayi.
  */
int Encryption::encrypt(int number) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = (number % 10 + 7) % 10; // Her bir basamagi sifrele
        number /= 10;
    }

    int encryptedNumber = digits[2] * 1000 + digits[3] * 100 + digits[0] * 10 + digits[1];
    return encryptedNumber;
}

/**
 * @brief Sifrelenmis sayiyi cozmek icin kullanilan fonksiyon.
 *
 * Sifrelenmis sayinin her bir basamagini coz.
 *
 * @param encryptedNumber Cozulecek olan sifrelenmis sayi.
 * @return Orijinal sayi.
 */
int Encryption::decrypt(int encryptedNumber) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = (encryptedNumber % 10 + 3) % 10; // Her bir basamagi coz
        encryptedNumber /= 10;
    }
    int originalNumber = digits[2] * 1000 + digits[3] * 100 + digits[0] * 10 + digits[1];
    return originalNumber;
}
