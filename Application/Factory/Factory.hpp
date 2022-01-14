#ifndef FACTORY_H_
#define FACTORY_H_
#include <memory>
#include <list>
#include "../Application.hpp"
#include "../../Figure/Figure.hpp"
class Application::Factory {
	public:
		static void draw(const std::list<std::shared_ptr<Figure<double>>> list) {
			for(auto i : list) {
				i->type();
				std::cout << *i;
			}
	}
	static void clear() {
		system("clear");
	}
};
#endif // FACTORY_H_
