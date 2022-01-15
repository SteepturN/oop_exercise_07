#pragma once
template class Figure<double>;
//template std::istream& operator>> <double>(std::istream&, Figure<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Figure<double>&);
//template double distance<double>(std::pair<double,double>, std::pair<double,double>);
//template void make_2_more_verteces(Figure<double>& t, double side_length);
