#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include <string>

#include "../Figure.hpp"

#define NUM_OF_VERTECES_T 3

template <typename T>
class Triangle;

template <typename T>
std::ostream& operator<<(std::ostream& cout, const Triangle<T>& t);
template <typename T>
std::istream& operator>>(std::istream& cin, Triangle<T>& t);

template <typename T>
class Triangle : public Figure<T> {
	public:
		Triangle();
		inline typename Figure<T>::size_type size() const noexcept override {
			return NUM_OF_VERTECES_T;
		}
		inline std::string type() const noexcept override {
			return "triangle";
		}

		friend std::ostream& operator<< <>(std::ostream& cout, const Triangle<T>& t);
		friend std::istream& operator>> <>(std::istream& cin, Triangle<T>& t);
};
