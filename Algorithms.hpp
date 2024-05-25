/**
 * Roi Sibony
 * roisi20041@gmail.com
*/
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
        public:
            static int isConnected(Graph g);
            static bool isContainsCycle(const Graph &g);
            static std::string shortestPath(const Graph &g, size_t des, size_t src);
            static std::string isBipartite(const Graph &g);
            static bool negativeCycle(const Graph &g); 
        private:
            //dfs helper is a chuncky boy
            static bool dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<bool> &recStack, size_t vertex, size_t parent, std::string &result);
            static void dfs(const Graph &g, std::vector<bool> &visited, size_t vertex);
            static void makeSymmetric(Graph &g);
            static bool isSameColor(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v);
            static bool isSelfLoop(const Graph &g, size_t u);
            static bool isNotColored(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v);
            static std::string BelmanFord(const Graph &g, size_t srcm, size_t des,std::vector<size_t> &parent,size_t &i);

    };
}

#endif //end of hpp
