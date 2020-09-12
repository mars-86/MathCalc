#include "newton.h"
#include <valarray>
#include <math.h>
using namespace PolynomialMethods;

Newton::Newton()
{
}

Newton::~Newton() {}

int zero_count(const std::vector<bool> v)
{
	int ctr = 0;
	for (auto i : v) if (!(i & 1)) ++ctr;
	return ctr;
}

double mul_tab(double fx, const std::vector<bool>& bin, const std::vector<std::vector<double>>& expressions)
{
	double res = fx;
	for (int i = 0; i < bin.size(); ++i)
		res *= expressions[i][bin[i]];
	return res;
}

const std::string build_polynomial(const std::vector<std::vector<double>>& polynomial)
{
	std::string poly;
	for (int i = polynomial.size() - 1; i >= 0; --i) {
		double sum = 0;
		// REFAC: use sum function
		for (int j = 0; j < polynomial[i].size(); ++j)
			sum += polynomial[i][j];
		poly += (sum < 0) ? std::to_string(sum) : '+' + std::to_string(sum);
		poly += (i > 1) ? "x^" + std::to_string(i) : (i > 0) ? "x" : "";
	}
	if (poly.size() > 0 && poly.front() == '+') poly.erase(poly.begin());
	return poly;
}

// OPTIMTIZATION: Build iterations binary array at first, that way we don't need to repeat
// binary convertions in every iteration of the previous steps
void Newton::apply(const PolynomialCommon::PointSet p)
{
	std::vector<std::vector<double>> gtemp;
	for (int i = 0; i < p.size(); ++i)
		gtemp.push_back({ (double)p[i].first, (double)p[i].second });

	// lets apply newton polynomial
	int n = 0;
	do {

		for (int i = 1; i < p.size() - n; ++i) {
			int prev = i - 1, x_offset = n + 1, y_offset = i + n;
			gtemp[prev].insert(gtemp[prev].end(), {
				(gtemp[i][x_offset] - gtemp[prev][x_offset]) / (gtemp[y_offset][0] - gtemp[prev][0])
			});
		}

	} while (++n < p.size());

	std::vector<std::vector<double>> polynomial(p.size());
	// lets build the multiplication tables
	// n1 + n2(x - m1) + n3(x - m1)(x - m2) + ...
	//
	// n1		it[bin] |	n2		it[bin]	|	n3
	//			---------------		------------------
	//			0 [0]	| n2.x		0 [00]	| n3.x.x
	//			1 [1]	| n2.m1		1 [01]	| n3.x.m2	......
	//								2 [10]	| n3.m1.x
	//								3 [11]	| n3.m1.m2
	//
	// NOTE: x degree depends on zeroes count

	// Build expressions vector
	// [0] -> (1 - m1)
	// [1] -> (1 - m2)
	// [2] -> (1 - m3)
	// [n] -> (1 - mn)

	std::vector<std::vector<double>> expressions;
	for (int i = 0; i < gtemp.size() - 1; ++i)
		expressions.push_back( {1, -gtemp[i][0]} );

	// then the iteration binary (it[bin]) will determine expressions quantity
	// and bin[n] retrieves which number we must multiply -> 1 | mn

	for (int i = 0; i < p.size(); ++i) {
		int it = pow(2, i) - 1, fx = i + 1;
		for (int j = 0; j <= it; ++j) {
			auto bin = _base_calc.dec_to_bin_arr(j, i);
			// it = 0 means no iteration (n1)
			int x_deg = (it > 0) ? zero_count(bin) : 0;
			polynomial[x_deg].push_back(mul_tab(gtemp[0][fx], bin, expressions));
		}
	}
	set_result(build_polynomial(polynomial));
}