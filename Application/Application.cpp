#include "Application.hpp"
#include <list>
#include <memory>
#include <functional>
#include <fstream>
#include <iostream>
#include "../Figure/Figure.hpp"
#include "../Figure/Triangle/Triangle.h"
#include "../Figure/Octahedron/Octahedron.h"
#include "../Figure/Square/Square.h"
#include "Factory/Factory.hpp"

void Application::clear_buf() {
	buff.clear();
}

void Application::add(const int num, const std::shared_ptr<Figure<double>>& elem) {
	auto i = buff.begin();
	for(int count = num ; count > 0 ; count--, i++);
	buff.insert(i, elem);
	undo_f = [num, elem, this](){
		auto i = buff.begin();
		for(int count = num ; count > 0 ; count--, i++);
		buff.erase( i );
	};
}
void Application::remove(const int num) {
	auto i = buff.begin();
	for(int count = num ; count > 0 ; count--, i++);
	auto elem = *i;
	buff.erase(i);
	undo_f = [num, elem, this](){
		auto i = buff.begin();
		for(int count = num ; count > 0 ; count--, i++);
		buff.insert(i, elem);
	};
}

void Application::undo() {
	undo_f();
}

void Application::create_document(const std::string& name) {
	using io = std::ios;
	opened_doc_name = name;
	opened_doc.open(name, io::trunc | io::out | io::in);
}


void Application::export_document() const {
	export_document(opened_doc_name);
}
void Application::export_document(const std::string& name) const { //save doc in 'name'
	using io = std::ios;
	std::fstream doc(name, io::out | io::trunc | io::binary);
	for(auto figure_ptr : buff) {
		typename Figure<double>::size_type num_of_verteces = figure_ptr->size();
		doc.write(reinterpret_cast<char*>(&num_of_verteces),
		          sizeof(num_of_verteces));
		doc.write(reinterpret_cast<char*>(figure_ptr->verteces.data()),
		          sizeof(Figure<double>::vertex_type) * num_of_verteces);
	}
	doc.close();
}
std::size_t Application::buff_size() const{
	return buff.size();
}
void Application::import_document(const std::string& name) {
	enum {
	OCTAHEDRON_SIZE = 8,
	TRIANGLE_SIZE = 3,
	SQUARE_SIZE = 4,
};
	using io = std::ios;
	std::fstream doc(name, io::in | io::binary);
	clear_buf();
	typename Figure<double>::size_type read_figure_size;
	doc.read(reinterpret_cast<char*>(&read_figure_size), sizeof(Figure<double>::size_type));
	while(doc.good()) {
		Figure<double>* read_figure_ptr;
		switch(read_figure_size) {
			case OCTAHEDRON_SIZE:
				read_figure_ptr = new Octahedron<double>;
				break;
			case TRIANGLE_SIZE:
				read_figure_ptr = new Triangle<double>;
			    break;
			case SQUARE_SIZE:
				read_figure_ptr = new Square<double>;
			    break;
		}
		read_figure_ptr->verteces.resize(read_figure_size);
		for(std::size_t i = 0; i < read_figure_size; ++i) {
			doc.read(reinterpret_cast<char*>(&(read_figure_ptr->verteces[i])),
			         sizeof(Figure<double>::vertex_type));
		}
		buff.push_back(std::shared_ptr<Figure<double>>(read_figure_ptr));
		doc.read(reinterpret_cast<char*>(&read_figure_size),
		         sizeof(Figure<double>::size_type));
	}
	doc.close();
	undo_f = [](){};
}

void Application::draw() const {
	Application::Factory::draw(buff);
}

void Application::clear() const {
	Application::Factory::clear();
}

void Application::print_document() const {
	for(auto i : buff) {
		std::cout << i->type() << std::endl;
	}
}
