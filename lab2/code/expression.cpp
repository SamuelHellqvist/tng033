/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

// Used only for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}

/* ************************* */


bool Expression::isRoot(double x) const
{
    bool isRoot = false;

    double difference = abs(this->operator()(x));
    if (difference < Epsilon) {
        isRoot = true;
    }

    return isRoot;
}

std::ostream& operator<<(std::ostream& os, const Expression& e)
{
    e.display(os);
    return os;
}
