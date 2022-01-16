#include <iostream>
#include "Read_input/Read_input.hpp"
#include "Application/Application.hpp"
#include "Figure/Figure.hpp"
#include "Figure/Triangle/Triangle.h"
#include "Figure/Square/Square.h"
#include "Figure/Octahedron/Octahedron.h"
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {
	std::string help_message = "You can use\n\
--create new file: create *filename* \n\
--import file: import *filename*\n\
--export file: export *filename*\n\
\
--print file: draw\n\
--clean terminal: clean\n\
\
--print figures: print\n\
--add figure (square, triangle, octahendron): add *s || t || o*\n\
    *(point) 3 times for square, for octahedron and triangle center\
 position,\n radius, starting angle* *position to put in*\n\
--delete figure: delete *position of figure*\n\
--undo last add/delete: undo\n\
--help for this list of commands\n\
--exit\n";
	char ch(' ');
	Application app;
	char command[20];
	std::set<std::string> valid_commands = {"create", "import", "export",
	"draw", "clean", "print", "add", "delete", "undo", "exit", "help"};
	std::cout << help_message;
	do {
		while(get_command(valid_commands, command) != VALID_INPUT) {
			do ch=getchar();
			while((ch != EOF) && (ch != '\n'));
			std::cout << "wrong input" << std::endl;
			if(ch == EOF) return 0;
		}
		std::string&& command_string = static_cast<std::string>(command);
		if(command_string == "help") {
			std::cout << help_message;
		} else if(command_string == "create") {
			std::string document_name;
			if(get_value<std::string>(document_name) != VALID_INPUT)
				std::cout << "wrong input\n";
			else
				app.create_document(document_name);
		} else if (command_string == "import") {
			std::string document_name;
			if(get_value<std::string>(document_name) != VALID_INPUT)
				std::cout << "wrong input\n";
			else
				app.import_document(document_name);
		} else if (command_string == "export") {
			std::string document_name;
			if(get_value<std::string>(document_name) != VALID_INPUT)
				std::cout << "wrong input\n";
			else
				app.export_document(document_name);
		} else if (command_string == "draw") {
			app.draw();
			std::cout << std::endl;
		} else if (command_string == "clean") {
			app.clear();
		} else if (command_string == "print") {
			app.print_document();
			std::cout << std::endl;
		} else if (command_string == "add") {
			Figure<double>* f;
			std::set<std::string> valid_figures{"t", "o", "s"};
			char figure_type[3];
			if(get_command(valid_figures, figure_type) != VALID_INPUT) {
				std::cout << "wrong input\n";
				continue;
			}
			std::string figure_type_str =
				static_cast<std::string>(figure_type);
			if(figure_type_str == "t") {
				f = new Triangle<double>;
				if(get_value<Triangle<double>>
				   (*dynamic_cast<Triangle<double>*>(f)) != VALID_INPUT) {
					std::cout << "wrong input\n";
					delete f;
					continue;
				}
			} else if(figure_type_str == "o") {
				f = new Octahedron<double>;
				if(get_value<Octahedron<double>>
				   (*dynamic_cast<Octahedron<double>*>(f)) != VALID_INPUT) {
					std::cout << "wrong input\n";
					delete f;
					continue;
				}
			} else if(figure_type_str == "s") {
				f = new Square<double>;
				if(get_value<Square<double>>
				   (*dynamic_cast<Square<double>*>(f)) != VALID_INPUT) {
					std::cout << "wrong input\n";
					delete f;
				}
			}
			std::size_t index;
			if(get_value<std::size_t>(index) != VALID_INPUT || index > app.buff_size()) {
				std::cout << "wrong input\n";
				delete f;
			} else {
				app.add(index, std::shared_ptr<Figure<double>>(f));
			}
		} else if (command_string == "delete") {
			std::size_t index;
			if(get_value<std::size_t>(index) != VALID_INPUT || index >= app.buff_size())
				std::cout << "wrong input\n";
			else
				app.remove(index);
		} else if (command_string == "undo") {
			app.undo();
		} else if(command_string == "exit") return 0;
		do ch = getchar(); while((ch != '\n') && (ch != EOF));
		if(ch == EOF) return 0;
	} while(true);
	return 0;
}
