#include "ls_approximation.h"
using namespace LeastSquaresMethods;

LSApproximation::LSApproximation()
{
	grid_set_header({ "| p(x,y)", "| xi", "| yi", "| (xi)^2", "| xi*yi", "| P(xi)", "| E = sum(yi - P(xi))^2" });
}

LSApproximation::~LSApproximation() {}

void LSApproximation::apply(const LeastSquaresCommon::PointSet& p)
{
	std::vector<double> xi, yi, xpow, xiyi, pxi;
	for (auto i : p) {
		xi.push_back(i.first), yi.push_back(i.second);
		xpow.push_back(pow(i.first, 2)), xiyi.push_back((double)i.first * i.second);
	}
	double xi_sum = _base_calc.summation<double>(xi);
	double yi_sum = _base_calc.summation<double>(yi);
	double xpow_sum = _base_calc.summation<double>(xpow);
	double xiyi_sum = _base_calc.summation<double>(xiyi);

	const std::string slope_eq = _base_calc.slope(xi.size(), xi_sum, yi_sum, xpow_sum, xiyi_sum);
	for (auto i : xi)
		pxi.push_back(resolv_eq(slope_eq, _base_calc.gen_var_val_tab("x", i)));
	double pxi_sum = _base_calc.summation<double>(xiyi);

	for (int i = 0; i < xi.size(); ++i)
		grid_insert_row({ (double)i, xi[i], yi[i], xpow[i], xiyi[i], pxi[i] });

	double e = 0;
	for (int i = 0; i < yi.size(); ++i)
		e += pow(yi[i] - pxi[i], 2);
	grid_insert_row({ -1, xi_sum, yi_sum, xpow_sum, xiyi_sum, pxi_sum, e });
}
