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
	cout << "Triangle\nsides' length:\n";
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
	const double triangle_central_angle = 2 * M_PI/ 3.0;
	Triangle<T> copy = t;
	std::pair<double, double> center;
	double radius;
	double fi;
	cin >> center.first;
	if(cin.fail()) {
		t = copy;
		return cin;
	}
	cin >> center.second;
	if(cin.fail()) {
		t = copy;
		return cin;
	}
	cin >> radius;
	if(cin.fail()) {
		t = copy;
		return cin;
	}
	cin >> fi;
	if(cin.fail()) {
		t = copy;
		return cin;
	}
	for(double i = 0; i < t.size(); ++i) {
		t.verteces[i].first = center.first +
			radius * cos( fi + i * triangle_central_angle );
		t.verteces[i].second = center.second +
			radius * sin( fi + i * triangle_central_angle );
	}
	return cin;
}

#include "Triangle.tpp"
