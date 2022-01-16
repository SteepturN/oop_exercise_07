#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../Figure/Figure.hpp"
#include <list>
#include <string>
#include <memory>
#include <functional>
#include <fstream>

class Application {
	class Factory;
	public:
		Application() = default;
		~Application() = default;

		void add(const int, const std::shared_ptr<Figure<double>>&);
		void remove(const int);
		void undo();

		void create_document(const std::string&);

		void export_document() const;

		void import_document(const std::string&);
		void export_document(const std::string&) const;

		void draw() const;
		void clear() const;

		void print_document() const;
		std::size_t buff_size() const;
	private:
		std::function<void()> undo_f;
		std::list<std::shared_ptr<Figure<double>>> buff;
		std::string opened_doc_name;
		std::fstream opened_doc;
		void clear_buf();
};

#endif // APPLICATION_H_
