#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>
using namespace std;

class Point2d {
private:
    double x;
    double y;

public:
    // Constructor por defecto
    Point2d() : x(0.0), y(0.0) {}

    // Constructor con parámetros
    Point2d(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Constructor de copia
    Point2d(const Point2d &other) : x(other.x), y(other.y) {}

    // Destructor
    ~Point2d() {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // Setters
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    // Sobrecarga del operador +
    Point2d operator+(const Point2d &rhs) const {
        return Point2d(this->x + rhs.x, this->y + rhs.y);
    }

    // Sobrecarga del operador -
    Point2d operator-(const Point2d &rhs) const {
        return Point2d(this->x - rhs.x, this->y - rhs.y);
    }

    // Sobrecarga del operador * (escalar).
    Point2d operator*(double scalar) const {
        return Point2d(this->x * scalar, this->y * scalar);
    }

    // Sobrecarga del operador / (escalar)
    Point2d operator/(double scalar) const {
        // Se asume que scalar != 0
        return Point2d(this->x / scalar, this->y / scalar);
    }

    // Calcula la distancia al origen o a otro punto si se pasa como argumento
    double distance(const Point2d *p = nullptr) const {
        if (p == nullptr) {
            return sqrt(x * x + y * y);
        } else {
            double dx = x - p->x;
            double dy = y - p->y;
            return sqrt(dx * dx + dy * dy);
        }
    }

    // Imprime la distancia entre el objeto actual y otro punto
    void printDistance(const Point2d &other) const {
        double dist = this->distance(&other);
        cout << "Distancia entre (" << x << ", " << y << ") y ("
             << other.x << ", " << other.y << ") = " << dist << endl;
    }

    // Retorna el vector unitario del punto
    Point2d unitVector() const {
        double mag = sqrt(x * x + y * y);
        if (mag == 0) {
            return Point2d(0.0, 0.0);
        }
        return Point2d(x / mag, y / mag);
    }
};
#endif // POINT2D_H
