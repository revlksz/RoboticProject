#include "Record.h"
using namespace std;

/**
 * @brief Bu fonksiyon, Record sinifinin temel islemlerini test eder.
 */
void record_test() {
    Record myRecord; ///< Record nesnesi
    string nameOfFile; ///< Dosya adi

    // Test case: file operations
    myRecord.setFileName("dosya.txt");

    // Dosyayi acma islemi
    if (myRecord.openFile()) {
        myRecord << "Hello, World!";
        myRecord.closeFile();
    }

    // Dosyayi tekrar okuma islemi icin acma
    myRecord.openFile();

    string content;
    myRecord >> content;

    cout << "Content read from file: " << content << endl;
}
