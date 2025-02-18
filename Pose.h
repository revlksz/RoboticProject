#ifndef Pose_H
#define Pose_H
/**
 * @class Pose
 * @brief 2D konum ve yonlendirme bilgisini temsil eden sinif.
 *
 * Pose sinifi, bir konum ve yonlendirme bilgisini icerir ve bu bilgiler uzerinde cesitli matematiksel islemleri gerceklestirebilir.
 */
class Pose
{
private:
    double x; ///< X koordinati.
    double y; ///< Y koordinati.
    double th; ///< Yonlendirme acisi (radyan cinsinden).

public:
    /**
     * @brief Parametreli constructor.
     * @param x X koordinati.
     * @param y Y koordinati.
     * @param th Yonlendirme acisi (radyan cinsinden).
     */
    Pose(double x, double y, double th);

    /**
     * @brief Varsayilan yapilandirici.
     */
    Pose();

    /**
     * @brief X koordinatini getirir.
     * @return X koordinati.
     */
    double getX();

    /**
     * @brief X koordinatini ayarlar.
     * @param x Yeni X koordinati.
     */
    void setX(double x);

    /**
     * @brief Y koordinatini getirir.
     * @return Y koordinati.
     */
    double getY();

    /**
     * @brief Y koordinatini ayarlar.
     * @param y Yeni Y koordinati.
     */
    void setY(double y);

    /**
     * @brief Yonlendirme acisini getirir.
     * @return Yonlendirme acisi (radyan cinsinden).
     */
    double getTh();

    /**
     * @brief Yonlendirme acisini ayarlar.
     * @param th Yeni yonlendirme acisi (radyan cinsinden).
     */
    void setTh(double th);

    /**
     * @brief Konumu ve yonlendirmeyi bir dizi olarak getirir.
     * @param[out] x X koordinati.
     * @param[out] y Y koordinati.
     * @param[out] th Yonlendirme acisi (radyan cinsinden).
     */
    void getPose(double& x, double& y, double& th);

    /**
     * @brief Konumu ve yonlendirmeyi belirtilen degerlerle ayarlar.
     * @param x Yeni X koordinati.
     * @param y Yeni Y koordinati.
     * @param th Yeni yonlendirme acisi (radyan cinsinden).
     */
    void setPose(double x, double y, double th);

    /**
     * @brief Belirtilen konuma olan uzakligi hesaplar.
     * @param other Hesaplanacak diger konum.
     * @return Belirtilen konuma olan uzaklik.
     */
    double findDistanceTo(Pose other);

    /**
     * @brief Belirtilen konuma olan aciyi hesaplar.
     * @param other Hesaplanacak diger konum.
     * @return Belirtilen konuma olan aci.
     */
    double findAngleTo(Pose other);

    /**
     * @brief Iki konumu toplar.
     * @param other Toplanacak diger konum.
     * @return Iki konumun toplami.
     */
    Pose operator+(const Pose& other);

    /**
     * @brief Iki konumu cikarir.
     * @param other Cikarilacak diger konum.
     * @return Iki konumun farki.
     */
    Pose operator-(const Pose& other);

    /**
     * @brief Iki konumun esit olup olmadigini kontrol eder.
     * @param other Karsilastirilacak diger konum.
     * @return Eger konumlar esitse true, degilse false.
     */
    bool operator==(const Pose& other) const;

    /**
     * @brief Iki konumun kucukluk iliskisini kontrol eder.
     * @param other Karsilastirilacak diger konum.
     * @return Eger bu konum kucukse true, degilse false.
     */
    bool operator<(const Pose& other);

    /**
     * @brief Iki konumu toplar ve kendisine atar.
     * @param other Toplanacak diger konum.
     * @return Iki konumun toplami.
     */
    Pose& operator+=(const Pose& other);

    /**
     * @brief Iki konumu cikarir ve kendisine atar.
     * @param other Cikarilacak diger konum.
     * @return Iki konumun farki.
     */
    Pose& operator-=(const Pose& other);
};

#endif // POSE_H
