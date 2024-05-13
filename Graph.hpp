/**
 * Roi Sibony
 * roisi20041@gmail.com
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
namespace ariel{
class Graph{
    private:
        int numOfEdges;
        std::vector<std::vector<int>> vec;
        int numOfVertices;
        bool directed;
    public:
        Graph();
        void loadGraph(const std::vector<std::vector<int>> &vec1);
        void printGraph() const;
        size_t getVertices() const;
        size_t getEdges() const;
        std::vector<std::vector<int>> getGraph() const;
        bool isDirected() const;
        // Mathematical operators
        void theBigIf(const ariel::Graph &g) const;

    Graph operator+(const Graph& other) const; // Adds two graphs together.
    
    Graph& operator+=(const Graph& other); // Adds another graph to this graph.
    
    Graph operator+() const; // Unary plus operator, returns a copy of the graph.
    
    Graph operator-(const Graph& other) const; // Subtracts another graph from this graph.
    
    Graph& operator-=(const Graph& other); // Subtracts another graph from this graph and assigns the result to this graph.
    
    Graph operator-() const; // Unary minus operator, returns the negation of the graph.

    // Comparison operators
    bool operator>(const Graph& other) const; // Checks if this graph is greater than another graph.
    
    bool operator>=(const Graph& other) const; // Checks if this graph is greater than or equal to another graph.
    
    bool operator<(const Graph& other) const; // Checks if this graph is less than another graph.
    
    bool operator<=(const Graph& other) const; // Checks if this graph is less than or equal to another graph.
    
    bool operator==(const Graph& other) const; // Checks if this graph is equal to another graph.
    
    bool operator!=(const Graph& other) const; // Checks if this graph is not equal to another graph.

    // Other operators
    Graph& operator++(); // Pre-increment operator, increments the graph by 1.
    
    Graph operator++(int); // Post-increment operator, increments the graph by 1.
    
    Graph& operator--(); // Pre-decrement operator, decrements the graph by 1.
    
    Graph operator--(int); // Post-decrement operator, decrements the graph by 1.
    
    Graph operator*(int scalar) const; // Multiplies the graph by a scalar.
    
    Graph operator*(const Graph& other) const; // Multiplies this graph by another graph.
};
}
#endif //GRAPH_H
