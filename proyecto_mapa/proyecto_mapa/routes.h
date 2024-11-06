#pragma once
#include <iostream>
#include "string"
#include "pointList.h"

class routes{
private:
	struct routesList{
		string name;
		pointList pointsList;
		routesList* next;

		routesList(string name, pointList point) : name(name), pointsList(point),next(nullptr) {}
	};
	routesList* head;
public:
	routes() : head(nullptr){}
	void addRoute(routesList);
	void printAll();
};

