#include "graph.hpp"

int main() {
    Graph G;
    int noOfVertices, vertex;
    cout << "Enter the number of nodes: ";
    cin >> noOfVertices;
    for (int i=0; i < noOfVertices; i++) {
        cout << "Enter the vertex value: ";
        cin >> vertex;
        int noOfAdjacentVertices;
        cout << "Enter the number of adjacent vertices: ";
        cin >> noOfAdjacentVertices;
        set<EdgeTo> setTemp;
        int adjVertex, weight;
        cout << "Enter the adjacent vertices: \n";
        for (int j=0; j < noOfAdjacentVertices; j++) {
            cin >> adjVertex >> weight;
            EdgeTo edgeTemp(adjVertex, weight);
            setTemp.insert(edgeTemp);
        }
        G.Insert(vertex, setTemp);
    }
    int val;
    cout << "Enter the vertex whose adjacent vertex is to be found: ";
    cin >> val;
    set<EdgeTo> result = G.returnAdjacentVertices(val);
    for (auto adjacentVertex : result) {
        cout << "(" << adjacentVertex.value << ","<< adjacentVertex.weight << "), ";
    }
    cout << endl;
}