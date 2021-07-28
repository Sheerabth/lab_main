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

    // G.Insert(0, {{1, 4}, {7, 8}});
    // G.Insert(1, {{2, 8}, {7, 11}});
    // G.Insert(7, {{6, 1}, {8, 7}});
    // G.Insert(2, {{8, 2}, {3, 7}, {5, 4}});
    // G.Insert(8, {{6, 6}});
    // G.Insert(6, {{5, 2}});
    // G.Insert(3, {{5, 14}, {4, 9}});
    // G.Insert(5, {{4, 10}});

    Graph H = G.kruskalMinSpanTree();
    H.Display();
}