#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "./graph/Graph.h"

class DataManager {
private:

public:
    Graph* g;
    DataManager(Graph* g);

    /**
     * @brief Computes the optimal solution for the Traveling Salesman Problem using backtracking.
     * @details Time Complexity: O(n!), where n is the number of vertices.
     * @return The minimum tour distance.
     */
    double tspBacktracking();

    /**
     * @brief Auxiliary function for the TSP backtracking solution.
     * @details Time Complexity: O(n!), where n is the number of vertices.
     * @param count The current count of visited vertices.
     * @param currentVertex The current vertex being visited.
     * @param cost The current accumulated cost of the tour.
     * @param ans Reference to the variable holding the minimum cost found.
     * @param path The current path being explored.
     * @param bestPath Reference to the vector holding the best path found.
     */
    void tspBacktrackingAux(int count, const Vertex* currentVertex, double cost, double& ans, std::vector<Vertex*>& path, std::vector<Vertex*>& bestPath);

    /**
     * @brief Computes the total distance of a given tour.
     * @details Time Complexity: O(n), where n is the number of vertices in the tour.
     * @param tour The tour whose distance is to be computed.
     * @return The total distance of the tour.
     */
    double getTourDistance(const std::vector<Vertex*>& tour) const;

    /**
     * @brief Approximates the solution to the Traveling Salesman Problem using a Minimum Spanning Tree
     * @details Time Complexity: O(n^2), where n is the number of vertices
     * @return The approximated minimum tour distance
     */
    double tspApproximation() const;

    /**
     * @brief Optimizes a given tour using simulated annealing and the 2-opt algorithm
     * @details Time Complexity: O(n^2) per iteration, where n is the number of vertices in the tour
     * @param tour The initial tour to be optimized
     * @return The optimized tour
     */
    std::vector<Vertex*> optimizeTour(std::vector<Vertex*>& tour) const;

    /**
     * @brief Finds the nearest unvisited neighbor of a given vertex
     * @details Time Complexity: O(n), where n is the number of vertices
     * @param v The vertex for which the nearest neighbor is to be found
     * @return Pointer to the nearest unvisited neighbor
     */
    Vertex* findNearestNeighbour(Vertex* v, bool connected) const;

    /**
     * @brief Generates a tour using the nearest neighbor heuristic
     * @details Time Complexity: O(n^2), where n is the number of vertices
     * @param start The starting vertex index for the tour (default is 0)
     * @return The tour generated using the nearest neighbor heuristic
     */
    std::vector<Vertex*> getNearestNeighbourTour( bool connected, const unsigned int& start = 0) const;
};

#endif
