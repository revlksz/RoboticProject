#pragma once
#include <iostream>
#include <fstream>
#include <string>

/**
 * @class Record
 * @brief Dosya islemleri icin sinif.
 *
 * Record sinifi, dosya islemleri yapmak icin gerekli temel islevleri saglar.
 */
class Record {
private:
    std::string fileName; ///< Dosya adi.
    std::fstream file; ///< Dosya akisi.

public:
    /**
     * @brief constructor.
     */
    Record() {}

    /**
     * @brief destructor.
     */
    ~Record() {
        closeFile();
    }

    /**
     * @brief Dosyayi okuma ve yazma icin acar.
     * @return Acma islemi basariliysa true, degilse false.
     */
    bool openFile();

    /**
     * @brief Dosyayi kapatir.
     * @return Kapatma islemi basariliysa true, degilse false.
     */
    bool closeFile();

    /**
     * @brief Dosya adini ayarlar.
     * @param name Ayarlanacak dosya adi.
     */
    void setFileName(std::string name);

    /**
     * @brief Dosyadan bir satir okur.
     * @return Okunan satir.
     */
    std::string readLine();

    /**
     * @brief Dosyaya bir satir yazar.
     * @param line Yazilacak satir.
     */
    void writeLine(std::string line);

    /**
     * @brief << operatorunu asiri yukler, dosyaya yazma islemi yapar.
     * @param data Yazilacak veri.
     * @return Record nesnesi.
     */
    Record& operator<<(std::string data);

    /**
     * @brief >> operatorunu asiri yukler, dosyadan okuma islemi yapar.
     * @param data Okunan veri.
     * @return Record nesnesi.
     */
    Record& operator>>(std::string& data);
};
// RECORD_H
