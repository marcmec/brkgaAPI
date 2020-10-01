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
		distance(0), tour(instance.getSize()) {
		
    for(unsigned i = 0; i < chromosome.size(); ++i) {tour[i] = ValueKeyPair(chromosome[i], i);}


	std::sort(tour.begin(), tour.end());

/*
	//se todos os agvs chegaram no alvo
	while(instance.finished()){

   		for(unsigned i=0;i<tour.size();i++){

			
			sol.roboWalk(tour[i].second);

   		}

	}

		distance+= sol.distanciapercorrida();
       */
}

TSPSolver::~TSPSolver() {}

unsigned TSPSolver::getTourDistance() const { return distance; } //distancia percorrida

std::list< unsigned > TSPSolver::getTour() const {
	std::list< unsigned > tourSequence;

	for(unsigned i = 0; i < tour.size(); ++i) { 
		
		tourSequence.push_back(tour[i].second); 

	}
	return tourSequence;
}


