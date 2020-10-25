#include<bits/stdc++.h> 
using namespace std;

class Graph
{
protected:
    map<int, set<int>> adjacencyList;
public:
    void insert(int, set<int>);
    void display();
    set<int> findVertexOfDegree(int);
};

void Graph::insert(int value, set<int> connectedNodes)
{
    map<int, set<int>>::iterator iterator = adjacencyList.find(value);
    if (iterator == adjacencyList.end())
        adjacencyList.insert(pair<int, set<int>>(value, connectedNodes));
    else
        iterator->second.insert(connectedNodes.begin(),connectedNodes.end());
    
    set<int>::iterator connectedNode = connectedNodes.begin();
    for (int connectedNode: connectedNodes)
    {
        map<int, set<int>>::iterator iterator = adjacencyList.find(connectedNode);
        if (iterator != adjacencyList.end())
            iterator->second.insert(value);
        else{
            set<int> connected({value});
            adjacencyList.insert(pair<int, set<int>>(connectedNode, connected));
        }
    }
}

void Graph :: display() {
    map<int, set<int>> :: iterator mapItr = adjacencyList.begin();
    for (pair<int, set<int>> mapItr : adjacencyList) {
        cout << mapItr.first << " ";
        set<int> :: iterator setItr = mapItr.second.begin();
        for (int setItr : mapItr.second)
            cout << setItr << " ";
        cout << endl;
    }
}

set<int> Graph :: findVertexOfDegree(int degree) {
    set<int> vertices;
    map<int, set<int>> :: iterator mapItr= adjacencyList.begin();
    for (pair<int, set<int>> mapItr : adjacencyList) {
        if (mapItr.second.size() == degree)
            vertices.insert(mapItr.first);
    }

    if (!vertices.size()) {
        cout << "Degree not found in graph\n";
        exit(-1);
    }

    return vertices;
}

int main() {
    Graph G;
    int vertex, adj;
    vertex = 0;
    while (true) {
        cout << "Enter the vertex: ";
        cin >> vertex;
        if (vertex == -1)
            break;
        cout << "Enter the adjacent vertices\n";
        set<int> adjVertices;
        adj = 0;
        while (true) {
            cin >> adj;
            if (adj == -1)
                break;
            adjVertices.insert(adj);
        }
        G.insert(vertex, adjVertices);
    }
        
    cout << "Enter the degree to be searched: ";
    cin >> vertex;
    set<int> vertices = G.findVertexOfDegree(vertex);
    cout << "The vertices with the degree are\n";
    set<int> :: iterator itr = vertices.begin();
    for (int itr : vertices)    
        cout << itr << " ";
    cout << endl;
    cout << "The adjacency list:\n";
    G.display();
}