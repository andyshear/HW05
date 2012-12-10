//MatrixGraph.cpp


#include "MatrixGraph.h"

using namespace std;
//References regojr's MatrixGraph(unsigned num_nodes) method
MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	M.resize(num_nodes,std::vector<EdgeWeight>(num_nodes,0));
}

MatrixGraph::~MatrixGraph(){

}
//Reverences anglessw's addEdge
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
	if(0<=M[u].size() && 0<=M[v].size()){
		if(u!=v){
			if(0<weight){
				if(M[u][v] == 0){
					M[u][v] = weight;
					M[v][u] = weight;
					num_edges++;
				}				
			}			
		}
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	if(0<=M[u].size() && 0<=M[v].size()){
		return M[u][v];
	}
	return 0.0;
}
//References regojr's getAdj method
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair> pair;
	std::vector<EdgeWeight>::const_iterator it;
	int nID = 0;
	for(it=M[u].begin(); it<M[u].end(); it++){
		if(*it != 0.0){
			pair.push_front(NWPair( nID, *it));
		}
		nID++;
	}
	return pair;
}

unsigned MatrixGraph::degree(NodeID u) const{
	std::list<NWPair> pair;
	pair = getAdj(u);
	int neighbors = pair.size();
	return neighbors;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

