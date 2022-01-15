#ifndef FACTORY_H_
#define FACTORY_H_
#include <memory>
#include <list>
#include "../Application.hpp"
#include "../../Figure/Figure.hpp"
#include <iostream>
class Application::Factory {
	public:
		static void draw(const std::list<std::shared_ptr<Figure<double>>> &list) {
			for(auto i : list) {
				i->type();
				std::cout << std::endl;
				// std::cout << "\nsides' length:\n";
				// for(int j = 0; j < i->size(); ++j) {
				// 	auto v1 = i->verteces[j];
				// 	auto v2 = i->verteces[(j + 1) % i->size()];
				// 	std::cout << "side " << j << ": " << sqrt(pow(v1.first - v2.first, 2) +
				// 	                                     pow(v1.second - v2.second, 2)) << '\n';
				// }
				// std::cout << "coordinates: ";
				// i->coordinates();
				std::cout << *i << std::endl;
			}
	}
	static void clear() {
		system("clear");
	}
};
#endif // FACTORY_H_
