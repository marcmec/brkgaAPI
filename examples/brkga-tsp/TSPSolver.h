/*
 * TSPSolver.h
 *
 *  Created on: Mar 16, 2013
 *      Author: Rodrigo
 */

#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <vector>
#include <algorithm>
#include "TSPInstance.h"


class TSPSolver {
public:
	// The constructor 'solves' the problem in O(n log n) by transforming the chromosome into
	// a tour (by getting a permutation out of the chromosome):
	TSPSolver(const TSPInstance& instance, const std::vector< double >& chromosome);
	virtual ~TSPSolver();
	unsigned tourSize;
	unsigned getTourDistance() const;		// Returns the tour distance
	std::list< unsigned > getTour() const;	// Returns the tour (first node not copied in the end)

	unsigned pegaDistancia(unsigned i, unsigned j);
private:
	typedef std::pair< double, unsigned > ValueKeyPair;

	unsigned distance;
	std::vector< ValueKeyPair > tour;

	
};

#endif
