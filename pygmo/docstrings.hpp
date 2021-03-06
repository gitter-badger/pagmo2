/* Copyright 2017 PaGMO development team

This file is part of the PaGMO library.

The PaGMO library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 3 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The PaGMO library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the PaGMO library.  If not,
see https://www.gnu.org/licenses/. */

#ifndef PYGMO_DOCSTRINGS_HPP
#define PYGMO_DOCSTRINGS_HPP

#include <string>

namespace pygmo
{
// population
std::string population_docstring();
std::string population_push_back_docstring();
std::string population_decision_vector_docstring();
std::string population_best_idx_docstring();
std::string population_worst_idx_docstring();
std::string population_size_docstring();
std::string population_set_xf_docstring();
std::string population_set_x_docstring();
std::string population_set_problem_seed_docstring();
std::string population_get_problem_docstring();
std::string population_get_f_docstring();
std::string population_get_x_docstring();
std::string population_get_ID_docstring();
std::string population_get_seed_docstring();

// problem
std::string problem_docstring();
std::string problem_fitness_docstring();
std::string problem_gradient_docstring();
std::string problem_get_best_docstring(const std::string &);

// algorithm
std::string algorithm_docstring();

// user - problems
std::string rosenbrock_docstring();
std::string decompose_decompose_fitness_docstring();
std::string get_best_docstring(const std::string &);

// user - algorithms
std::string cmaes_docstring();
std::string cmaes_get_log_docstring();
std::string compass_search_docstring();
std::string compass_search_get_log_docstring();
std::string de_docstring();
std::string de_get_log_docstring();
std::string de1220_docstring();
std::string de1220_get_log_docstring();
std::string moead_docstring();
std::string moead_get_log_docstring();
std::string sade_docstring();
std::string sade_get_log_docstring();

// stand alone functions
std::string fast_non_dominated_sorting_docstring();
}

#endif
