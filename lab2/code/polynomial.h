/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"

class Polynomial : public Expression {
    // ADD CODE

public:
    explicit Polynomial(const std::vector<double>& v);
    Polynomial(double d); // not explicit to allow converting from double to Polynomial

    //copy constructor

    Polynomial(const Polynomial& rhs) = default;

    virtual Polynomial* clone() const;

    Polynomial& operator=(const Polynomial& rhs) = default;

    Polynomial& operator+=(const Polynomial& rhs);

    friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs) {
        return lhs += rhs;
    };

    double operator[](const int position) const;

    double& operator[](const int position);

    virtual explicit operator std::string() const override;
    virtual double operator()(double d) const override;


private:
    std::vector<double> coefficients;


};

/*
 * std::vector should be used to store polinomial's coefficients
 */
