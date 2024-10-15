#include "Vertex.h"


Vertex::Vertex(const unsigned int& id) : id(id) { }

bool Vertex::operator<(const Vertex& other) const {
    return this->dist < other.dist;
}

unsigned int Vertex::getId() const {
    return id;
}

Coordinates* Vertex::getCoordinates() {
    return coordinates;
}

void Vertex::setCoordinates(const Coordinates& val) {
    *coordinates = val;
}

std::unordered_map<unsigned int, Edge*> Vertex::getAdj() const {
    return adj;
}

std::unordered_map<unsigned int, Edge*> Vertex::getIncoming() const {
    return incoming;
}

void Vertex::addEdge(Edge* edge) {
    adj.emplace(edge->getDest()->getId(), edge);
}

void Vertex::addIncoming(Edge* edge) {
    adj.emplace(edge->getSource()->getId(), edge);
}

Edge* Vertex::getEdge(const unsigned int& val) const {
    if(adj.find(val) != adj.end()) {
        return adj.find(val)->second;
    }
    return nullptr;
}

Edge* Vertex::getPath() const {
    return path;
}

void Vertex::setPath(Edge* edge) {
    path = edge;
}

double Vertex::getDist() const {
    return dist;
}

void Vertex::setDist(const double& distance) {
    dist = distance;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(const bool& flag) {
    visited = flag;
}

std::string Vertex::getLabel() const {
    return label;
}

void Vertex::setLabel(const std::string& val) {
    label = val;
}