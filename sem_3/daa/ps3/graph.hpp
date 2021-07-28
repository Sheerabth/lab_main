#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

class Graph;

class EdgeTo {
    public:

    int value, weight;
    friend class Graph;
    EdgeTo(int v, int w) : value(v), weight(w) {}
    friend bool operator < (const EdgeTo first, const EdgeTo second) {
        return first.weight < second.weight;
    }
    friend bool operator==(const EdgeTo one, const EdgeTo two)
    {
        return one.weight == two.weight && one.value == two.value;
    }
};

class Graph {
    map<int, set<EdgeTo>> adjacencyLists;
    static void makeset(map<int, set<int>> &sets, int srcRep, int destRep);
    static void joinSets(map<int, set<int>> &, int srcRep, int destRep);
    public:
        void Insert(int, set<EdgeTo>);
        set<EdgeTo> returnAdjacentVertices(int);
        set<int> verticesWithDegree(int);
        int totalDegree();
        bool hasPath(int, int);
        bool hasPathTo(int, int, set<int>&);
        void BFS(int);
        void DFS(int);
        set<int> allNodes();
        Graph kruskalMinSpanTree();
        Graph Djikstras(int);
        void Display();
};

set<int> Graph::allNodes()
{
    set<int> nodes;
    for (auto node : adjacencyLists)
    {
        nodes.insert(node.first);
    }
    return nodes;
}

void Graph :: Insert (int value, set<EdgeTo> connectedNodes) {
    map<int, set<EdgeTo>> :: iterator iterator = adjacencyLists.find(value);
    
    if (iterator == adjacencyLists.end())
        adjacencyLists.insert(pair<int, set<EdgeTo>>(value, connectedNodes));
    else 
        iterator->second.insert(connectedNodes.begin(), connectedNodes.end());

    for (EdgeTo connectedVertex : connectedNodes) {
        map<int, set<EdgeTo>> :: iterator iterator = adjacencyLists.find(connectedVertex.value);
        if (iterator == adjacencyLists.end()) {
            set<EdgeTo> connected;
            connected.insert({value, connectedVertex.weight});
            adjacencyLists.insert(pair<int, set<EdgeTo>>(connectedVertex.value, connected));
        } 
        else
            iterator->second.insert({value, connectedVertex.weight});

    }
}

set<EdgeTo> Graph :: returnAdjacentVertices(int value) {
    map<int, set<EdgeTo>> :: iterator iterator = adjacencyLists.find(value);
    if (iterator == adjacencyLists.end()) 
        return set<EdgeTo>();
    else
        return iterator->second;
}

set<int> Graph :: verticesWithDegree(int degree) {
    set<int> verticesMatchingDegree;

    for (pair<int, set<EdgeTo>> keyValuePair : adjacencyLists) {
        if (keyValuePair.second.size() == degree)
            verticesMatchingDegree.insert(keyValuePair.first);
    }

    return verticesMatchingDegree;
}

int Graph :: totalDegree() {
    int total = 0;
    for (pair<int, set<EdgeTo>> keyValuePair : adjacencyLists) {
        total += keyValuePair.second.size();
    }

    return total;
}

void Graph :: BFS(int node) {
    set<int> visited;
    queue<int> q;

    visited.insert(node);
    q.push(node);

    while (!q.empty()) {
        node = q.front();
        cout << node << " ";
        q.pop();

        map<int, set<EdgeTo>> :: iterator iteratorToSrc = adjacencyLists.find(node);
        for (EdgeTo connectedVertex : iteratorToSrc->second) {
            if (visited.find(connectedVertex.value) == visited.end()) {
                visited.insert(connectedVertex.value);
                q.push(connectedVertex.value);
            }
        }
    }
}

void Graph :: DFS(int node) {
    set<int> visited;
    stack<int> s;

    visited.insert(node);
    s.push(node);

    while (!s.empty()) {
        node = s.top();
        cout << node << " ";
        s.pop();

        map<int, set<EdgeTo>> :: iterator iteratorToSrc = adjacencyLists.find(node);
        for (EdgeTo connectedVertex : iteratorToSrc->second) {
            if (visited.find(connectedVertex.value) == visited.end()) {
                visited.insert(connectedVertex.value);
                s.push(connectedVertex.value);
            }
        }
    }
}

bool Graph::hasPathTo(int src, int dest, set<int> &visited)
{
    map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyLists.find(src);
    for (EdgeTo connectedVertex : iteratorToSrc->second)
    {
        if (connectedVertex.value == dest)
            return true;
        else
        {
            if (visited.find(connectedVertex.value) == visited.end())
            {
                visited.insert(connectedVertex.value);
                if (hasPathTo(connectedVertex.value, dest, visited))
                    return true;
            }
        }
    }
    return false;
}

bool Graph::hasPath(int src, int dest)
{
    set<int> visited;
    bool isConnected = hasPathTo(src, dest, visited);
    return isConnected;
}

