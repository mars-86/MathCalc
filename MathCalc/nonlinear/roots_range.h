#ifndef _ROOT_RANGE_H_
#define _ROOT_RANGE_H_
#pragma once

#include <string>
#include <vector>
#include "../base_calc/base_calc.h"

namespace NonLinear {

	class RootRange {
	public:
		RootRange(const std::string& equation);
		~RootRange();

		const std::vector<std::pair<double, double>>& get_ranges() const;
	private:
		BaseCalc _base_calc;
		std::vector<std::pair<double, double>> _ranges;
		std::string _equation;

		void find_ranges(void);
	};

}

#endif // !_ROOT_RANGE_H_
