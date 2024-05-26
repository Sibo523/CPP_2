### Personal Details
- *ID:* in txt file
- *Name:* Roi Sibony
- *Email:* roisi20041@gmail.com

# CPP_1

## Prerequisites

Before you begin, ensure you have met the following requirements:

- You have installed the latest version of Clang++ compiler.
- You have a basic understanding of C++ programming.

## Makefile Commands

The project uses a Makefile to automate the build process. Here are the main commands available:

- `make`: Builds the project.
- `make demo`: makes the demo exee
- `make test`: makes the test.
- `make run`: runs the demo exe (need to use after making the demo).
- `make tidy`: Runs clang-tidy on the source files to check for common issues.
- `make valgrind`: Runs Valgrind on both the demo and test executables to check for memory leaks.
- `make clean`: Cleans up the build artifacts by removing object files and executables.


## How to run the program
- `./demo`: runs the demo exe file.
- `./test`: Runs the test exe file.

## Graph Class Library
Welcome to the Graph Class Library, a comprehensive toolset for working with graphs in C++. Developed by Roi Sibony, this library offers extensive functionalities for creating, manipulating, and analyzing graphs, supporting both directed and undirected types.

Key Features
Graph Creation: Easily initialize graphs with a predefined number of vertices.
Graph Manipulation: Load graph structures from matrices, print graph details, and access graph properties such as vertex count, edge count, and directionality.
Arithmetic Operations: Perform addition, subtraction, multiplication, and division on graphs.
Comparison Operators: Compare graphs to determine equality, inequality, and relative ordering.
Increment/Decrement Operators: Modify graphs through increment and decrement operations.
Stream Output: Utilize overloaded output stream operators for straightforward graph visualization.
Quick Start
To begin using the Graph Class Library in your project, follow these simple steps:

1. Include the Library: Add the graph.h header file to your source code.
```
#include "graph.h"
```
2. Initialize a Graph: Create a new graph object with a specified number of vertices.

```
ariel::Graph myGraph(5); // Initializes a graph with 5 vertices.
```
3. Load Graph Data: Populate the graph using a matrix representation.
```
std::vector<std::vector<int>> adjacencyMatrix = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
myGraph.loadGraph(adjacencyMatrix);
```
4. Perform Operations: Apply various operations to manipulate and analyze the graph.
```
ariel::Graph anotherGraph(3);
anotherGraph.loadGraph({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}});

ariel::Graph combinedGraph = myGraph + anotherGraph; // Combines two graphs.
```
5. Print the Graph: Display the graph's structure using the overloaded output stream operator.
```
std::cout << combinedGraph << std::endl;
```
## Example
```
#include "graph.h"

int main() {
    ariel::Graph graphA(3);
    graphA.loadGraph({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}});

    ariel::Graph graphB(3);
    graphB.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

    ariel::Graph sumGraph = graphA + graphB;
    std::cout << "Sum of Graph A and Graph B:\n" << sumGraph << std::endl;

    return 0;
}
```

# Algorithms

`Algorithms` class withing the `ariel` namespace, offering a suite of static Algorithms that can be applied on the Graph object.
The funtions withing this file, checks connectivity, cycle detetion, shortest path calculation, bipartitennes groups and negative cycle determention.

## Class Overview

The `Algorithms` class encapsulates a collection of static methods that operate on instances of the `Graph` class. These methods leverage graph theory concepts to solve common problems in graph analysis and manipulation.

## Public Methods

### `isConnected(Graph g)`

- **Description**: Checks if the given graph `g` is connected.
- **Return Type**: `int`
- **Parameters**: A reference to a `Graph` object `g`.
- **Usage**: To determine if all nodes in the graph are reachable from each other.

### `isContainsCycle(const Graph &g)`

- **Description**: Determines if the graph `g` contains a cycle.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`.
- **Usage**: To check for the presence of a cycle in the graph.

### `shortestPath(const Graph &g, size_t des, size_t src)`

- **Description**: Finds the shortest path between the source node `src` and the destination node `des` in the graph `g`.
- **Return Type**: `std::string`
- **Parameters**: A constant reference to a `Graph` object `g`, and two `size_t` values representing the source and destination nodes.
- **Usage**: To find the shortest path between two nodes in the graph.

### `isBipartite(const Graph &g)`

- **Description**: Checks if the graph `g` is bipartite.
- **Return Type**: `std::string`
- **Parameters**: A constant reference to a `Graph` object `g`.
- **Usage**: To determine if the graph can be divided into two disjoint sets where every edge connects a node in one set to a node in the other set.

### `negativeCycle(const Graph &g)`

- **Description**: Identifies if the graph `g` contains a negative cycle.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`.
- **Usage**: To detect the presence of a negative cycle in the graph.

## Private Methods

### `dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<bool> &recStack, size_t vertex, size_t parent, std::string &result)`

- **Description**: Helper method for depth-first search (DFS) to detect cycles.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`, vectors for visited nodes and recursion stack, a vertex, a parent vertex, and a result string.
- **Usage**: Internally used by `isContainsCycle` to perform DFS and detect cycles.

### `dfs(const Graph &g, std::vector<bool> &visited, size_t vertex)`

- **Description**: Depth-first search traversal of the graph `g`.
- **Return Type**: `void`
- **Parameters**: A constant reference to a `Graph` object `g`, a vector for visited nodes, and a vertex.
- **Usage**: Used internally for various graph traversal needs.

### `makeSymmetric(Graph &g)`

- **Description**: Makes the graph `g` symmetric by adding missing edges.
- **Return Type**: `void`
- **Parameters**: A reference to a `Graph` object `g`.
- **Usage**: Ensures that the graph is fully connected by adding any missing edges.

### `isSameColor(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v)`

- **Description**: Checks if two nodes have the same color in a colored graph.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`, a vector of colors, and two node indices `u` and `v`.
- **Usage**: Used internally for bipartiteness checks.

### `isSelfLoop(const Graph &g, size_t u)`

- **Description**: Checks if a node has a self-loop in the graph.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g` and a node index `u`.
- **Usage**: Used internally for certain graph validations.

### `isNotColored(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v)`

- **Description**: Checks if two nodes are not colored in a colored graph.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`, a vector of colors, and two node indices `u` and `v`.
- **Usage**: Used internally for bipartiteness checks.

### `BelmanFord(const Graph &g, size_t srcm, size_t des)`

- **Description**: Implements the Bellman-Ford algorithm to find the shortest path between `srcm` and `des` in the graph `g`.
- **Return Type**: `std::string`
- **Parameters**: A constant reference to a `Graph` object `g`, and two `size_t` values representing the source and destination nodes.
- **Usage**: To find the shortest path between two nodes using the Bellman-Ford algorithm.


