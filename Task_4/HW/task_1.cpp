#include <iostream>
#include <cmath>  

class Circle {
private:
    double radius;

public:
   
    Circle(double r) : radius(r) {}

   
    double getArea() const {
        return M_PI * radius * radius; 
    }

    
    double getPerimeter() const {
        return 2 * M_PI * radius;  
    }
};

int main() {
   
    Circle c(5.0);

    
    std::cout << "Area of the circle: " << c.getArea() << std::endl;
    std::cout << "Perimeter (Circumference) of the circle: " << c.getPerimeter() << std::endl;

    return 0;
}
