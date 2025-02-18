#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

// Beyza Nur Akyýldýrým 
// 08.01.2024 
// ikinci asama
#include <iostream>
#include "Pose.h"
#include "Path.h"
#include "Record.h"
#include "RobotOperator.h"
#include "NaoRobotAPI.h"
#include "SensorInterface.h"
#include "RobotInterface.h"
#include "NaoRobotInterface.h"
#include <list>
/**
 * @class RobotControl
 * @brief Robotun hareketini kontrol eden sinif.
 *
 * RobotControl sinifi, robotun hareketini kontrol eden temel islevleri saglar.
 */
class RobotControl :virtual public RobotInterface {
private:
    Path path;
    bool accessGranted;
    list<SensorInterface*> sensorList;
    Pose* position = new Pose();
    RobotInterface* robotInterface;
    NaoRobotInterface* naoRobotInterface;

public:
    RobotControl();
    ~RobotControl();


    /**
     * @brief Sola donme islemi.
     */
    void turnLeft() override;

    /**
     * @brief Saga donme islemi.
     */
    void turnRight() override;

    /**
     * @brief Ileri gitme islemi.
     */
    void forward()override;

    /**
     * @brief Geri gitme islemi.
     */
    void backward()override;

    /**
     * @brief Robotun mevcut konumunu getirir.
     * @return Robotun mevcut konumu.
     */
    Pose getPose();

    /**
     * @brief Robotu durdurma islemi.
     */
    void stop()override;

    /**
     * @brief Sola hareket etme islemi.
     */
    void moveLeft()override;

    /**
     * @brief Saga hareket etme islemi.
     */
    void moveRight()override;

    /**
     * @brief Robotun durumunu ekrana yazdirma islemi.
     */
    void print()override;

    /**
    * @brief Robotun bulundugu konum path e eklenecek.
    */
    bool addToPath();

    /**
    * @brief Path temizlenmektedir.eklenen tüm konumlar silinmektedir.
    */
    void clearPath();

    /**
   * @brief Path nesnesinde yüklenmiþ olan konumlar dosyaya yazdýrýlmaktadýr..
   */

    bool recordPath();

    /**
  * @brief erisim icin kullanýlan bir fonksiyondur.
  * dogru sýfre giriþ yapilmadiginde hicbir fonksiyon islem yapmayacaktir
  */
    bool  openAccess(int);

    /**
  * @brief doðru þifre verildiðinde, eriþim tekrar kapatýlacaktýr.
  * Tekrar açýlana kadar fonksiyonlar iþlemlerini yapmayacaktýr.
  */
    bool closeAccess(int);

    /**
  * @brief type ile verilen sensoru sensorList de bulup
  * getSensorValue()'yu çagýrarak veriyi dosyaya kaydedecektir.
  */

    bool recordSensor(string type);

    /**
    * @brief type ile verilen sensoru sensorList de bulup
    *  getSensorValue()'yu çagýrarak veriyi ekranda dokecektir.
    */
    void printSensor(string type);

    /**
   * @brief Sensör ekler.
   */
    void addSensor(SensorInterface* sensor);

    /**
    * @brief Robot nesnesine eriþim iþlemi
    */
    NaoRobotAPI* get_robot();

};

#endif // ROBOT_CONTROL_H