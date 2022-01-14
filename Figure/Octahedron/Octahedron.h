#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include "../Figure.hpp"

#define NUM_OF_VERTECES_O 8

template <typename T>
class Octahedron;

template <typename T>
std::ostream& operator<<(std::ostream& cout, const Octahedron<T>& t);
template <typename T>
std::istream& operator>>(std::istream& cin, Octahedron<T>& t);

template <typename T>
class Octahedron : public Figure<T> {
	public:
		typename Figure<T>::size_type size() const noexcept override {
			return NUM_OF_VERTECES_O;
		};
		void type() const noexcept override {
			std::cout << "octahedron";
		};
		friend std::ostream& operator<< <>(std::ostream& cout, const Octahedron<T>& t);
		friend std::istream& operator>> <>(std::istream& cin, Octahedron<T>& t);
};

//#include "Octahedron.tpp"
