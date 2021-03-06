# -*- coding: utf-8 -*-

# Copyright 2017 PaGMO development team
#
# This file is part of the PaGMO library.
#
# The PaGMO library is free software; you can redistribute it and/or modify
# it under the terms of either:
#
#   * the GNU Lesser General Public License as published by the Free
#     Software Foundation; either version 3 of the License, or (at your
#     option) any later version.
#
# or
#
#   * the GNU General Public License as published by the Free Software
#     Foundation; either version 3 of the License, or (at your option) any
#     later version.
#
# or both in parallel, as here.
#
# The PaGMO library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received copies of the GNU General Public License and the
# GNU Lesser General Public License along with the PaGMO library.  If not,
# see https://www.gnu.org/licenses/.

# for python 2.0 compatibility
from __future__ import absolute_import as _ai

# Plotting functions
def plot_non_dominated_fronts(points, marker = 'o', comp = [0,1]):
    """
    Plots the nondominated fronts of a set of points. Makes use of :class:`~pygmo.core.fast_non_dominated_sorting` to
    compute the non dominated fronts.

    Args:
        points (``array`` [or ``list``] of ``arrays`` [or ``lists``] of ``floats``): points to plot
        marker (``str``): matplotlib marker used to plot the *points*
        comp (``list``): Components to be considered in the two dimensional plot (useful in many-objectives cases)

    Returns:
        ``matplotlib.axes.Axes``: the current ``matplotlib.axes.Axes`` instance on the current figure

    Examples:
        >>> from pygmo import *
        >>> prob = problem(zdt())
        >>> pop = population(prob, 40)
        >>> ax = plot_non_dominated_fronts(pop.get_f())
    """
    from matplotlib import pyplot as plt
    from ..core import fast_non_dominated_sorting, population
    from numpy import linspace

    # We plot
    fronts, _, _, _ = fast_non_dominated_sorting(points)

    # We define the colors of the fronts (grayscale from black to white)
    cl = list(zip(linspace(0.1, 0.9, len(fronts)),
                  linspace(0.1, 0.9, len(fronts)),
                  linspace(0.1, 0.9, len(fronts))))

    for ndr, front in enumerate(fronts):
        # We plot the points
        for idx in front:
            plt.plot(points[idx][comp[0]], points[idx][comp[1]], marker = marker, color = cl[ndr])
        # We plot the fronts
        # Frist compute the points coordinates
        x = [points[idx][0] for idx in front]
        y = [points[idx][1] for idx in front]
        # Then sort them by the first objective
        tmp = [(a, b) for a, b in zip(x, y)]
        tmp = sorted(tmp, key=lambda k: k[0])
        # Now plot using step
        plt.step([c[0] for c in tmp], [c[1] for c in tmp], color=cl[ndr], where='post')

    plt.show()
    return plt.gca()
