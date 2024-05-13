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


# Graph

`Graph` class withing the `ariel` namespace, providing simple implemantion of adjancacy matriix to represent a Graph.

## Class Overview

The `Graph` class encapsulates the structure and operations of a graph. It includes methods for loading graph data, printing the graph, retrieving the number of vertices and edges, accessing the graph's adjacency matrix, and checking if the graph is directed.

## Class Members

### `Public methods`

- `numOfEdges`: Stores the number of edges in the graph.
- `vec`: A 2D vector representing the adjacency matrix of the graph.
- `numOfVertices`: Stores the number of vertices in the graph.
- `directed`: A boolean flag indicating whether the graph is directed.


### `Public members`

- `Graph()`: Default constructor initializes an empty graph.
- `loadGraph(const std::vector<std::vector<int>> vec1)`: Loads the graph from a 2D vector representation.
- `printGraph() const`: Prints the graph to the console.
- `getVertices() const`: Returns the number of vertices in the graph.
- `getEdges() const`: Returns the number of edges in the graph.
- `getGraph() const`: Returns the graph's adjacency matrix.
- `isDirected() const`: Returns whether the graph is directed.

## Usage

To use the `Graph` class, you need to include the header file in your source code and create instances of the `Graph` class. Here's a simple example demonstrating how to create a graph, add edges, and print it:

// Adding edges to the graph
graph.loadGraph({{0, 1}, {1, 2}, {2, 3}, {3, 0}}); // Creates a directed graph with 4 vertices and 4 edges
// Printing the graph
graph.printGraph();
return 0;



This example demonstrates creating a directed graph with 4 vertices and 4 edges, then printing the graph to the console. The `loadGraph` method is used to populate the graph with edges, and `printGraph` displays the graph's structure.

The `Graph` class provides a solid foundation for graph-based algorithms and data structures, making it easy to implement complex graph operations and algorithms.

### `P.S:I got help from phind to create this readme`
 

