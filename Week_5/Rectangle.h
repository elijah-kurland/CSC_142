#define RECTANGLE_H

//defines the rectangle class
class Rectangle {
private:
    double length; //private variable to store the length
    double width; //private variable to store the width

public:
//constructor to initialize the length and width of the rectangle
    Rectangle(double len = 0.0, double wid = 0.0);

    //getter function to retrieve current length
    double getLength() const;

    //getter function to retrieve current width
    double getWidth() const;

    //setter function to set the current length
    void setLength(double len);

    //setter function to set the current width
    void setWidth(double wid);

    //calculates and returns area
    double getArea() const;
};