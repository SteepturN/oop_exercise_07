#pragma once
template class Square<double>;
template std::istream& operator>> <double>(std::istream&, Square<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Square<double>&);
template double distance<double>(std::pair<double,double>, std::pair<double,double>);
