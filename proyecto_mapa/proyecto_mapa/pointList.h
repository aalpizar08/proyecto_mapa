#pragma once
#include <iostream>
#include <string>
#include "point.h"
#include <fstream>
using namespace std;
class pointList {
public:
	struct nodePoint {
		Point point;
		nodePoint* next;
		nodePoint* prev;

		nodePoint(Point point) : point(point), next(nullptr), prev(nullptr) {}
	};
	nodePoint* head;
	nodePoint* tail;

public:
	pointList() : head(nullptr), tail(nullptr) {}
	void insertPoint(Point);
	void print() const;
};