/**
 * Roi Sibony
 * roisi20041@gmail.com
*/
#include "Graph.hpp" // Include the header file
// bro says that if we can give refrence to something is optimize cause than we don't need to copy it 

namespace ariel {

// Constructor
Graph::Graph() : numOfEdges(0), numOfVertices(0), directed(false) {
    // Initialize vec with an empty vector
    vec = std::vector<std::vector<int>>();
}

// Load graph from a 2D vector
void Graph::loadGraph(const std::vector<std::vector<int>> &vec1) {
    //might won't work  cause we never intilized numOfVertices
    if (!vec1.empty() &&  vec1.size() != vec1[0].size()) { // means that this is not a square matrix
        
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix." );

        return;
    }
    vec = vec1;
    numOfVertices = vec1.size();
    numOfEdges = 0; // Reset numOfEdges before counting
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] != 0) {
                numOfEdges++;
            }
        }
    }
    // check if it's exactly semtric if so then it's undirected
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] != vec[j][i]) {
                directed = true;
                return;
            }
        }
    }
    numOfEdges /= 2; // Divide by 2 because the graph is undirected
}

// Print the graph
void Graph::printGraph() const{
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout<<"Graph with "<<numOfVertices<<" vertices and "<<numOfEdges<<" edges.\n";
}

// Get the number of vertices
size_t Graph::getVertices() const{
    return (size_t)numOfVertices;
}

// Get the number of edges
size_t Graph::getEdges()const {
    return (size_t)numOfEdges;
}

// Get the graph
std::vector<std::vector<int>> Graph::getGraph() const {
    return vec;
}
bool Graph::isDirected()const{
    return directed;
}
//Matala 2 
void Graph::theBigIf(const Graph& g) const{
    if (numOfVertices != g.numOfVertices) {
        throw std::invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }
}

// Overload the + operator
Graph Graph::operator+(const Graph& other) const {
    theBigIf(other);

    std::vector<std::vector<int>> newVec = vec;
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            newVec[i][j] += other.vec[i][j];
        }
    }
    Graph newGraph;
    newGraph.loadGraph(newVec);
    return newGraph;
}
// Overload the += operator
Graph& Graph::operator+=(const Graph& other) {
    theBigIf(other);
    
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            vec[i][j] += other.vec[i][j];
        }
    }
    loadGraph(vec);
    return *this;
}
// Overload the + unary operator
Graph Graph::operator+() const { // litterly does nothing
    return *this; // return copy of the original graph
}
// Overload the - operator
Graph Graph::operator-(const Graph& other) const { //negates the value[i][j] and insert to new Vec
    theBigIf(other);
    std::vector<std::vector<int>> newVec = vec;
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            newVec[i][j] -= other.vec[i][j]; //new = me - other (it's me - other because I copied into newVec)
        }
    }
    Graph newGraph;
    newGraph.loadGraph(newVec); // create teh graph and return it
    return newGraph;
}
// Overload the -= operator
Graph& Graph::operator-=(const Graph& other) {
    theBigIf(other);
    
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            vec[i][j] -= other.vec[i][j];
        }
    }
    loadGraph(vec);
    return *this;
}
// Overload the - unary operator
Graph Graph::operator-() const {
    std::vector<std::vector<int>> newVec = vec; //copy the vec
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            newVec[i][j] = -newVec[i][j]; //put the minus of all the values
        }
    }
    Graph newGraph;
    newGraph.loadGraph(newVec);
    return newGraph;
}
// Overload the > operator
bool Graph::operator>(const Graph& other) const {

    if(numOfVertices <= other.numOfVertices){ // !>
        return false; // I cannot be large with less vertices
    }
    bool lemur = false;
    for (size_t i = 0; i < numOfVertices; ++i) {
        
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] <= other.vec[i][j]) {
                return false;
            }
        }
        
    }
}
// Overload the >= operator
bool Graph::operator>=(const Graph& other) const {
    return numOfVertices >= other.numOfVertices;
}
// Overload the < operator
bool Graph::operator<(const Graph& other) const {
    return numOfVertices < other.numOfVertices;
}
//need to fix
// Overload the <= operator
bool Graph::operator<=(const Graph& other) const {
    return numOfVertices <= other.numOfVertices;
}
// Overload the == operator
bool Graph::operator==(const Graph& other) const {
    if(numOfVertices != other.numOfVertices)
    {
        return false;
    }
    
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] != other.vec[i][j]) {
                return false;
            }
        }
    }
}
// Overload the != operator
bool Graph::operator!=(const Graph& other) const {
    return numOfVertices != other.numOfVertices;
}
// Overload the ++ operator
Graph& Graph::operator++() {
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            vec[i][j]++;
        }
    }
    loadGraph(vec);
    return *this;
}
// Overload the ++ operator
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++*this;
    return temp;
}
// Overload the -- operator
Graph& Graph::operator--() {
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            vec[i][j]--;
        }
    }
    loadGraph(vec);
    return *this;
}
// Overload the -- operator
Graph Graph::operator--(int) {
    Graph temp = *this;
    --*this;
    return temp;
}
// Overload the * operator
Graph Graph::operator*(int scalar) const {
    std::vector<std::vector<int>> newVec = vec;
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            newVec[i][j] *= scalar;
        }
    }
    Graph newGraph;
    newGraph.loadGraph(newVec);
    return newGraph;
}
// Overload the * operator
Graph Graph::operator*(const Graph& other) const {
    std::vector<std::vector<int>> newVec = vec;
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            newVec[i][j] *= other.vec[i][j];
        }
    }
    Graph newGraph;
    newGraph.loadGraph(newVec);
    return newGraph;
}


} // namespace ariel
