/*
 * TSPSolver.cpp
 *
 *  Created on: Mar 16, 2013
 *      Author: Rodrigo
 */

#include "TSPSolver.h"
#include <vector>
#include <list>
#include<vector>
#include <queue>
#include <time.h>
#include <iostream>
using namespace std;

TSPSolver::TSPSolver(const TSPInstance& instance, const std::vector< double >& chromosome) :
		distance(0), tour(instance.xI.size()) {
  

    for(unsigned i = 0; i < chromosome.size(); ++i) {tour[i] = ValueKeyPair(chromosome[i], instance.xI[i]);}
    std::sort(tour.begin(), tour.end());

    for(int i=1;i<tour.size();i++){

        const unsigned& first= tour[i-1].second;
        const unsigned& next= tour[i].second;

        distance+= instance.getDistance(first,next);

    }

}

TSPSolver::~TSPSolver() {}

unsigned TSPSolver::getTourDistance() const { return distance; }

std::list< unsigned > TSPSolver::getTour() const {
	std::list< unsigned > tourSequence;

	for(unsigned i = 0; i < tour.size(); ++i) { 
		
		tourSequence.push_back(tour[i].second); 

	}
	return tourSequence;
}


