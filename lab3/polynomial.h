/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial {


public:
	/*Polynomial();
	Polynomial(const int a);*/
	Polynomial(int i= 0, int a = 0);

	Polynomial(const std::vector<std::pair<int, int>> p);
	Polynomial(const Polynomial& rhs) = default;
	int degree() const;

	explicit operator std::string() const;

	Polynomial& operator+=(const Polynomial& rhs);
	Polynomial& operator-=(const Polynomial& rhs);
	Polynomial& operator*=(const Polynomial& rhs);
	friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs);
	friend Polynomial operator-(Polynomial lhs, const Polynomial& rhs);
	friend Polynomial operator*(Polynomial lhs, const Polynomial& rhs);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& e);




private:
	std::map<int, int> coefficients_table;
	Polynomial multiply(std::pair<int, int>t);

};