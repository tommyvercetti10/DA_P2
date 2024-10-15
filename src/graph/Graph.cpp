#include <cfloat>
#include "Graph.h"

Graph::Graph() = default;

void Graph::resetAll() {
    for(auto pair : vertices) {
        Vertex* v = pair.second;
        v->setVisited(false);
    }
}

std::unordered_map<unsigned int, Vertex*> Graph:: getVertices() const {
    return vertices;
}

void Graph::addVertex(Vertex* vertex) {
    if(getVertex(vertex->getId()) == nullptr) vertices.emplace(vertex->getId(), vertex);
}

Vertex* Graph::getVertex(const unsigned int& id) const {
    if(vertices.find(id) == vertices.end()) return nullptr;
    return vertices.find(id)->second;
}

std::vector<Vertex*> Graph::prim() {

    std::vector<Vertex*> verticesVector;
    verticesVector.reserve(vertices.size());

    for(auto pair: vertices) {
        Vertex* v = pair.second;
        verticesVector.emplace_back(v);
    }

    if (vertices.empty()) {
        return verticesVector;
    }

    resetAll();

    Vertex* s = vertices.at(0);
    s->setDist(0);

    MutablePriorityQueue<Vertex> q;
    q.insert(s);

    while(!q.empty() ) {

        auto v = q.extractMin();
        v->setVisited(true);

        for(auto pair : vertices) {
            Vertex* w = pair.second;
            Edge* e = v->getEdge(w->getId());
            double dist = e == nullptr ? w->getCoordinates()->getDistance(*v->getCoordinates()) : e->getDistance();

            if (!w->isVisited()) {
                auto oldDist = w->getDist();

                if(dist < oldDist) {
                    w->setDist(dist);
                    w->setPath(e);

                    if (oldDist == FLT_MAX) {
                        q.insert(w);
                    }

                    else {
                        q.decreaseKey(w);
                    }
                }
            }
        }
    }
    return verticesVector;
}

std::vector<Vertex*> Graph::dfs(const unsigned int& source) {
    std::vector<Vertex*> res;

    auto s = getVertex(source);
    if (s == nullptr) {
        return res;
    }

    resetAll();

    dfsVisit(s, res);

    return res;
}


void Graph::dfsVisit(Vertex *v, std::vector<Vertex*> & res) const {
    v->setVisited(true);
    res.push_back(v);
    for (auto & pair : v->getAdj()) {
        Edge* e = pair.second;
        auto w = e->getDest();
        if (!w->isVisited()) {
            dfsVisit(w, res);
        }
    }
}