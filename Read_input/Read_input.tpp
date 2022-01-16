#pragma once
template read_return_t get_value (Square<double>& d);
template read_return_t get_value (Triangle<double>& d);
template read_return_t get_value (Octahedron<double>& d);
template read_return_t get_value (int& d);
template read_return_t get_value (std::size_t& d);
#include <string>
template read_return_t get_value (std::string& d);
