/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <vector>;
#include <cmath>

// ADD implementation of the member functions for class Polynomial

Polynomial* Polynomial::clone() const
{
    return new Polynomial(*this);
}

Polynomial Polynomial::operator+=(const Polynomial& rhs){
    for (int i = 0; i < rhs.coefficients.size(); i++) {
        if (i <= coefficients.size()) {
            coefficients[i] += rhs.coefficients[i];
        }
        else {
            coefficients.push_back(rhs.coefficients[i]);
        }
       
    }
    return *this;
   
}

//function that will calculate the sum of the polynomial with x = d
double Polynomial::operator()(double d) const
{
    double sum = 0;

    for (int i = 0; i <= coefficients.size(); i++) {
        double temp = coefficients[i] * pow(d, i);
        sum = sum += temp;
    }

    return sum;
}

void Polynomial::display(std::ostream& os) const
{
    for (int i = 0; i <= coefficients.size(); i++) {
        if (i == 0) {
            os << coefficients[i] << " ";
        }
        else if (i > 0) {
            os << " + " << coefficients[i] << "X^" << i;
        }
        //the coeficient is smaller than zero, negative number
        else {
            os << coefficients[i] << "X^" << i;
        }
    }
}
