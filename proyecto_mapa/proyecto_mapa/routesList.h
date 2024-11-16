#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "route.h"
using namespace std;

class routesList{
private:
	struct nodeList{
		string name;
		Route* route;
		nodeList* next;
		nodeList(string name, Route* route) : name(name), route(route), next(nullptr) {}
	};
	nodeList* head;
public:
	routesList	() : head(nullptr) {}
	void saveRoute(string, Route*);
	void selectRoute(RenderWindow&, Text&, string);
	void printNames();
	void deleteRoute(string);
	void loadRoutes();
	void downloadRoutes();
};

