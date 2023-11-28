/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <string>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS

    bool isRoot(double x) const;

    virtual double operator()(double d) const = 0; //must be overloaded

    virtual Expression* clone() const = 0; //overload i subclass
 

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

    friend std::ostream& operator<<(std::ostream& e, const Expression&);

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    virtual void display(std::ostream&) const = 0;

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;

    Expression& operator=(const Expression& e) = default;
};
