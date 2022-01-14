#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

#include "Octahedron.h"
// template <typename T>
// inline constexpr typename Figure<T>::size_type Octahedron<T>::size() const noexcept {
// 	return NUM_OF_VERTECES;
// }

// template <typename T>
// inline void Octahedron<T>::type() const noexcept {
// 	std::cout << "octahedron";
// }

template <typename T>
std::ostream& operator<<(std::ostream& cout, const Octahedron<T>& obj) {
	cout << "octahedron\nsides' length:\n";
	for(int i = 0; i < obj.size(); ++i) {
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
//«std::istream& operator>><int>(std::istream&, Octahedron<int>&)»
template <typename T>
std::istream& operator>>(std::istream& cin, Octahedron<T>& t) {
	enum {
	FIRST_AXIS = 0,
	SECOND_AXIS = 1,
    };
	char ch(' ');
	Octahedron<T> copy = t;
	for(int i = 0, cur_axis = 0; i < ( t.size() - 1 ) * 2;
	    ++i, cur_axis = (cur_axis + 1)%2) {
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
	if((distance(t.verteces[0], t.verteces[1]) !=
	    distance(t.verteces[1], t.verteces[2])) ||
	   (distance(t.verteces[0], t.verteces[2])
	    != distance(t.verteces[0], t.verteces[1])*sqrt(2))){
		t = copy;
		cin.setstate(std::ios_base::failbit);
		return cin;
	}
	t.verteces[3].first = t.verteces[0].first - t.verteces[1].first
		+ t.verteces[2].first;
	t.verteces[3].second = t.verteces[0].second - t.verteces[1].second
		+ t.verteces[2].second;
	return cin;
}
// template <typename T>
// void make_2_more_verteces(Octahedron<T>& t, double side_length) {
// 	double _distance = distance(t.verteces[0], t.verteces[2]);

// 	std::pair<double, double> center(
// 		( t.verteces[0].first + t.verteces[2].first) / 2.0,
// 		( t.verteces[0].second + t.verteces[2].second ) / 2.0);

// 	double alpha = std::atan(( t.verteces[2].second - t.verteces[0].second ) /
// 	                          ( t.verteces[2].first - t.verteces[0].first ));

// 	double side = sqrt(pow( side_length, 2 )
// 	                   - pow( _distance / 2.0 , 2 ));

// 	std::cout << center.first - side * sin(alpha) << ' ' << center.second + side * cos(alpha) << '+' <<
// 		center.first + side * sin(alpha) << ' ' <<
// 		center.second - side * cos(alpha);

// 	t.verteces[1] = std::make_pair<T, T>(
// 		static_cast<T>( center.first - side * sin(alpha) ),
// 		static_cast<T>( center.second + side * cos(alpha) ));
// 	t.verteces[3] = std::make_pair<T, T>(
// 		static_cast<T>(center.first + side * sin(alpha)),
// 		static_cast<T>(center.second - side * cos(alpha)));
// }
// //std::istream& operator>><int>(std::istream&, Octahedron<int>&)
// template <typename T>
// std::istream& operator>> (std::istream& cin, Octahedron<T>& t) {
// 	enum {
// 	FIRST_AXIS = 0,
// 	SECOND_AXIS = 1,
//     };
// 	char ch(' ');
// 	Octahedron<T> copy = t;
// 	for(int i = 0, cur_axis = 0; i < ( NUM_OF_VERTECES / 2 ) * 2;
// 	    ++i, cur_axis = (cur_axis + 1)%2) {
// 		while((ch == '\t') || (ch == ' ') || (ch == '\n')) {
// 			cin >> ch;
// 			if(cin.eof()) {
// 				t = copy;
// 				return cin;
// 			}
// 		}
// 		cin.unget();
// 		ch = ' ';
// 		if(cur_axis == FIRST_AXIS)
// 			cin >> t.verteces[ i / 2 ].first; //0 & 2 points
// 		else //(cur_axis == SECOND_AXIS)
// 			cin >> t.verteces[ i / 2 ].second;
// 		if(cin.fail()) {
// 			t = copy;
// 			return cin;
// 		}
// 	}
// 	t.verteces[2] = t.verteces[1];
// 	double side_length;
// 	cin >> side_length;
// 	if(cin.fail() ||
// 	   distance(t.verteces[0], t.verteces[1]) > 2 * side_length) {
// 		t = copy;
// 		return cin;
// 	}
// 	make_2_more_verteces(t, side_length);
// 	return cin;
// }

#include "Octahedron.tpp"
