#pragma once
template class Octahedron<double>;
template std::istream& operator>> <double>(std::istream&, Octahedron<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Octahedron<double>&);
template double distance<double>(std::pair<double,double>, std::pair<double,double>);
