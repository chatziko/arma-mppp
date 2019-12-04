#include <iostream>

#include <mp++/mp++.hpp>
#include <armadillo>

#include "arma_mp++.hpp"

using std::cout;
using int_t = mppp::integer<1>;
using rat_t = mppp::rational<1>;

using arma::Mat;
using arma::Row;

void integer() {
	Mat<int_t> M(2,2);

	cout << "M(2,2)\n" << M;
	cout << "M.ones()\n" << M.ones();
	cout << "M = 'string'\n" << (M  = "1 3; -1 -6");
	cout << "M:\n" << M;
	cout << "M*M:\n" << M*M;
	cout << "abs:\n" << arma::abs(M) << "\n";
	cout << "cdot(row(0),row(1)): " << arma::cdot(M.row(0), M.row(1)) << "\n";
	cout << "max: " << arma::max(M) << "\n";
	cout << "accu: " << arma::accu(M) << "\n";
	cout << "M * -3\n" << (M * int_t(-3));
	cout << "M.each_row() + Row(2,3)\n" << (M.each_row() + Row<int_t>("2 3"));
	cout << "M == -3\n" << (M == int_t(-3)) << "\n";
}

void rational() {
	Mat<rat_t> M(2,2);

	cout << "M(2,2)\n" << M;
	cout << "M.ones()\n" << M.ones();
	cout << "M.randu()\n" << M.randu();
	cout << "M = 'string'\n" << (M  = "1/2 3/1; -1/3 -6");
	cout << "M:\n" << M;
	cout << "M*M:\n" << M*M;
	cout << "abs:\n" << arma::abs(M) << "\n";
	cout << "cdot(row(0),row(1)): " << arma::cdot(M.row(0), M.row(1)) << "\n";
	cout << "max: " << arma::max(M) << "\n";
	cout << "accu: " << arma::accu(M) << "\n";
	cout << "M * -1/3\n" << (M * rat_t(-1,3));
	cout << "M.each_row() + Row(1/2,1/3)\n" << (M.each_row() + Row<rat_t>("1/2 1/3"));
	cout << "M == -1/3\n" << (M == rat_t(-1,3)) << "\n";
}

int main() {
	integer();
	rational();
}