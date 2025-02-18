/**
 * @file Record.cpp
 * @brief Record sinifi icin uygulama dosyasi.
 */

#include "Record.h"
#include <fstream>
#include <string>

 /**
  * @brief Belirtilen dosya adini giris, cikis ve ekleme modunda acar.
  * @return Dosya basariyla acilirsa true, aksi takdirde false doner.
  */
bool Record::openFile() {
    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);

    if (file.is_open()) {
        return true;
    }
    else {
        std::cerr << "Dosya acma hatasi: " << fileName << std::endl;
        return false;
    }
}

/**
 * @brief Su anda acik olan dosyayi kapatir.
 * @return Dosya basariyla kapatilirsa true, aksi takdirde false doner.
 */
bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Record nesnesinin dosya adini ayarlar.
 * @param name Dosya adi.
 */
void Record::setFileName(std::string name) {
    fileName = name;
}

/**
 * @brief Su anda acik olan dosyadan bir satir okur.
 * @return Okunan satiri bir dize olarak dondurur.
 */
std::string Record::readLine() {
    std::string line;
    std::getline(file, line);
    return line;
}

/**
 * @brief Su anda acik olan dosyaya bir satir ve ardindan bir yeni satir karakteri yazar.
 * @param line Dosyaya yazilacak satir.
 */
void Record::writeLine(std::string line) {
    file << line << std::endl;
}

/**
 * @brief Asiri yuklenmis << operatoru, bir dizini su anda acik olan dosyaya yazmak icin kullanilir.
 * @param data Dosyaya yazilacak dize.
 * @return Zincirleme icin Record nesnesine referans.
 */
Record& Record::operator<<(std::string data) {
    writeLine(data);
    return *this;
}

/**
 * @brief Asiri yuklenmis >> operatoru, su anda acik olan dosyadan bir dizeyi okumak icin kullanilir.
 * @param data Okunan verinin depolanacagi dizeye referans.
 * @return Zincirleme icin Record nesnesine referans.
 */
Record& Record::operator>>(std::string& data) {
    data = readLine();
    return *this;
}
