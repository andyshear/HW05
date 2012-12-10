//MatrixGraph.cpp


#include "ListGraph.h"

using namespace std;
//References regojr's ListGraph(unsigned num_nodes) method
ListGraph::ListGraph(int num_nodes){
	num_edges = 0;
	edgeList.resize(num_nodes);
}

ListGraph::~ListGraph(){

}
//References regojr's addEdge method
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
	if(0<=edgeList[u].size() && 0<=edgeList[v].size()){
		if(u!=v){
			if(0<weight){
				EList::iterator it;
				bool match = false;
				for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
					NWPair edge = *it;
					if(edge.first == v){
						match = true;
					}
				}
				if(!match){
					edgeList[u].push_front(NWPair(v,weight));
					edgeList[v].push_front(NWPair(u,weight));
					num_edges++;
				}
			}			
		}
	}
}
//References regojr's weight method
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	if(0<=edgeList[u].size() && 0<=edgeList[v].size()){
		EList::const_iterator it;
		for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
			NWPair edge = *it;
			if(edge.first == v)
				return edge.second;
		}
	}
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	std::list<NWPair> pair = edgeList[u];	
	return pair;
}

unsigned ListGraph::degree(NodeID u) const{
	std::list<NWPair> pair;
	pair = getAdj(u);
	int neighbors = pair.size();
	return neighbors;
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}

