/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"
#include <vector>
#include <map>
#include <format>
#include <string>
#include <algorithm>


Polynomial::Polynomial(int i , int a) { // iX^a
	if (i != 0) {
		coefficients_table[a] = i; // i is the coefficient
	}
}

Polynomial::operator std::string() const
{
	std::string s;
	int counter = 0;
	char sign = '+';
	if (coefficients_table.empty()) {
		return std::string("0");
		}
	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		int i = it->first;
		int a = it->second;
		if (counter == 0) {
			if (a > 0) {
				s += std::format("{}X^{}", a, i);
			}
			
			else {
				sign = '-';
				s += std::format("{}{}X^{}", sign, std::abs(a), i);
			}
			counter++;
			continue;
		}
		sign = '+';
		if (a < 0) {
			sign = '-';
		}
		s += std::format(" {} {}X^{}", sign, std::abs(a), i);
	}
	return s;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs)
{
	for (auto it = rhs.coefficients_table.begin(); it != rhs.coefficients_table.end(); ++it) {
		
		
		coefficients_table[it->first] += it->second;	
		
	}

	Polynomial newPoly;
	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		if (it->second != 0) {
			newPoly.coefficients_table[it->first] += it->second;

		}
	}

	//coefficients_table.clear();
	*this = newPoly;

	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& rhs)
{
	for (auto it = rhs.coefficients_table.begin(); it != rhs.coefficients_table.end(); ++it) {
		coefficients_table[it->first] -= it->second;
	}

	Polynomial newPoly;
	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		if (it->second != 0) {
			newPoly.coefficients_table[it->first] += it->second;

		}
	}

	//coefficients_table.clear();
	*this = newPoly;




	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& rhs)
{
	std::pair<int, int> p;

	Polynomial result;

	for (auto it = rhs.coefficients_table.begin(); it != rhs.coefficients_table.end(); ++it) {
		p.first = it->first;
		p.second = it->second;
		result += multiply(p);
	}
	*this = result;
	return *this;
}

Polynomial operator+(Polynomial lhs,const Polynomial& rhs)
{
	return lhs += rhs;
	
}

Polynomial operator-(Polynomial lhs,const Polynomial& rhs)
{
	return lhs -= rhs;
}

Polynomial operator*(Polynomial lhs,const Polynomial& rhs)
{
	 lhs *= rhs;
	 return lhs;
}

bool operator==(const Polynomial& lhs,const Polynomial& rhs)
{
	return (lhs.coefficients_table == rhs.coefficients_table);
}

std::ostream& operator<<(std::ostream& os, const Polynomial& e) {

	os << std::string(e);
	return os;
}




Polynomial Polynomial::multiply(std::pair<int, int> t)
{
	Polynomial result;
	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		int a = it->second * t.second;
		int i = it->first + t.first;
		result.coefficients_table[i] = a;
	}
	return result;
}



Polynomial::Polynomial(const  std::vector<std::pair<int, int>> p) { 
	std::copy(p.begin(), p.end(), std::inserter(coefficients_table, std::begin(coefficients_table)));
	
}

int Polynomial::degree() const
{
	if (coefficients_table.empty()) {
		return 0;
	}
	return coefficients_table.rbegin()->first;
}


