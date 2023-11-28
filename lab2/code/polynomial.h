/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"

class Polynomial : public Expression {

    Polynomial(double d); //contructor from a constant to a polynomial

    Polynomial(const Polynomial&) = default; //copy constructor

    ~Polynomial() = default;

    Polynomial* clone() const override;

    Polynomial operator+=(const Polynomial& rhs); //add and assign operator

    Polynomial& operator=(const Polynomial&) = default; //assign operator

    //2 polynomials added together
    friend Polynomial operator+(Polynomial lhs, const Polynomial rhs) {
        return (lhs += rhs);
    }

    double operator()(double d) const override;


    private:
        std::vector<double> coefficients;
        void display(std::ostream& os) const override;
};

/*
 * std::vector should be used to store polinomial's coefficients
 */

