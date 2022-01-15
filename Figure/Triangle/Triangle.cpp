#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include "../Figure.hpp"
#include "Triangle.h"

template <typename T>
Triangle<T>::Triangle()
	: Figure<T>() {
	Figure<T>::verteces.resize(size());
}

template <typename T>
std::ostream& operator<<(std::ostream& cout, const Triangle<T>& obj) {
	cout << "triangle\nsides' length:\n";
	for(std::size_t i = 0; i < obj.size(); ++i) {
		auto v1 = obj.verteces[i];
		auto v2 = obj.verteces[(i + 1) % obj.size()];
		cout << "side " << i << ": " << sqrt(pow(v1.first - v2.first, 2) +
		             pow(v1.second - v2.second, 2)) << '\n';
	}
	cout << "coordinates: ";
	obj.coordinates();
	return cout;
}
template <typename T>
double distance(std::pair<T, T> o1, std::pair<T, T> o2) {
	return sqrt(pow(o1.first - o2.first, 2)+pow(o1.second - o2.second, 2));
}

template <typename T>
std::istream& operator>>(std::istream& cin, Triangle<T>& t) {
	enum {
	FIRST_AXIS = 0,
	SECOND_AXIS = 1,
    };
	char ch(' ');
	Triangle<T> copy = t;
	for(std::size_t i = 0, cur_axis = 0; i < 3 * 2; ++i,
		    cur_axis = (cur_axis + 1) % 2) {
		while((ch == '\t') || (ch == ' ') || (ch == '\n')) {
			cin >> ch;
			if(cin.eof()) {
				t = copy;
				return cin;
			}
		}
		cin.unget();
		ch = ' ';
		if(cur_axis == FIRST_AXIS)
			cin >> t.verteces[i/2].first;
		else //(cur_axis == SECOND_AXIS)
			cin >> t.verteces[i/2].second;
		if(cin.fail()) {
			t = copy;
			return cin;
		}
	}
	return cin;
}

#include "Triangle.tpp"
