/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "Logarithm.h"
#include "polynomial.h"
#include <format>


 // ADD implementation of the member functions for class Logarithm

Logarithm::Logarithm() : logcoefficients{ new Polynomial({0, 1}) }, c1{ 0 }, c2{ 1 }, b{ 2 } {}

Logarithm::Logarithm(const Expression& e, const double d1, const double d2, const int i) {
	logcoefficients = e.clone();
	c1 = d1;
	c2 = d2;
	b = i;

}

Logarithm::Logarithm(const Logarithm& rhs)
{
	b = rhs.b;
	c1 = rhs.c1;
	c2 = rhs.c2;
	logcoefficients = rhs.logcoefficients->clone();
}

Logarithm::~Logarithm()
{
	delete logcoefficients;
	b = 0;
	c1 = 0;
	c2 = 0;

}

Logarithm& Logarithm::operator=(const Logarithm& rhs)
{

	b = rhs.b;
	c1 = rhs.c1;
	c2 = rhs.c2;
	delete logcoefficients;
	logcoefficients = rhs.logcoefficients->clone();

	return *this;
}

Logarithm* Logarithm::set_base(const int i)
{
	b = i;
	return this;
}

Logarithm::operator std::string() const {

	std::string s;

	char sign = '+';
	if (c2 < 0) {
		sign = '-';
	}

	s += std::format("{:.2f} {} {:.2f} * log_{}( {} )", c1, sign, std::abs(c2), b, std::string(*logcoefficients));



	return s;
}

Logarithm* Logarithm::clone() const
{
	return new Logarithm(*this);
}

double Logarithm::operator()(double d) const
{
	double sum;

	double e = logcoefficients->operator()(d);

	sum = c1 + c2 * log(e) / log(b);
	return sum;

}