#ifndef EDGE_H
#define EDGE_H


#include "Vertex.h"

class Vertex;

class Edge {
    private:
        Vertex* src;
        Vertex* dest;
        double distance;
    public:
        Edge(Vertex* source, Vertex* destination, const double& dist);
        Vertex* getSource() const;
        Vertex* getDest() const;
        double getDistance() const;
};


#endif
