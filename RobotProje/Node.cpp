/**
 * @file Node.cpp
 * @brief Bu dosya, bir bagli listedeki dugumu temsil eden Node sinifinin implementasyonudur.
 */


#include "Node.h"

Node::Node() :next(nullptr), pose() {}


Node::Node(const Pose& p1) {
	next = nullptr;
	this->pose = p1;
}

// NODE.cpp
