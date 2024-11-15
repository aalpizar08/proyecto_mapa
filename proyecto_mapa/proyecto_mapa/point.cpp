#include "point.h"
//setters
void Point::setName(string name) {
    this->name = name;
}
void Point::setXY(Vector2f XY){
    this->X = XY.x;
    this->Y = XY.y;
}

//getters
string Point::getName() {
    return name;
}
float Point::getX(){
    return 0.0f;
}
float Point::getY(){
    return 0.0f;
}
Vector2f Point::getXY(){
    return Vector2f(X,Y);
}
