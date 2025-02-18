/**
* Beyza Nur Akyýldýrým 29.12.2023 _ birinci asama
*
* Beyza Nur Akyýldýrým 08.01.2024 _ ikinci asama
*
 * @file RobotControl.cpp
 * @brief RobotControl sinifi icin uygulama dosyasi.
 */
#include "Pose.h"
#include "RobotControl.h"
#include "Record.h"
#include "RobotOperator.h"
#include "NaoRobotAPI.h"
#include "SensorInterface.h"
#include "RobotInterface.h"
#include <iostream>
#include <vector>

using namespace std;

RobotControl::RobotControl() : accessGranted(true), NaoRobotInterface(nullptr) {}

RobotControl::~RobotControl() {
    delete NaoRobotInterface;
}
/**
 * @brief Robotu sola donmeye yetkilendirir.
 */
void RobotControl::turnLeft() {
    if (accessGranted)
    {
        NaoRobotInterface->turnLeft();
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Robotu saga donmeye yetkilendirir.
 */
void RobotControl::turnRight() {
    if (accessGranted)
    {
        NaoRobotInterface->turnRight();
    }
    else {
        cout << "Access is denied" << endl;
    }

}

/**
 * @brief Robotu surekli olarak ileri hareket etmeye yetkilendirir.
 */
void RobotControl::forward() {
    if (accessGranted)
    {
        NaoRobotInterface->forward();
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Robotu surekli olarak geri hareket etmeye yetkilendirir.
 */
void RobotControl::backward() {
    if (accessGranted)
    {
        NaoRobotInterface->backward();
    }
    else {
        cout << "Access is denied" << endl;
    }
}
//
///**
// * @brief Robotun pozisyonunu dondurur.
// * @return Robotun pozisyonunu temsil eden Pose nesnesi.
// */
//Pose RobotControl::getPose() {
//
//    return robotInterface->getPose();
//
//
//}

/**
 * @brief Robotu durdurmaya yetkilendirir.
 */
void RobotControl::stop() {
    if (accessGranted)
    {
        NaoRobotInterface->stop();
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Robota sola yan adim atmaya yetkilendirir.
 */
void RobotControl::moveLeft() {
    if (accessGranted)
    {
        NaoRobotInterface->moveLeft();
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Robota saga yan adim atmaya yetkilendirir.
 */
void RobotControl::moveRight() {
    if (accessGranted)
    {
        NaoRobotInterface->moveRight();
    }
    else {
        cout << "Access is denied" << endl;
    }
}


NaoRobotAPI* RobotControl::get_robot()
{

    return robotAPI;

}
/**
 * @brief Robotun mevcut hareket durumunu ve pozisyonunu yazdirir.
 */
void RobotControl::print() {
    if (accessGranted)
    {
        Pose currentPose = getPose();
        cout << "Robot Movement Status and Pose:\n";
        cout << "Position: X=" << currentPose.getX() << ", Y=" << currentPose.getY()
            << ", Orientation=" << currentPose.getTh() << " degrees\n";
    }
    else {
        cout << "Access is denied" << endl;
    }

}
/**
 * @brief robotun bulundugu konumu path e eklenmektedir..
 */
bool RobotControl::addToPath() {
    if (accessGranted)
    {
        Pose currentPose = getPose();
        Path newPath;
        newPath.addPose(currentPose);
        return true;
    }
    else {
        cout << "Access is denied" << endl;
    }
}
/**
 * @brief Yolu temizlemeye yetkilendirir.
 * Path nesnesini boþ bir nesneyle deðiþtirerek temizle
 */
void RobotControl::clearPath() {
    if (accessGranted)
    {
        path = Path();
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Path nesnesindeki konumlarý dosyaya kaydeder.
 * @return Kaydetme iþlemi baþarýlýysa true, aksi halde false.
 */

bool RobotControl::recordPath() {
    if (accessGranted)
    {
        const string fileName = "path.txt";

        Record record;
        record.setFileName(fileName);

        if (!record.openFile())
        {
            cerr << "Dosya acma hatasi: " << fileName << endl;
            return false;
        }

        for (int i = 0; i < path.getNumber(); ++i)
        {
            Pose currentPose = path.getPos(i);

            string poseString =
                to_string(currentPose.getX()) + " " +
                to_string(currentPose.getY()) + " " +
                to_string(currentPose.getTh());

            record << poseString;
        }

        record.closeFile();

        return true;
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
  * @brief erisim icin kullanýlan bir fonksiyondur.
  * dogru sýfre giriþ yapilmadiginde hicbir fonksiyon islem yapmayacaktir
  */

bool RobotControl::openAccess(int password) {
    RobotOperator operator1("OperatorName", "OperatorSurname", password); // Varsayýlan 
    int enteredCode;
    cout << "Enter access code: ";
    cin >> enteredCode;

    if (operator1.checkAccessCode(enteredCode)) {
        accessGranted = true;
        cout << "Access granted!\n";
    }
    else {
        accessGranted = false;
        cout << "Access denied!\n";
    }

    return accessGranted;
}

/**
  * @brief doðru þifre verildiðinde, eriþim tekrar kapatýlacaktýr.
  * Tekrar açýlana kadar fonksiyonlar iþlemlerini yapmayacaktýr.
  */

bool RobotControl::closeAccess(int password) {
    RobotOperator operator1("OperatorName", "OperatorSurname", password);
    int enteredCode;
    cout << "Enter access code to close access: ";
    cin >> enteredCode;

    if (operator1.checkAccessCode(enteredCode)) {
        accessGranted = false;
        cout << "Access closed!\n";
    }
    else {
        cout << "Access closure failed. Incorrect access code.\n";
    }

    return !accessGranted; // Eger accessGranted false ise, fonksiyon true dönecek.
}

/**
 * @brief Belirtilen sensor tipine ait veriyi dosyaya kaydeder.
 * islem dogru olursa true, degilse false doner.
 */
bool RobotControl::recordSensor(std::string type) {
    if (accessGranted)
    {

        for (auto sensor : sensorList)
        {
            if (sensor->getSensorType() == type)
            {

                Record record;
                record.setFileName("sensor_data.txt");
                if (!record.openFile())
                {
                    cerr << "Dosya acma hatasi: sensor_data.txt" << endl;
                    return false;
                }

                record << "Sensor Type: " << sensor->getSensorType() << "\n";
                record << "Sensor Value: " << sensor->getSensorValue() << "\n";
                record << "------------------------\n";

                record.closeFile();
                return true;
            }
        }

        cout << "Sensor of type '" << type << "' not found.\n";
        return false;
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Belirtilen sensor tipine sahip sensoru bulur
 * ve degerini ekrana yazdýrýr.
 */
void RobotControl::printSensor(string type) {
    if (accessGranted)
    {

        for (auto sensor : sensorList)
        {
            if (sensor->getSensorType() == type)
            {

                cout << "Sensor Type: " << sensor->getSensorType() << "\n";
                cout << "Sensor Value: " << sensor->getSensorValue() << "\n";
                return;
            }
        }
        cout << "Sensor of type '" << type << "' not found.\n";
    }
    else {
        cout << "Access is denied" << endl;
    }
}

/**
 * @brief Sensör ekler.
 *
 * Bu fonksiyon, verilen SensorInterface türünden sensörü
 * sensorList listesine ekler.
 * Eklenen sensörün tipini ekrana yazdýrýr.
 *
 * @param sensor Eklenecek sensörün pointer'ý.
 */
void RobotControl::addSensor(SensorInterface* sensor) {
    if (accessGranted)
    {
        sensorList.push_back(sensor);
        cout << "Sensor added: " << sensor->getSensorType() << "\n";
    }
    else {
        cout << "Access is denied" << endl;
    }
}