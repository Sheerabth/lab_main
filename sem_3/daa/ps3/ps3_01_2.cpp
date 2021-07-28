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
    int deg;
    cout << "Enter the degree";
    cin >> deg;
    set<int> result = G.verticesWithDegree(deg);
    cout << "The adjacent vertices are\n";
    for (auto vertex : result)
        cout << vertex; 
    cout << endl;
}