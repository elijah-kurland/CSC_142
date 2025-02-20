#include "Rectangle.h" //header file

//constructor to initialize length and width
Rectangle::Rectangle(double len, double wid) {
    length = len; //set rectangle length
    width = wid; //set rectangle width
}

//getter function to return the length
double Rectangle::getLength() const {
    return length;
}

//getter function to return the width
double Rectangle::getWidth() const {
    return width;
}

//setter function to set the length
void Rectangle::setLength(double len) {
    length = len;
}

//setter function to set the width
void Rectangle::setWidth(double wid) {
    width = wid;
}

//getter function to calculate and return the area
double Rectangle::getArea() const {
    return length * width;
}