/*
 * TSPInstance.h
 *
 * Reads an instance from TSPLIB (Symmetric TSP).
 *
 * Here's the URL: http://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/tsp/
 *
 * Here's the format:
 *
 * NAME : a280
 * COMMENT : drilling problem (Ludwig)
 * TYPE : TSP
 * DIMENSION: 280
 * EDGE_WEIGHT_TYPE : EUC_2D
 * NODE_COORD_SECTION
 * 1 288 149
 * 2 288 129
 * 3 270 133
 * 4 256 141
 * ...
 * EOF
 *
 *  Created on: Mar 16, 2013
 *      Author: Rodrigo
 */

#ifndef TSPINSTANCE_H
#define TSPINSTANCE_H

#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <list>
#include <math.h>
#include <queue>
#include "TSPInstance.h"

using namespace std;

class TSPInstance {
public:
	typedef std::runtime_error Error;

	TSPInstance(const std::string& instanceFile) throw(Error);
	virtual ~TSPInstance();
	// Getters:
		vector<unsigned> xI;
		std::list<unsigned>* listOfVertices;
		std::vector<unsigned> listOfPositions;
		unsigned getDistance(unsigned i, unsigned j) const;
private:
	std::string inputs,file;
    std::fstream readFile;
	unsigned v0,v1;
	double conver;	
  
};

#endif
