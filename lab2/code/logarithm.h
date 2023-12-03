/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
    // ADD CODE
public:
    Logarithm();

    Logarithm(const Expression& e, const double d1, const double d2, const int i);

    Logarithm(const Logarithm& rhs);

    virtual ~Logarithm();

    Logarithm& operator=(const Logarithm& rhs);

    Logarithm* set_base(const int i);

    virtual explicit operator std::string() const override;

    virtual Logarithm* clone() const override;

    virtual double operator()(double d) const override;




private:
    Expression* logcoefficients;
    int b;
    double c1;
    double c2;


};