#include "MatrixGraph.h"
#include "ListGraph.h"
#include "GraphAlgs.h"
#include <algorithm>

using namespace std;

double sortList(std::vector<std::vector<EdgeWeight>> temp, int size, int i, int j){
	double shortest = 0.0;	
	std::sort(temp[i].begin(),temp[i].end());
	shortest = temp[i][j];
	
	return shortest;
}
void bestPath(std::vector<std::vector<EdgeWeight>> temp, int size){
	
	ID.resize(size*size);
	int l = 0;
	for(int i = 0; i<size; i++){
		
		for(int k = 0; k<size; k++){
			int j = 1;			
			while(temp[i][j] != sortList(temp,size,i,k)){
				j++;
			}
			ID[l] = pairs1(i,j);
			l++;			
		}
	}
	int len = l;
	for(int i = 0; i<size; i++){
		
	}
}
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	int size = G->size();
	int edges = G->numEdges();
	
	std::vector<std::vector<EdgeWeight>> temp;
	std::vector<std::vector<EdgeWeight>> temp1;
	temp.resize(size,std::vector<EdgeWeight>(size,0));
	temp1.resize(size,std::vector<EdgeWeight>(size,0));
	for(int i = 0; i<size; i++){
		EList::iterator j;
		double min = 0;
		double min1 = 0;
		std::list<NWPair> pairs = G->getAdj(i);
				
		for(j = pairs.begin(); j != pairs.end(); j++){			
			NWPair p1 = *j;
			temp[i][p1.first] = p1.second;
			temp1[i][p1.first] = p1.second;
		}		
	}
	int nodeNumber = 0;
	int depth = 1;
	sortList(temp,size,nodeNumber,depth);
	std::pair<std::vector<NodeID>, EdgeWeight> test;
	return test;
}

