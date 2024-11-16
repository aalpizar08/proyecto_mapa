#pragma once
#include<iostream>
#include <string>
#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;
class Point {
private:
	string name;
	float X,Y;
public:
	Point(string name, float X, float Y) :name(name), X(0), Y(0) {}
	Point(string name) : X(0), Y(0) {}
	Point(float X, float Y) : X(X), Y(Y) {}
	Point(Vector2f XY) : name(""), X(XY.x),Y(XY.y) {}
	Point(string name, Vector2f XY) : name(name), X(XY.x), Y(XY.y) {}
	void setName(string);
	void setXY(Vector2f);

	Vector2f getXY();
	string getName();
	float getX();
	float getY();
};

