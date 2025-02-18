#pragma once
#include "Node.h"
#include "Pose.h"
#include <iostream>

/**
 * @class Path
 * @brief Yol bilgisini tutan ve yoneten sinif.
 *
 * Path sinifi, bir yolun dugumlerini iceren bir bagli listeyi temsil eder ve bu yolla ilgili temel islemleri gerceklestirir.
 */
class Path
{
private:
    Node* tail; ///< Bagli listenin son dugumu.
    Node* head; ///< Bagli listenin bas dugumu.
    int number; ///< Yoldaki dugum sayisi.

public:
    /**
     * @brief default constructor.
     */
    Path();

    /**
     * @brief Yeni bir pozisyonu yola ekler.
     * @param pose Eklenen pozisyon bilgisi.
     */
    void addPose(Pose pose);

    /**
     * @brief Yolu ekrana yazdirir.
     */
    void print() const;

    /**
     * @brief Belirtilen indexteki pozisyonu getirir.
     * @param index Istenen pozisyonun indeksi.
     * @return Belirtilen pozisyon bilgisi.
     */
    Pose getPos(int index);

    /**
     * @brief Belirtilen indexte yeni bir pozisyon ekler.
     * @param index Yeni pozisyonun eklenecegi indeks.
     * @param pose Eklenecek yeni pozisyon bilgisi.
     * @return Eger ekleme basariliysa true, degilse false.
     */
    bool insertPos(int index, Pose pose);

    /**
     * @brief Belirtilen indexteki pozisyonu yoldan cikarir.
     * @param index Cikarilacak pozisyonun indeksi.
     * @return Eger cikarma basariliysa true, degilse false.
     */
    bool removePos(int index);

    /**
     * @brief Belirtilen indexteki pozisyonu referans olarak getirir.
     * @param index Istenen pozisyonun indeksi.
     * @return Belirtilen pozisyonun referansi.
     */
    Pose& operator[](int index);

    /**
     * @brief Yolu standart cikis akisina yazdirir.
     * @param os Cikis akisi.
     * @param path Yazdirilacak yol.
     * @return Cikis akisi.
     */
    friend std::ostream& operator<<(std::ostream& os, Path& path);

    /**
     * @brief Yolu standart giris akisindan okur.
     * @param is Giris akisi.
     * @param path Okunacak yol.
     * @return Giris akisi.
     */
    friend std::istream& operator>>(std::istream& is, Path& path);
    /**
     * @brief  number'ý robotcontrol sinifinda kullanabilmek icin yazdýk
     * number üye degiskenini donduruyor.
     */
    int getNumber() const;
};
// PATH_H
