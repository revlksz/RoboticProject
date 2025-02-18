#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <iomanip>

/**
 * @class Encryption
 * @brief Sayi sifreleme ve sifre cozme islemlerini gerceklestiren sinif.
 *
 * Encryption sinifi, bir sayiyi sifreleme ve sifreyi cozme islemlerini gerceklestiren basit bir siniftir.
 */
class Encryption {
public:
    /**
     * @brief Sayiyi sifreler.
     * @param number Sifrelenecek sayi.
     * @return Sifrelenmis sayi.
     */
    int encrypt(int number);

    /**
     * @brief Sifrelenmis sayiyi coz.
     * @param encryptedNumber Sifrelenmis sayi.
     * @return Cozulmus sayi.
     */
    int decrypt(int encryptedNumber);
};

#endif // ENCRYPTION_H
