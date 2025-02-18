/**
* Yusuf Böçkün 
* 25.12.2023
 * @file Path.cpp
 *
 * @brief Path sinifinin uygulama dosyasi.
 */

#include "Path.h"
#include <stdexcept>

 /**
  * @brief Path sinifinin default constructor fonksiyonu.
  */
Path::Path() : tail(nullptr), head(nullptr), number(0) {}

/**
 * @brief Path'e bir poz ekler.
 *
 * @param add_pose Eklenecek poz.
 */
void Path::addPose(Pose add_pose) {
    if (head == nullptr) {
        tail = head = new Node(add_pose);
    }
    else {
        tail->next = new Node(add_pose);
        tail = tail->next;
    }
    number++;
}

/**
 * @brief Path'teki pozlari yazdirir.
 */
void Path::print() const {
    Node* p = head;
    int i = 0;
    std::cout << "Your Path:\n" << "-------------" << std::endl;
    while (p != nullptr) {
        i++;
        std::cout << i << ". poz : x=" << p->pose.getX() << " y=" << p->pose.getY() << " th=" << p->pose.getTh() << std::endl;
        p = p->next;
    }
}

/**
 * @brief Path'teki belirli bir indexteki pozu alir.
 *
 * @param index Alinacak pozu belirten indeks.
 * @return Belirtilen indeksteki poz.
 * @throws std::runtime_error indeks sinirlarin disindaysa.
 */
Pose Path::getPos(int index) {
    if (head == nullptr || index > number || index < 0) throw std::runtime_error("Hata");
    Node* p = head;
    for (int i = 0; i < index; i++) {
        if (p->next != nullptr) {
            p = p->next;
        }
    }
    return p->pose;
}

/**
 * @brief Path'teki belirli bir indexteki pozunu kaldirir.
 *
 * @param index Kaldirilacak pozu belirten indeks.
 * @return Kaldirma basariliysa true, aksi halde false.
 */
bool Path::removePos(int index) {
    if (head == NULL || index < 0 || index > number) return false;
    else {
        Node* p = head;
        if (index == 0) {
            p = p->next;
            delete head;
            head = p;
        }
        else if (index == number) {
            while (p->next != tail) {
                p = p->next;
            }
            delete tail;
            tail = p;
        }
        else {
            int flag = 0;
            while (flag != index - 1) {
                p = p->next;
                flag++;
            }
            Node* temp;
            temp = p->next->next;
            delete p->next;
            p->next = temp;
        }
        number--;
        return true;
    }
}

/**
 * @brief Path'e belirli bir indexte poz ekler.
 *
 * @param index Pozun eklenecegi indeks.
 * @param p1 Eklenecek poz.
 * @return Ekleme basariliysa true, aksi halde false.
 */
bool Path::insertPos(int index, Pose p1) {
    if (index<0 || index > number + 1) return false;
    else {
        if (head == NULL) {
            addPose(p1);
        }
        else {
            if (index == 0) {
                Node* newItem = new Node(p1);
                newItem->next = head;
                head = newItem;
            }
            else if (index > number) {

                tail->next = new Node(p1);
                tail = tail->next;
            }
            else {
                Node* p = head;
                for (int i = 0; i < index - 1; i++) {
                    p = p->next;
                }
                Node* newItem = new Node(p1);
                Node* nextTemp = p->next;
                p->next = newItem;
                newItem->next = nextTemp;
            }
            return true;
        }
        number++;
    }
}

/**
 * @brief Indeksleme operatörünü aþiri yukleyerek pozlara erisim saglar.
 *
 * @param index Alinacak pozun indeksi.
 * @return Belirtilen indeksteki pozun referansi.
 * @throws std::out_of_range indeks sinirlarin disindaysa.
 */
Pose& Path::operator[](int index) {
    Node* p;
    if (head == nullptr) throw std::out_of_range("Indeks disinda");
    p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    return p->pose;
}

/**
 * @brief Cikis akisi operatorunu aþiri yukleyerek patiyi yazdirir.
 *
 * @param out Cikis akisi.
 * @param p1 Yazdirilacak Path nesnesi.
 * @return Cikis akisi.
 */
std::ostream& operator<<(std::ostream& out, Path& p1) {
    p1.print();
    return out;
}

/**
 * @brief Giris akisi operatorunu aþiri yukleyerek patiye yeni bir poz ekler.
 *
 * @param in Giris akisi.
 * @param p1 Pozun eklenecegi Path nesnesi.
 * @return Giris akisi.
 */
std::istream& operator>>(std::istream& in, Path& p1) {
    Pose p;
    std::cout << "Yeni poz girin (x, y, th): ";
    double temp;
    in >> temp;
    p.setX(temp);
    in >> temp;
    p.setY(temp);
    in >> temp;
    p.setTh(temp);
    p1.addPose(p);
    return in;
}

/**
 * @brief Path sýnýfýndaki toplam poz sayýsýný döndürür.
 * return Path sýnýfýndaki toplam poz sayýsý.
 */
int Path::getNumber() const {
    return number;
}
