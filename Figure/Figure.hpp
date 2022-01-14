#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

template <typename T>
class Figure;

template <typename T>
std::ostream& operator<<(std::ostream& cout, const Figure<T>& t);
template <typename T>
std::istream& operator>>(std::istream& cin, Figure<T>& t);



template <typename T>
class Figure {
	public:
		using size_type = std::size_t;
		using vertex_type = std::pair<T, T>;
		std::vector<vertex_type> verteces;
		Figure(const Figure<T>& t);
		Figure();
		virtual ~Figure() = default;
		virtual size_type size() const noexcept {return 0;}
		virtual void type() const noexcept {std::cout << "figure";}
		vertex_type center() const noexcept;
		void coordinates() const noexcept;
		double area() const noexcept;
		Figure<T>& operator=(const Figure<T>& t) noexcept;
		bool operator==(const Figure<T>& t) const noexcept;
		friend std::ostream& operator<< <>(std::ostream& cout,
		                                   const Figure<T>& t);
		friend std::istream& operator>> <>(std::istream& cin,
		                                   Figure<T>& t);
};

//#include "../template/Figure.tpp"
