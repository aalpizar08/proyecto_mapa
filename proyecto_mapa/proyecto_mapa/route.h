#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "point.h"
using namespace std;
class Route{
private:
	struct nodePoint{
		Point point;
		nodePoint* next;
		nodePoint* prev;
		nodePoint(Point point): point(point), next(nullptr), prev(nullptr) {}
	};
	nodePoint* head;
	nodePoint* tail;
public:
	Route() :head(nullptr), tail(nullptr) {}
	void createRoute(Point);
	void printRoute(RenderWindow&);
	void curve(RenderWindow&);
};
