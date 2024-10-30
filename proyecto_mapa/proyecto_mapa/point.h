#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include <string.h>
using namespace std;
using namespace sf;

class Point{
private:
	string name;
	float x;
	float y;
public:
	Point(string name, float x, float y) {
		this->name = name;
		this->x = x;
		this->y = y;
	}
    //setters
    void setName(string name) {
        this->name = name;
    }
    void setX(float x) {
        this->x = x;
    }
    void setY(float y) {
        this->y = y;
    }
    //getters
    string getName() const {
        return name;
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }
};

