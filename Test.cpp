#include "doctest.h"
#include "Algorithms.hpp"
// #include "Graph.hpp"

using namespace std;
using namespace ariel;
#define CATCH_CONFIG_MAIN
#include <sstream>
#include "Graph.hpp"

using namespace ariel;

TEST_CASE("Graph addition operator")
{
        Graph g1(3);
        Graph g2(3);

        std::vector<std::vector<int>> matrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix1);

        std::vector<std::vector<int>> matrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}};
        g2.loadGraph(matrix2);

        Graph g3 = g1 + g2;
        std::vector<std::vector<int>> expected = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
        CHECK(g3.getGraph() == expected);
}

TEST_CASE("Graph addition assignment operator")
{
        Graph g1(3);
        Graph g2(3);

        std::vector<std::vector<int>> matrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix1);

        std::vector<std::vector<int>> matrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}};
        g2.loadGraph(matrix2);

        g1 += g2;
        std::vector<std::vector<int>> expected = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
        CHECK(g1.getGraph() == expected);
}

TEST_CASE("Graph subtraction operator")
{
        Graph g1(3);
        Graph g2(3);

        std::vector<std::vector<int>> matrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix1);

        std::vector<std::vector<int>> matrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}};
        g2.loadGraph(matrix2);

        Graph g3 = g1 - g2;
        std::vector<std::vector<int>> expected = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        CHECK(g3.getGraph() == expected);
}

TEST_CASE("Graph subtraction assignment operator")
{
        Graph g1(3);
        Graph g2(3);

        std::vector<std::vector<int>> matrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix1);

        std::vector<std::vector<int>> matrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}};
        g2.loadGraph(matrix2);

        g1 -= g2;
        std::vector<std::vector<int>> expected = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        CHECK(g1.getGraph() == expected);
}

TEST_CASE("Graph unary minus operator")
{
        Graph g1(3);

        std::vector<std::vector<int>> matrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix);

        Graph g2 = -g1;
        std::vector<std::vector<int>> expected = {
            {0, -1, 0},
            {-1, 0, -1},
            {0, -1, 0}};
        CHECK(g2.getGraph() == expected);
}

TEST_CASE("Graph scalar multiplication operator")
{
        Graph g1(3);

        std::vector<std::vector<int>> matrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix);

        Graph g2 = g1 * 2;
        std::vector<std::vector<int>> expected = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
        CHECK(g2.getGraph() == expected);
}

TEST_CASE("Graph matrix multiplication operator")
{
        Graph g1(2);
        Graph g2(2);

        std::vector<std::vector<int>> matrix1 = {
            {1, 2},
            {3, 4}};
        g1.loadGraph(matrix1);

        std::vector<std::vector<int>> matrix2 = {
            {2, 0},
            {1, 2}};
        g2.loadGraph(matrix2);

        Graph g3 = g1 * g2;
        std::vector<std::vector<int>> expected = {
            {4, 4},
            {10, 8}};
        CHECK(g3.getGraph() == expected);
}

TEST_CASE("Graph increment and decrement operators")
{
        Graph g1(2);

        std::vector<std::vector<int>> matrix = {
            {1, 2},
            {3, 4}};
        g1.loadGraph(matrix);

        Graph g2 = g1++;
        std::vector<std::vector<int>> expectedPostInc = {
            {2, 3},
            {4, 5}};
        CHECK(g1.getGraph() == expectedPostInc);

        std::vector<std::vector<int>> expectedPreInc = {
            {1, 2},
            {3, 4}};
        CHECK(g2.getGraph() == expectedPreInc);

        g1--;
        CHECK(g1.getGraph() == expectedPreInc);

        --g1;
        std::vector<std::vector<int>> expectedPreDec = {
            {0, 1},
            {2, 3}};
        CHECK(g1.getGraph() == expectedPreDec);

        ++g1;
        CHECK(g1.getGraph() == expectedPreInc);
}

TEST_CASE("Graph comparison operators")
{
        Graph g1(3);
        Graph g2(3);

        std::vector<std::vector<int>> matrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix1);

        std::vector<std::vector<int>> matrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}};
        g2.loadGraph(matrix2);

        CHECK(g1 != g2);
        CHECK(g1 > g2);
        CHECK(g2 < g1);
        CHECK(g1 >= g2);
        CHECK(g2 <= g1);

        Graph g3 = g1;
        CHECK(g1 == g3);
}
TEST_CASE("multimply and devision by scalar"){
        Graph g1(3);
        std::vector<std::vector<int>> matrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(matrix1);
        Graph g2 = g1 * 2;
        std::vector<std::vector<int>> expected = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
        CHECK(g2.getGraph() == expected);
        Graph g3 = g2 / 2;
        bool l = g3==g1;
        CHECK(l == true);
        g3 *= 2;
        CHECK(g3.getGraph() == g2.getGraph());
        g3 /= 2;
        CHECK(g3.getGraph() == g1.getGraph());

}

TEST_CASE("Graph stream output operator")

{
                Graph g1(3);

                std::vector<std::vector<int>> matrix = {
                        {0, 1, 0},
                        {1, 0, 1},
                        {0, 1, 0}};
                g1.loadGraph(matrix);

                std::ostringstream os;
                os << g1;

                std::string expectedOutput = "0 1 0 \n1 0 1 \n0 1 0 \n";
                CHECK(os.str() == expectedOutput);
}
