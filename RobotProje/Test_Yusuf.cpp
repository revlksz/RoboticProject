//#include "Pose.h"
//#include "Path.h"
//#include <iostream>
//#include <cmath>
//
///**
// * @brief Programin baslangic noktasi.
// *
// * Bu fonksiyon, Pose ve Path siniflarini test etmek icin kullanilir.
// * Pose sinifinin cesitli fonksiyonlari ve operator asiri yuklemeleri, Path sinifinin temel
// * fonksiyonlari bu fonksiyon icinde test edilmistir.
// *
// * @return Programin basariyla sona erdigi belirten bir deger.
// */
//int main() {
//
//    // TEST 1 - Pose.cpp
//#if 0
//    Pose p1; // default constructor
//    Pose p2(4, 8, 0); // overloaded constructor
//
//    std::cout << "TEST1\n------" << std::endl;
//
//    // TEST1 SET and GET function
//    p1.setX(8);
//    p1.setY(8);
//    p1.setTh(0);
//    std::cout << "p1.x=" << p1.getX() << "\np1.y= " << p1.getY() << "\np1.th= " << p1.getTh() << std::endl;
//
//    std::cout << "\nTEST2\n------" << std::endl;
//
//    // TEST2 operator 
//    p1 += p2;
//    std::cout << "p1+=p2 is x= " << p1.getX() << "\np1+=p2 is y= " << p1.getY() << "\np1+=p2 is th= " << p1.getTh() << std::endl;
//    if (p1 == p2)
//        std::cout << "p1 p2 is equal" << std::endl;
//    else
//        std::cout << "p1 p2 is not equal" << std::endl;
//
//    if (p1 < p2)
//        std::cout << "p2 is greater than p1" << std::endl;
//    else
//        std::cout << "p1 is greater than p2" << std::endl;
//
//    p1.setX(4);
//    p1.setY(4);
//    p1.setTh(0);
//
//    std::cout << "\n\nTEST3\n------" << std::endl;
//    // TEST3 FIND_DISTANCE AND ANGLE
//    std::cout << "Distance  p1 to p2: " << p1.findDistanceTo(p2) << std::endl;
//    std::cout << "findAngleTO:   " << p1.findAngleTo(p2);
//
//#endif // 0
//
//    // TEST2 - PATH.cpp
//#if 0
//    Pose p1; // default constructor
//    Pose p2(3, 4, 0); // overloaded constructor
//    Pose p3(3, 5, 10);
//    Pose p4(11, 13, 17);
//
//    Path my_path; // create path
//
//    // addPose function
//    my_path.addPose(p1);
//    my_path.addPose(p2);
//    my_path.addPose(p3);
//
//    my_path.getPos(1);
//    my_path.insertPos(2, p4); // insert function
//
//    Pose p5 = my_path[0]; // index operator
//
//    my_path.print(); // print function
//
//    // getPos
//    double x, y, th;
//    my_path.getPos(2).getPose(x, y, th);
//    Pose newPose(x, y, th); // pathteki 2. indexte ki posun degerlerini aldi
//
//    std::cin >> my_path; // cin pose operator
//
//    my_path.removePos(0); // remove function
//
//    std::cout << my_path; // cout operator
//#endif
//    return 0;
//}
