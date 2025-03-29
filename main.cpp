#include <iostream>
#include "point2d.h"

int main() {

    Point2d p1;                  // Por defecto (0,0)
    Point2d p2(3.0, 4.0);        // Con parámetros (3,4)
    Point2d p3(p2);              // De copia (3,4)

    // 2. Getters y Setters.
    p1.setX(1.0);
    p1.setY(2.0);

    std::cout << "p1 = (" << p1.getX() << ", " << p1.getY() << ")\n";
    std::cout << "p2 = (" << p2.getX() << ", " << p2.getY() << ")\n";
    std::cout << "p3 = (" << p3.getX() << ", " << p3.getY() << ")\n";

    // 3. Sobrecarga de operadores
    Point2d sum = p1 + p2;
    std::cout << "p1 + p2 = (" << sum.getX() << ", " << sum.getY() << ")\n";

    Point2d diff = p2 - p1;
    std::cout << "p2 - p1 = (" << diff.getX() << ", " << diff.getY() << ")\n";

    Point2d scaled = p2 * 2.0;
    std::cout << "p2 * 2.0 = (" << scaled.getX() << ", " << scaled.getY() << ")\n";

    // 4. Distancia al origen y a otro punto
    std::cout << "Distancia de p2 al origen = " << p2.distance() << std::endl;
    std::cout << "Distancia de p2 a p1      = " << p2.distance(&p1) << std::endl;

    // 5. Imprimir distancia entre dos puntos
    p2.printDistance(p1);

    // 6. Vector unitario
    Point2d unit = p2.unitVector();
    std::cout << "Vector unitario de p2 = ("
              << unit.getX() << ", " << unit.getY() << ")\n";

    return 0;
}
