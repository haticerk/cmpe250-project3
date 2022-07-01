#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstring>
#include <queue>

using namespace std;

class Vertex{
public:
	int inDegree=0;
	int outDegree;
	list<int> edges;
	Vertex(){
	}
};

list<int> verWithNonUsedEdge(vector<Vertex>& vertexes, vector<int>& circuit){
	list<int> nums;

	for(int i=1; i<circuit.size(); i++){
		if(!vertexes[circuit[i]].edges.empty()){
			nums.push_back(circuit[i]);
			nums.push_back(i);
			break;
		}
	}
	return nums;
}

int findCircuit(int& startPoint, vector<Vertex>& vertexes, vector<int>& circuit){
	while(!vertexes[startPoint].edges.empty()){
		circuit.push_back(startPoint);

		int next = vertexes[startPoint].edges.front();
		vertexes[startPoint].edges.pop_front();

		startPoint = next;
	}
	circuit.push_back(startPoint);
	return 0;
}

bool isEulerian(vector<Vertex>& vertexes, int vertex){
	for(int i=0; i<vertex; i++){
		int outDegree = vertexes[i].outDegree;
		int inDegree = vertexes[i].inDegree;

		if(inDegree!=outDegree){
			return false;
		}
	}
	return true;
} 

int main(int argc, char const *argv[]){

	ifstream inputFile;
	inputFile.open(argv[1]);

	int vertex;
	inputFile >> vertex;

	int totalLength=1;

	vector<Vertex> vertexes(vertex);
	for(int i=0; i<vertex; i++){
		int id, outDegree;
		
		inputFile >> id >> outDegree;
		totalLength += outDegree;

		vertexes[i].outDegree = outDegree;
		for(int k=0; k<outDegree; k++){
			int edge; 
			inputFile >> edge;
			
			vertexes[i].edges.push_back(edge);
			vertexes[edge].inDegree++;
		}
	}

	int startPoint;
	inputFile >> startPoint;
	inputFile.close();

	ofstream outputFile;
	outputFile.open(argv[2]);

	if(isEulerian(vertexes, vertex)){
		vector<int> circuit;
		findCircuit(startPoint, vertexes, circuit);
		while(circuit.size()!=totalLength){
			list<int> nonUsed = verWithNonUsedEdge(vertexes, circuit);
			int vertex = nonUsed.front();
			int i = nonUsed.back();
			
			int next = vertexes[vertex].edges.front();
			vertexes[vertex].edges.pop_front();

			vector<int> tour;
			findCircuit(next, vertexes, tour);

			circuit.insert(circuit.begin()+i+1, tour.begin(), tour.end());
		}	
		for(int i=0; i<totalLength; i++){
			outputFile << circuit[i] << " " ;
		}
	}else{
		outputFile << "no path" << endl;
	}
	outputFile.close();
	return 0;
}
