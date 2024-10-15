#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <algorithm>
#include "Vertex.h"
#include "MutablePriorityQueue.h"

class Graph {
    private:
        std::unordered_map<unsigned int, Vertex*> vertices;

    public:
        Graph();
        void resetAll();
        std::unordered_map<unsigned int, Vertex*> getVertices() const;
        void addVertex(Vertex* vertex);
        Vertex* getVertex(const unsigned int& id) const;
        std::vector<Vertex*> prim();
        std::vector<Vertex*> dfs(const unsigned int& source);
        void dfsVisit(Vertex *v, std::vector<Vertex*> & res) const;
};


#endif