#include "Edge.h"

Edge::Edge(Vertex* source, Vertex* destination, const double& dist) : src(source), dest(destination), distance(dist) { }

Vertex* Edge::getSource() const {
    return src;
}

Vertex* Edge::getDest() const {
    return dest;
}

double Edge::getDistance() const {
    return distance;
}