#include <iostream>
#include <stdexcept>
#include <cmath>

class Polynomial {
private:
    int degree;
    double* coefficients;

public:
    
    Polynomial() : degree(0) {
        coefficients = new double[1](); 
    }

    
    Polynomial(int deg, const double* coeffs) : degree(deg) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

  
    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    
    ~Polynomial() {
        delete[] coefficients;
    }

  
    int getDegree() const {
        return degree;
    }

   
    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * std::pow(x, i);
        }
        return result;
    }

   
    Polynomial add(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        double* resultCoeffs = new double[maxDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }


    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* resultCoeffs = new double[newDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }


    void print() const {
        for (int i = degree; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (i != degree && coefficients[i] > 0) {
                    std::cout << "+";
                }
                std::cout << coefficients[i];
                if (i > 0) {
                    std::cout << "x";
                    if (i > 1) {
                        std::cout << "^" << i;
                    }
                }
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};


int main() {

    double coeffs1[] = {1, 2, 3};  
    Polynomial p1(2, coeffs1);

    
    double coeffs2[] = {5, 1, 4};  
    Polynomial p2(2, coeffs2);

    
    std::cout << "Polynomial 1: ";
    p1.print();
    std::cout << "Polynomial 2: ";
    p2.print();

   
    std::cout << "p1(2) = " << p1.evaluate(2) << std::endl;

   
    Polynomial sum = p1.add(p2);
    std::cout << "Sum of p1 and p2: ";
    sum.print();

  
    Polynomial product = p1.multiply(p2);
    std::cout << "Product of p1 and p2: ";
    product.print();

    return 0;
}
