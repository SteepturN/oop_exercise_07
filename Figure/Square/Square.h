#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include "../Figure.hpp"
#include <string>
#define NUM_OF_VERTECES_S 4

template <typename T>
class Square;

template <typename T>
std::ostream& operator<<(std::ostream& cout, const Square<T>& t);
template <typename T>
std::istream& operator>>(std::istream& cin, Square<T>& t);

template <typename T>
class Square : public Figure<T> {
	public:
		Square();
		inline typename Figure<T>::size_type size() const noexcept override {
			return NUM_OF_VERTECES_S;
		}
		inline std::string type() const noexcept override {
			return "square";
		}

		friend std::ostream& operator<< <>(std::ostream& cout, const Square<T>& t);
		friend std::istream& operator>> <>(std::istream& cin, Square<T>& t);
};
