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

#ifndef PAGMO_PROBLEM_SCHWEFEL_HPP
#define PAGMO_PROBLEM_SCHWEFEL_HPP

#include <exception>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../exceptions.hpp"
#include "../problem.hpp" // needed for cereal registration macro
#include "../types.hpp"

namespace pagmo
{

/// The Schwefel problem.
/**
 * \image html schwefel.png "Two-dimensional Schwefel function." width=3cm
 *
 * This is a scalable box-constrained continuous single-objective problem.
 * The objective function is the generalised n-dimensional Schwefel function:
 * \f[
 * 	F\left(x_1,\ldots,x_n\right) = 418.9828872724338 n - \sum_{i=1}^{n} x_i\sin \sqrt{|x_i|}, \quad x_i \in \left[
 * -500,500 \right].
 * \f]
 * The global minimum is in \f$x_i=420.9687, i = 1..n\f$, where \f$ F\left( 420.9687,\ldots,420.9687 \right) = 0 \f$.
 */
struct schwefel {
    /// Constructor from dimension
    schwefel(unsigned int dim = 1u) : m_dim(dim)
    {
        if (dim < 1u) {
            pagmo_throw(std::invalid_argument,
                        "Schwefel Function must have minimum 1 dimension, " + std::to_string(dim) + " requested");
        }
    };
    /// Fitness
    vector_double fitness(const vector_double &x) const
    {
        vector_double f(1, 0.);
        auto n = x.size();
        for (decltype(n) i = 0u; i < n; i++) {
            f[0] += x[i] * std::sin(std::sqrt(std::abs(x[i])));
        }
        f[0] = 418.9828872724338 * static_cast<double>(n) - f[0];
        return f;
    }
    /// Problem bounds
    std::pair<vector_double, vector_double> get_bounds() const
    {
        vector_double lb(m_dim, -500);
        vector_double ub(m_dim, 500);
        return {lb, ub};
    }
    /// Problem name
    std::string get_name() const
    {
        return "Schwefel Function";
    }
    /// Optimal solution
    vector_double best_known() const
    {
        return vector_double(m_dim, 420.9687);
    }
    /// Serialization
    template <typename Archive>
    void serialize(Archive &ar)
    {
        ar(m_dim);
    }
    /// Problem dimensions
    unsigned int m_dim;
};

} // namespace pagmo

PAGMO_REGISTER_PROBLEM(pagmo::schwefel)

#endif
