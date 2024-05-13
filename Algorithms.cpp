/**
 * Roi Sibony
 * roisi20041@gmail.com
*/
#include "Algorithms.hpp"
#include <climits>
#include <queue>

namespace ariel
{
    //my definetion for connected is that there's no vertext that isn't touched by other vertexes in a component
    // standard dfs algorithm
    void Algorithms::dfs(const Graph &g, std::vector<bool> &visited, size_t vertex)
    {
        visited[vertex] = true; // Mark current vertex as visited

        // Recursively visit all unvisited neighbors
        for (size_t neighbor = 0; neighbor < g.getVertices(); ++neighbor)
        {
            if (g.getGraph()[vertex][neighbor] != 0 && !visited[neighbor])
            {
                dfs(g, visited, neighbor);
            }
        }
    }
    // create missing edges
    void Algorithms::makeSymmetric(Graph &g)
    {
        for (size_t i = 0; i < g.getVertices(); ++i)
        {
            for (size_t j = 0; j < g.getVertices(); ++j)
            {
                if (g.getGraph()[i][j] != g.getGraph()[j][i])
                {
                    g.getGraph()[i][j] = g.getGraph()[j][i] = 1;
                }
            }
        }
    }
    // public function, checks if the graph is connected (not strongly connected, just connected)
    int Algorithms::isConnected(Graph g)
    {
        size_t V = g.getVertices(); // amount of vertirces 
        if (V == 0) {
            return 0;
        }
        
        // Create a visited vector to keep track of visited nodes
        std::vector<bool> visited((size_t)g.getVertices(), false);

        // Choose any starting vertex (here we choose the first vertex just because)
        size_t start = 0;

        // Perform DFS traversal starting from the chosen vertex
        makeSymmetric(g);       // now we have symmetring graph so when we will do dfs if the graph is connected we will get to everyone else not
        dfs(g, visited, start); // we will dfs, if we can reach all the vertices then the graph is connected

        // Check if all vertices are marked visited
        for (size_t i = 0; i < visited.size(); i++)
        {
            if (!visited[i]) // if one of them is false then the graph is not connected
            {
                // std::cout << "false "; //used for debugging
                return 0;
            }
        }

        // If all vertices are visited, the graph is connected
        // std::cout << "true "; //used for debugging
        return 1;
    }
    // public function, checks if there is a back edge,in the end stores all the vertexes of the cycle in reslut
    bool Algorithms::dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<bool> &recStack, size_t vertex, size_t parent, std::string &result)
    {
        // std::cout << "Visiting vertex: " << vertex << std::endl;
        visited[vertex] = true;
        recStack[vertex] = true;

        for (size_t neighbor = 0; neighbor < g.getVertices(); neighbor++)
        {
            if (!g.isDirected() && parent == neighbor)
            {
                // std::cout << "Skipping parent in undirected graph: " << neighbor << std::endl;
                continue;
            }

            if (g.getGraph()[vertex][neighbor] != 0 && !visited[neighbor])
            {
                // std::cout << "Recursing to neighbor: " << neighbor << std::endl;
                if (dfsCycleHelper(g, visited, recStack, neighbor, vertex,result))
                {
                    // std::cout<<vertex;
                    result +=  " <- " + std::to_string(vertex) ;
                    return true;
                }
            }
            else if (neighbor != vertex && recStack[neighbor] && g.getGraph()[vertex][neighbor] != 0) // if the neighbor is not the parent and is in the recStack
            {
                if (g.isDirected() || (!g.isDirected() && parent != neighbor)) // can't complete cycle with my parent if I am undirected
                { // if it's directed or if it's undirected and the neighbor is not the parent

                    result += std::to_string(neighbor) + + " <- " +std::to_string(vertex)  ;
                    return true;
                }
            }
        }
        recStack[vertex] = false;
        // std::cout << "Backtracking from vertex: " << vertex << std::endl; // used for debugging
        return false;
    }
    //public function, dfs's from the every vertex and checks if there is a cycle
    bool Algorithms::isContainsCycle(const Graph &g)
    {
        // Create a visited vector to keep track of visited nodes
        std::vector<bool> visited(g.getVertices(), false);
        std::string result = "";
        // Create a recStack vector to keep track of nodes in the current recursion path

        // Iterate through all vertices
        for (size_t vertex = 0; vertex < g.getVertices(); ++vertex)
        {
            // If the vertex is not visited, call DFS helper function
            if (!visited[vertex])
            {
                std::vector<bool> recStack(g.getVertices(), false);
                if (dfsCycleHelper(g, visited, recStack, vertex, (size_t)-1, result))
                {
                    std::cout << result<<"\n"; // print the cycle
                    return true; // Cycle found found a back edge
                }
            }
        }
        // If no cycle found after iterating through all vertices, return false
        // std::cout << "false doesn't contain cycle";
        return false;
    }
    // Function to find the shortest path between two vertices (Bellman-Ford algorithm)
    // if there's somewhere in teh graph negative cycle we will return that there's a negative cycle even if reach it
    std::string Algorithms::BelmanFord(const Graph &g, size_t src, size_t des)
    {
        size_t V = g.getVertices(); // amount of vertirces 
        if (V == 0) { 
            return "Empty graph";
        }
        
        // Create a vector to store the shortest distances from the source vertex
        std::vector<int> dist(g.getVertices(), INT_MAX);
        std::vector<int> parent(g.getVertices(), -1);
        // Set the distance of the source vertex to itself as 0
        dist[src] = 0;

        // Relax edges repeatedly to find the shortest path
        for (size_t i = 0; i < g.getVertices() - 1; ++i)
        {
            // Iterate through all edges and update the distance if a shorter path is found
            for (size_t u = 0; u < g.getVertices(); ++u)
            {
                for (size_t v = 0; v < g.getVertices(); ++v)
                {
                    if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                    {
                        parent[v] = u;
                        dist[v] = dist[u] + g.getGraph()[u][v];
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (size_t u = 0; u < g.getVertices(); ++u)
        {
            for (size_t v = 0; v < g.getVertices(); ++v)
            {
                if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                {
                    return "Graph contains negative weight cycle";
                }
            }
        }

        //  Return the shortest path from the source vertex to all other vertices
        std::string result;
        if (dist[des] == INT_MAX)
        {
            return "-1";
        }
        while (des != src)
        {
            result += std::to_string(des) + "->";
            des = (size_t)parent[des];
        }

        return result + std::to_string(src);
    }
    
    // Function to find the shortest path between two vertices (Dijkstra's algorithm)
    std::string Algorithms::shortestPath(const Graph &g, size_t des, size_t src)
    {
        return BelmanFord(g, src, des); //BF
    }

    // Function to check if a graph is bipartite (uses BFS)
    bool Algorithms::isSelfLoop(const Graph &g, size_t u) {
        return g.getGraph()[u][u] != 0;
    }

    bool Algorithms::isSameColor(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v) {
        return g.getGraph()[u][v] != 0 && colorArr[v] == colorArr[u];
    }

    bool Algorithms::isNotColored(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v) {
        return g.getGraph()[u][v] != 0 && colorArr[v] == -1;
    }

    std::string Algorithms::isBipartite(const Graph &g) {
        size_t V = g.getVertices(); // amount of vertices 
        if (V == 0) {
            return "The graph is bipartite: A={}, B={}";
        }

        std::vector<int> colorArr(V, -1);
        std::queue<size_t> q;
        //   Start BFS from the first vertex
        for (size_t i = 0; i < V; i++) {
            if (colorArr[i] != -1) {continue;}
            //  Color the first vertex as 1
            q.push(i);
            colorArr[i] = 1;

            while (!q.empty()) {
                size_t u = q.front();
                q.pop();

                if (isSelfLoop(g, u)) {return "0";}

                for (size_t v = 0; v < V; ++v) {
                    if (isSameColor(g, colorArr, u, v)){ return "0";}
                    if (isNotColored(g, colorArr, u, v)) {
                        colorArr[v] = 1 - colorArr[u];
                        q.push(v);
                    }
                }
            }
        }

        std::string result = "The graph is bipartite: A={";
        for (size_t i = 0; i < V; i++) {
            if (colorArr[i] == 0) {result += std::to_string(i) + " ";}
        }

        result += "}, B={";
        for (size_t i = 0; i < V; i++) {
            if (colorArr[i] == 1) {result += std::to_string(i) + " ";}
        }

        result += "}";
        return result;
    }//end of function

    // Function to check for a negative cycle in a weighted graph (Bellman-Ford)
    bool Algorithms::negativeCycle(const Graph &g)
    {
        return BelmanFord(g, 0, 0) == "Graph contains negative weight cycle"; // in BelmanFord we check for negative cycless
    }

} // namespace ariel
