#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "route.h"
using namespace std;

class routesList{//aqui se almacenan todas las rutas que se van guardando 
private:
	struct nodeList{
		string name;
		Route route;
		nodeList* next;
		nodeList(string name, Route route) : name(name), route(route), next(nullptr) {}
	};
	nodeList* head;
public:
	routesList	() : head(nullptr) {}
	void saveRoute(string, Route);
	void displayRoute(RenderWindow&, Text&, string);
	void printNames();
	void deleteRoute(string);
	void saveRoutes(string&);
	void chargeRoutes(string&);
	void selectRouteToEdit(RenderWindow&,Event&,bool&,string);
};

