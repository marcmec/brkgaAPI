/*
 * TSPInstance.cpp
 *
 *  Created on: Mar 16, 2013
 *      Author: Rodrigo
 */

#include "TSPInstance.h"
#include "TSPSolver.h"
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

TSPInstance::TSPInstance(const std::string& instanceFile) throw(TSPInstance::Error){ 
    //9 para 3x3 e 16 para 4x4
   

    readFile.open(instanceFile);
    if(readFile){
        while (getline(readFile,inputs))
        {
            conver = (double)(stoi(inputs));
            listOfPositions.push_back(conver);
        }
	readFile.close();

    }
    else{
        cout<< "incorrect name file or do not exists"<< endl;
    }
    

		std::list<unsigned>:: iterator iteratorBrkga;

		listOfVertices = new list<unsigned> [16];

        for(int i =0; i< listOfPositions.size();i++){
            v0 = listOfPositions[i];
            v1= listOfPositions[i+1];
            listOfVertices[v0].push_back(v1);
            listOfVertices[v1].push_back(v0);
            listOfPositions.erase(listOfPositions.begin(), listOfPositions.begin()+1);
        }
    
    xI.push_back(0);
    xI.push_back(3);
    xI.push_back(15);
    xI.push_back(12);
   
}
    
TSPInstance::~TSPInstance() { }

unsigned TSPInstance::getDistance(unsigned i, unsigned j)const{
    vector<vector<unsigned> > listaVectors;
	list<unsigned>:: iterator findPathForAgv;
    queue<unsigned> backTrack;
    bool agvVisit[16];
    for(unsigned i=0;i<16;i++)
    agvVisit[i]=false;
	unsigned getTargetAgv=9;	
	vector<unsigned> listAgvVisited;
    unsigned something=0;
	listAgvVisited.push_back(something);
	agvVisit[something]=true;
	 while(true){ 
        for(findPathForAgv= listOfVertices[something].begin();findPathForAgv!= listOfVertices[something].end();findPathForAgv++){
            if(!agvVisit[*findPathForAgv] && *findPathForAgv!=getTargetAgv && *findPathForAgv != j){
                agvVisit[*findPathForAgv]=true;
                listAgvVisited.push_back(*findPathForAgv);
                backTrack.push(*findPathForAgv);
            }
            listaVectors.push_back(listAgvVisited);
        }
        if(!backTrack.empty()){
            something=backTrack.front();
            backTrack.pop();
        }else{

            break;
            }

    	}
        const unsigned k= listaVectors[i].size();
        

    return k;

}