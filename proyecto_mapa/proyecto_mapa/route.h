#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "point.h"
using namespace std;
class Route{//esto es una sola ruta
private:
	struct nodePoint{
		Point point;//clase punto es el lugar donde se hara la parada turistica
		nodePoint* next;
		nodePoint* prev;
		nodePoint(Point point): point(point), next(nullptr), prev(nullptr) {}
	};
	nodePoint* head;
	nodePoint* tail;
public:
	Route() :head(nullptr), tail(nullptr) {}
	void createRoute(Point);
	void deletePoint(Vector2f);
	void editRoute(RenderWindow&, Event&, bool&);
	void printRoute(RenderWindow&);
	void curve(RenderWindow&);
	void printName(RenderWindow&, Text&);
	bool isInNodePoint(string);
	void saveRoutesPoint(string&);
};

