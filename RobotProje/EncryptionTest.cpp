/**
 * @file EncryptionTest.cpp
 * @brief Sifreleme test fonksiyonunun uygulama dosyasi.
 */

#include"Encryption.h"
#include<iomanip>
using namespace std;

/**
 * @brief Sifreleme sinifini test etmek icin kullanilan fonksiyon.
 *
 * Bu fonksiyon, sifrelenmis ve cozulmus bir sayi uzerinde bir test yapar.
 */
void encryption_test() {
    Encryption en;

    // Test case: Encrypting and decrypting a number
    int originalNumber = 4356;
    int encrypted = en.encrypt(originalNumber);
    int decrypted = en.decrypt(encrypted);

    cout << "Original Number: " << originalNumber << endl;
    cout << "Encrypted Number: ";

    if (encrypted < 1000) {
        std::cout << std::setw(4) << std::setfill('0') << encrypted << std::endl;
    }
    else {
        cout << "Encrypted Number: " << encrypted << endl;
    }

    cout << "Decrypted Number: " << decrypted << endl;

    if (originalNumber == decrypted) {
        cout << "Encryption and decryption successful!" << endl;
    }
    else {
        cout << "Encryption and decryption failed!" << endl;
    }
}