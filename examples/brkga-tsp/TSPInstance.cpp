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
/*

código para maze 3x3
*/

TSPInstance::TSPInstance(const std::string& instanceFile) throw(TSPInstance::Error):distancia(0){ //9 para 3x3 e 16 para 4x4
    unsigned destiny=0;
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
        for(unsigned i=0;i<16;i++){
            visitNeightborn[i]=false;
        }
        visitNeightborn[destiny]=true;
        routeAgv.push_back(destiny);
        while(true){
            for(iteratorBrkga= listOfVertices[destiny].begin();iteratorBrkga!= listOfVertices[destiny].end();iteratorBrkga++){
                if(!visitNeightborn[*iteratorBrkga]&& destiny!= targetAgv0){
                    visitNeightborn[*iteratorBrkga]=true;
                    visitVertice0.push(*iteratorBrkga);
                    routeAgv.push_back(*iteratorBrkga);
                    distancia++;
                }
            }
            if(!visitVertice0.empty()){
                destiny=visitVertice0.front();
                visitVertice0.pop();  
            }
            else
            {
                break;
            }
         
        }

        for(int i=0;i<routeAgv.size();i++)
        cout<<routeAgv[i]<<" ";
    

}	

TSPInstance::~TSPInstance() { }

unsigned TSPInstance::getSize()const{ return routeAgv.size();}

unsigned TSPInstance::getDistance(unsigned i,unsigned j)const{
    
    const unsigned range= pow(routeAgv[i]-routeAgv[j],2.0);


    return range;
}
