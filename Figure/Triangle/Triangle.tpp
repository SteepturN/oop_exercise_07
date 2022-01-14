#pragma once
template class Triangle<double>;
template std::istream& operator>> <double>(std::istream&, Triangle<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Triangle<double>&);
template double distance<double>(std::pair<double,double>, std::pair<double,double>);
//template void make_2_more_verteces(Triangle<double>& t, double side_length);
