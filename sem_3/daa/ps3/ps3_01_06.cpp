#include<bits/stdc++.h> 
using namespace std;

class Graph
{
protected:
    map<int, set<int>> adjacencyList;
public:
    void insert(int, set<int>);
    void display();
    void depthFirstTraversal();
    void BFS(int);
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

void Graph::BFS(int node)
{
    set<int> visited;
    queue<int> q;

    visited.insert(node);
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        cout << node << " ";
        q.pop();
        
        map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(node);
        for (int connectedNode : iteratorToSrc->second){
            if(visited.find(connectedNode) == visited.end()){
                visited.insert(connectedNode);
                q.push(connectedNode);
            }
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
