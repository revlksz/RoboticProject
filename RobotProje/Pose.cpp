/**
 * @file Pose.cpp
 * @brief Pose sinifi icin uygulama dosyasi.
 */

#include "Pose.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

/**
 * @brief Pose sinifi, bir konumu (x, y, th) temsil eder.
 */
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

/**
 * @brief default constructor.
 */
Pose::Pose() : x(0), y(0), th(0) {}


/**
 * @brief X koordinatini getirir.
 * @return X koordinati.
 */
double Pose::getX() {
    return x;
}

/**
 * @brief X koordinatini ayarlar.
 * @param value Ayarlanacak X koordinat degeri.
 */
void Pose::setX(double value) {
    this->x = value;
}


/**
 * @brief Y koordinatini getirir.
 * @return Y koordinati.
 */
double Pose::getY() {
    return y;
}

/**
 * @brief Y koordinatini ayarlar.
 * @param value Ayarlanacak Y koordinat degeri.
 */
void Pose::setY(double value) {
    this->y = value;
}


/**
 * @brief Theta acisini getirir.
 * @return Theta acisi.
 */
double Pose::getTh() {
    return th;
}

/**
 * @brief Theta acisini ayarlar.
 * @param x Ayarlanacak Theta acisi.
 */
void Pose::setTh(double value) {
    this->th = value;
}


/**
 * @brief Pose'un icindeki x, y ve th degerlerini getirir.
 * @param x X koordinati.
 * @param y Y koordinati.
 * @param th Theta acisi.
 */
void Pose::getPose(double& x, double& y, double& th) {
    x = this->x;
    y = this->y;
    th = this->th;
}

/**
 * @brief Pose'un icindeki x, y ve th degerlerini ayarlar.
 * @param x Ayarlanacak X koordinati.
 * @param y Ayarlanacak Y koordinati.
 * @param th Ayarlanacak Theta acisi.
 */
void Pose::setPose(double x, double y, double th) {
    this->x = x;
    this->y = y;
    this->th = th;
}

/**
 * @brief Belirtilen Pose'a olan uzakligi bulur.
 * @param p2 Hesaplanacak diger Pose.
 * @return Uzaklik degeri.
 */
double Pose::findDistanceTo(Pose p2) {
    return sqrt(pow(this->x - p2.x, 2) + pow(this->y - p2.y, 2));
}

/**
 * @brief Belirtilen Pose'a olan aciyi bulur.
 * @param p2 Hesaplanacak diger Pose.
 * @return Aci degeri.
 */
double Pose::findAngleTo(Pose p2) {
    double deltaX = this->x - p2.x;
    double deltaY = this->y - p2.y;

    // atan2 kullanarak aciyi hesapla ve dereceye cevir
    double angle = atan2(deltaY, deltaX) * 180.0 / M_PI;

    // Eger aci negatifse, 360 derece ekleyerek pozitif bir aci elde et
    if (angle < 0) {
        angle += 360.0;
    }

    return angle;
}


// Operator islemleri
/**
 * @brief Iki Pose'u toplar.
 * @param p2 Toplanacak diger Pose.
 * @return Toplanmis Pose.
 */
Pose Pose::operator+(const Pose& p2) {
    Pose temp;
    temp.x = this->x + p2.x;  // x koordinatlarini topla
    temp.y = this->y + p2.y;  // y koordinatlarini topla
    temp.th = this->th + p2.th;  // theta (aci) degerlerini topla
    return temp;
}

/**
 * @brief Iki Pose'u cikarir.
 * @param p2 Cikarilacak diger Pose.
 * @return Cikarilmis Pose.
 */
Pose Pose::operator-(const Pose& p2) {
    Pose temp;
    temp.x = this->x - p2.x;  // x koordinatlarini cikar
    temp.y = this->y - p2.y;  // y koordinatlarini cikar
    temp.th = this->th - p2.th;  // theta (aci) degerlerini cikar
    return temp;
}

/**
 * @brief Iki Pose'un esit olup olmadigini kontrol eden operator asiri yukleme metodu
 * @param p2 Karsilastirilacak diger Pose.
 * @return Eger esitse true, degilse false.
 */
bool Pose::operator==(const Pose& p2) const {
    return (x == p2.x && y == p2.y && th == p2.th);  // x, y ve th degerlerini kontrol et
}

/**
 * @brief Iki Pose nesnesinin kucuk olup olmadigini kontrol eden operator asiri yukleme metodu
 * @param p2 Karsilastirilacak diger Pose.
 * @return Eger kucukse true, degilse false.
 */
bool Pose::operator<(const Pose& p2) {
    return (x < p2.x && y < p2.y && th < p2.th);  // x, y ve th degerlerini kontrol et
}

/**
 * @brief Iki Pose nesnesini ekleyip kendi uzerine atan operator asiri yukleme metodu
 * @param p1 Toplanacak diger Pose.
 * @return Guncellenmis Pose.
 */
Pose& Pose::operator+=(const Pose& p1) {
    x += p1.x;  // x koordinatlarini ekleyip kendi uzerine ata
    y += p1.y;  // y koordinatlarini ekleyip kendi uzerine ata
    th += p1.th;  // theta (aci) degerlerini ekleyip kendi uzerine ata
    return *this;
}
Pose& Pose::operator-=(const Pose& p1) {
    x -= p1.x;  // x koordinatlarini azaltip kendi uzerine ata
    y -= p1.x;  // y koordinatlarini azaltip kendi uzerine ata
    th -= p1.th;    // theta (aci) degerlerini azaltip kendi uzerine ata
    return *this;
}

/**
 * @brief Iki Pose nesnesini cikartip kendi uzerine atan operator asiri yukleme metodu
 * @param p1 Cikarilacak diðer Pose.
 * @return Güncellenmi
 */
