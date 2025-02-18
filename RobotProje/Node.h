#pragma once
#include "Pose.h"

/**
 * @class Node
 * @brief Bagli liste dugumu icin temel sinif.
 *
 * Node sinifi, bagli liste dugumunu temsil eder ve bir sonraki dugumu ve bir pozisyon (Pose) icerir.
 */
class Node
{
public:
    Node* next; ///< Bir sonraki dugumun isaretcisi.
    Pose pose; ///< Dugumun icerisinde saklanan pozisyon bilgisi.

    /**
     * @brief Varsayilan yapilandirici.
     */
    Node();

    /**
     * @brief Parametreli yapilandirici.
     * @param pose Dugumun icerisine yerlestirilecek pozisyon bilgisi.
     */
    Node(const Pose& pose);
};

// NODE_H
