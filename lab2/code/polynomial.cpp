/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <vector>
#include <string>
#include <format>
#include <cmath>
 // ADD implementation of the member functions for class Polynomial

Polynomial::Polynomial(const std::vector<double>& v) : coefficients{ v } {}


Polynomial::Polynomial(double d) {
	coefficients.push_back(d);

}







Polynomial* Polynomial::clone() const {
	return new Polynomial{ *this };
}



Polynomial& Polynomial::operator+=(const Polynomial& rhs)
{
	for (int i = 0; i < std::ssize(rhs.coefficients); i++) {
		if (i < std::ssize(coefficients)) {
			coefficients[i] += rhs.coefficients[i];
		}
		else {
			coefficients.push_back(rhs.coefficients[i]);
		}

	}
	return *this;

}

double Polynomial::operator[](const int position) const
{
	return coefficients[position];
}

double& Polynomial::operator[](const int position)
{
	return coefficients[position];
}

Polynomial::operator std::string() const {

	std::string s;
	char sign = '+';
	for (int i = 0; i < std::ssize(coefficients); i++) {
		if (i == 0) {
			s += std::format("{:.2f}", coefficients[i]);
		}
		else {
			char sign = '+';
			if (coefficients[i] < 0) {
				sign = '-';
			}

			s += std::format(" {} {:.2f} * X^{}", sign, std::abs(coefficients[i]), i);
		}
	}


	return s;
}

double Polynomial::operator()(double d) const
{
	double sum = 0.0;

	for (int i = 0; i < std::ssize(coefficients); i++) {
		double temp = coefficients[i] * std::pow(d, i);
		sum += temp;
	}
	return sum;
}
