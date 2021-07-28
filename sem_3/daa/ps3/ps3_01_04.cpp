#include<bits/stdc++.h> 
using namespace std;

class Graph
{
protected:
    map<int, set<int>> adjacencyList;
public:
    void insert(int, set<int>);
    void display();
    bool hasPath(int, int);
    bool hasPath(int, int, set<int>& checked);
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

bool Graph :: hasPath(int source, int destination) {
    set<int> visited;
    bool isConnected = hasPath(source, destination, visited);
    return isConnected;
}

bool Graph :: hasPath(int source, int destination, set<int>& visited) {
    map<int, set<int>> :: iterator mapPos = adjacencyList.find(source);
    for (int connectedNode : mapPos->second) {
        if (connectedNode == destination)
            return true;
        else {
            if (visited.find(connectedNode) == visited.end()) {
                visited.insert(connectedNode);
                if (hasPath(connectedNode, destination, visited))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    Graph G;
    int vertex, adj;
    int source, destination;
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
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;
    if (G.hasPath(source, destination)) 
        cout << "It has path\n";
    else 
        cout << "It does'nt have path\n";
    cout << "The adjacency list:\n";
    G.display();
}