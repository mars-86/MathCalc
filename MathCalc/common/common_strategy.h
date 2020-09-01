#ifndef _MATH_CALC_COMMON_STRATEGY_H_
#define _MATH_CALC_COMMON_STRATEGY_H_
#pragma once

#include <iostream> 
#include <vector>
#include <map>
#include <iomanip>
#include "../base_calc/base_calc.h"

class CommonStrategy {
private:
	template<typename T>
	struct _Grid {
		std::vector<std::vector<std::string>> _header;
		std::vector<std::vector<T>> _grid; // grid holds iterations
	};
	typedef struct _Grid<std::string> grid_s_t;
	typedef struct _Grid<double> grid_d_t;
public:
	virtual ~CommonStrategy() {};
	void grid_set_header(const std::vector<std::string>& header)
	{
		_grid._header.insert(_grid._header.begin(), header);
		_gridd._header.insert(_gridd._header.begin(), header);
	}

	void grid_insert_row(std::vector<std::string> row)
	{
		_grid._grid.push_back(row);
	}

	void grid_insert_row(std::vector<double> row)
	{
		_gridd._grid.push_back(row);
	}
	
	std::vector<std::vector<std::string>> get_grid_header(void) const
	{
		return _grid._header;
	}

	std::vector<std::vector<std::string>> get_grid(void) const
	{
		return _grid._grid;
	}

	std::vector<std::vector<double>> get_gridd(void) const
	{
		return _gridd._grid;
	}

	double resolv_eq(const std::string& eq, const std::map<std::string, std::vector<std::string>> var_val)
	{
		std::string f = eq;
		_base_calc.resolv(f, var_val), f.clear();
		return std::stod(_base_calc.get_result());
	}

	double resolv_eq(const std::string& eq, const std::map<std::string, std::vector<char*>> var_val)
	{
		std::string f = eq;
		_base_calc.resolv(f, var_val), f.clear();
		return std::stod(_base_calc.get_result());
	}

	void set_iterations(int it)
	{
		_iterations = it;
	}
	
	int get_iterations(void) const
	{
		return _iterations;
	}

	void set_result(const std::string& result)
	{
		_result = result;
	}

	std::string get_result(void) const
	{
		return _result;
	}

	void set_result(double result)
	{
		_resultd = result;
	}

	double get_resultd(void) const
	{
		return _resultd;
	}

	void print_grid(void)
	{
		auto hd = get_grid_header();
		auto gd = get_grid();

		print_head();
		for (auto i : gd) {
			for (int j = 0; j < i.size(); ++j)
				std::cout << "| " << std::left << std::setw(14) << i.at(j);
			std::cout << "|" << std::endl;
			print_line(hd[0].size());
		}
	}

	void print_gridd(void)
	{
		auto hd = get_grid_header();
		auto gd = get_gridd();

		print_head();
		for (auto i : gd) {
			for (int j = 0; j < i.size(); ++j)
				std::cout << "| " << std::left << std::setw(14) << i.at(j);
			std::cout << "|" << std::endl;
			print_line(hd[0].size());
		}
	}

protected:
	BaseCalc _base_calc;
	int _iterations;
	grid_s_t _grid;
	grid_d_t _gridd;
	std::string _result;
	double _resultd;

private:
	inline void print_head()
	{
		auto head = get_grid_header();
		// checks header != null
		size_t h_size = (head.size() > 0) ? head[0].size() : 0;
		print_line(h_size);
		for (auto i : head)
			for (auto j : i)
				std::cout << std::left << std::setw(16) << j;
		std::cout << "|" << std::endl;
		print_line(h_size);
	}

	inline void print_line(size_t columns)
	{
		for (int i = 0; i < 16 * columns; ++i)
			std::cout << '-';
		std::cout << std::endl;
	}
};

#endif // !_MATH_CALC_COMMON_STRATEGY_H_