Graph Graph::kruskalMinSpanTree()
{
    // List of all edges to be considered
    list<pair<int, EdgeTo>> allEdges;

    // Inserting all edges into the list
    for (auto adjacencyList : adjacencyLists)
    {
        for (EdgeTo edge : adjacencyList.second)
        {
            // Insert one direction(due to Raz's implementation of AdajencyLists)
            if (find(allEdges.begin(), allEdges.end(), pair<int, EdgeTo>(edge.value, {adjacencyList.first, edge.weight})) == allEdges.end())
                allEdges.push_back(pair<int, EdgeTo>(adjacencyList.first, edge));
        }
    }

    // Sorting the edges with a lambda funtion based on weight of edge
    allEdges.sort([](const std::pair<int, EdgeTo> &left, const std::pair<int, EdgeTo> &right) {
        return left.second < right.second;
    });

    // A map to store the resulting minimum spanning tree
    Graph minSpanTree;

    // Return if we have no edges
    if (allEdges.size() == 0)
        return minSpanTree;

    // Union-find:

    // A map to store all the representatives as keys and elements in the sets
    map<int, set<int>> sets;

    // Trying to insert each edge
    for (auto srcAndEdge : allEdges)
    {
        // Finding the reps
        int srcRep = -1, destRep = -1;
        for (auto setWithKey : sets)
        {
            std::set<int>::iterator it;

            it = setWithKey.second.find(srcAndEdge.first);
            if (it != setWithKey.second.end() && srcRep == -1)
                srcRep = setWithKey.first;

            it = setWithKey.second.find(srcAndEdge.second.value);
            if (it != setWithKey.second.end())
                destRep = setWithKey.first;

            if (srcRep != -1 && destRep != -1) // To avoid extra checks
                break;
        }
        // If both reps are same, do nothing
        if (srcRep == destRep)
        {
            // If we dont have both reps(which are same), we make a new set and insert both nodes and insert into MinSapntree
            if (srcRep == -1 && destRep == -1)
            {
                makeset(sets, srcAndEdge.first, srcAndEdge.second.value);
                minSpanTree.Insert(srcAndEdge.first, {srcAndEdge.second});
            }
        }
        else
        {
            // Insert the edge into Minspann tree as it remains same for all cases
            minSpanTree.Insert(srcAndEdge.first, {srcAndEdge.second});

            // No source rep, then add node to the set of destination rep
            if (srcRep == -1)
                sets.find(destRep)->second.insert(srcAndEdge.first);
            // The inverse of above
            else if (destRep == -1)
                sets.find(srcRep)->second.insert(srcAndEdge.second.value);
            // If both have reps, then merge the sets
            else
                joinSets(sets, srcRep, destRep);
        }
    }

    return minSpanTree;
}

void Graph::makeset(map<int, set<int>> &sets, int srcRep, int destRep)
{
    sets.insert(pair<int, set<int>>(srcRep, {srcRep, destRep}));
}

void Graph::joinSets(map<int, set<int>> &sets, int srcRep, int destRep)
{
    std::map<int, set<int>>::iterator src = sets.find(srcRep);
    std::map<int, set<int>>::iterator dest = sets.find(destRep);

    src->second.insert(dest->second.begin(), dest->second.end());
    sets.erase(dest);
}

Graph Graph::Djikstras(int sourceVertex)
{
    // Graph to store the resulting MinSpanTree, other Data structures -> complicated(coz no direction btw nodes)
    Graph shortestDistanceTree;
    // Map (int to int), key->node and value->weight from source(total weight), for nodes which are shortestDistanceTree
    map<int, int> nodesWithTotalWeight;

    // Insert sourceVertex
    shortestDistanceTree.Insert(sourceVertex, {});
    nodesWithTotalWeight.insert(pair<int, int>(sourceVertex, 0));

    // Terminate loop when all nodes are added into the shortestDistanceTree
    while (shortestDistanceTree.allNodes() != this->allNodes())
    {
        // Temporary map to select the edge with minimum totalWeight to a node
        map<int, pair<int, int>> shortDistList;

        
        for (int nodeToCheckEdges : shortestDistanceTree.allNodes())
        {
            // Checking all edges from a node present in graph
            set<EdgeTo> connectedEdges = this->returnAdjacentVertices(nodeToCheckEdges);

            for (auto connectedEdge : connectedEdges)
            {
                // Check if a edge should be inserted if its not connected to a node in graph
                if (nodesWithTotalWeight.find(connectedEdge.value) == nodesWithTotalWeight.end())
                {
                    // Calculate the totalWeight from source vertex
                    int totalWeight = nodesWithTotalWeight.find(nodeToCheckEdges)->second + connectedEdge.weight;
                    pair<int, int> nodeWithWeight = pair<int, int>(nodeToCheckEdges, totalWeight);

                    // Insert into shortDistList if we dont have a entry
                    if (shortDistList.find(connectedEdge.value) == shortDistList.end())
                        shortDistList.insert(pair<int, pair<int, int>>(connectedEdge.value, nodeWithWeight));

                    else
                    {
                        // If we have a entry, compare the weight, place the smallest one into shortDistList
                        auto nodeToCheck = shortDistList.find(connectedEdge.value);
                        if (totalWeight < nodeToCheck->second.second)
                            shortDistList.find(connectedEdge.value)->second = nodeWithWeight;
                    }
                }
            }
        }

        // List the edge with minimum totalWeight from the list of possible connections
        pair<int, int> keyWithtotalWeight = pair<int, int>(-1, 10000);
        for (auto keyPair : shortDistList)
        {
            if (keyPair.second.second < keyWithtotalWeight.second)
                keyWithtotalWeight = pair<int, int>(keyPair.first, keyPair.second.second);
            
        }
        // Insert it into the Graph and add its totalWeight
        if (keyWithtotalWeight.second != 10000)
        {
            nodesWithTotalWeight.insert(keyWithtotalWeight);
            shortestDistanceTree.Insert(
                shortDistList.find(keyWithtotalWeight.first)->second.first,
                 {{keyWithtotalWeight.first, keyWithtotalWeight.second - nodesWithTotalWeight.find(shortDistList.find(keyWithtotalWeight.first)->second.first)->second}});
        }
    }

    return shortestDistanceTree;
}

void Graph :: Display() {
    for (auto adjacencyList: adjacencyLists) {
        cout << adjacencyList.first << ": ";
        for (auto adjacentVertex : adjacencyList.second) {
            cout << "(" << adjacentVertex.value << ","<< adjacentVertex.weight << "), ";
        }
        cout << endl;
    }
}