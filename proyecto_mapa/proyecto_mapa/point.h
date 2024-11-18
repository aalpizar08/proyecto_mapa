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
	CircleShape point;
public:
    Point(string name, float X, float Y) : name(name), X(X), Y(Y) {
        point.setRadius(6.0f); // Configurar el tamaño del punto
        point.setFillColor(Color::Red);
        point.setPosition(X, Y); // Establecer la posición inicial
    }
    Point(float X, float Y) : name(""), X(X), Y(Y) {
        point.setRadius(6.0f);
        point.setFillColor(Color::Red);
        point.setPosition(X, Y);
    }
    Point(string name, Vector2f XY) : name(name), X(XY.x), Y(XY.y) {
        point.setRadius(6.0f);
        point.setFillColor(Color::Red);
        point.setPosition(X, Y);
    }
    void printPoint(RenderWindow&);//cada clase punto con su respectivo punto
    //setetrs
    void setName(string);
	void setXY(Vector2f);
    //getters
	Vector2f getXY();
	string getName();
	float getX();
	float getY();
    CircleShape getPoint();
};

