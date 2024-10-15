#include <valarray>
#include <cfloat>
#include <iostream>
#include "DataManager.h"

DataManager::DataManager(Graph *g) : g(g) {}

void DataManager::tspBacktrackingAux(int count, const Vertex* currentVertex, double cost, double& ans, std::vector<Vertex*>& path, std::vector<Vertex*>& bestPath) {
    if(count == g->getVertices().size()) {
        Edge* edge = nullptr;
        for(auto pair: currentVertex->getAdj()) {
            Edge* e = pair.second;
            if(e->getDest()->getId() == 0) {
                edge = e;
                break;
            }
        }
        if(edge != nullptr && (cost + edge->getDistance() < ans)) {
            ans = cost + edge->getDistance();
            bestPath = path;
            bestPath.push_back(g->getVertex(0));
            return;
        }
    }

    for(auto pair: currentVertex->getAdj()) {
        Edge* e = pair.second;
        Vertex* dest = e->getDest();
        if(!dest->isVisited()) {
            dest->setVisited(true);
            path.push_back(dest);
            tspBacktrackingAux(count + 1, dest, cost + e->getDistance(), ans, path, bestPath);
            path.pop_back();
            dest->setVisited(false);
        }
    }
}

double DataManager::tspBacktracking() {
    g->resetAll();
    std::vector<Vertex*> path, bestPath;
    Vertex* origin = g->getVertex(0);
    path.push_back(origin);
    origin->setVisited(true);
    double res = FLT_MAX;

    tspBacktrackingAux(1, origin, 0, res, path, bestPath);

    return res;
}

double DataManager::getTourDistance(const std::vector<Vertex*>& tour) const {
    if(tour.empty()) return 0;
    Vertex* start = g->getVertices().at(0);
    double cost = 0;

    for (size_t i = 0; i < tour.size() - 1; i++) {
        Vertex* current = tour[i];
        Vertex* next = tour[i + 1];

        Edge* e = current->getEdge(next->getId());
        cost += e == nullptr ? next->getCoordinates()->getDistance(*current->getCoordinates()) : e->getDistance();

    }

    Vertex* last = tour.back();

    Edge* e = last->getEdge(0);
    cost += e == nullptr ? last->getCoordinates()->getDistance(*start->getCoordinates()) : e->getDistance();

    return cost;
}

double DataManager::tspApproximation() const {
    g->resetAll();

    std::vector<Vertex*> mst = g->prim();

    return getTourDistance(mst);
}

std::vector<Vertex*> DataManager::optimizeTour(std::vector<Vertex*>& tour) const{
    std::vector<Vertex*> bestTour = tour;
    double currentDistance = getTourDistance(tour);
    double bestDist = currentDistance;
    double currentTemp = 5000;
    double stopTemp = 1;

    while (currentTemp > stopTemp) {
        int index1 = rand() % tour.size();
        int index2 = rand() % tour.size();

        if (index1 == index2 || index1 == 0 || index2 == 0) continue;
        if (index1 > index2) std::swap(index1, index2);

        std::reverse(tour.begin() + index1, tour.begin() + index2 + 1);
        double newDist = getTourDistance(tour);

        if (newDist < currentDistance || ((double)rand() / RAND_MAX) <= exp((currentDistance - newDist) / currentTemp)) {
            currentDistance = newDist;
            if (newDist < bestDist) {
                bestTour = tour;
                bestDist = newDist;
            }
        } else {
            std::reverse(tour.begin() + index1, tour.begin() + index2 + 1);
        }

        currentTemp *= 0.995;
    }

    return bestTour;
}

Vertex* DataManager::findNearestNeighbour(Vertex* v, bool connected) const {
    Vertex* min = nullptr;
    double currentDist = FLT_MAX;
    if(connected) {
        for(auto pair: g->getVertices()) {
            Vertex* vertex = pair.second;
            if(vertex == v || vertex->isVisited()) continue;
            Edge* e = v->getEdge(vertex->getId());
            double dist = e == nullptr ? v->getCoordinates()->getDistance(*vertex->getCoordinates()) : e->getDistance();
            if(dist < currentDist) {
                min = vertex;
                currentDist = dist;
            }
        }
    }
    else {
        for(auto pair: v->getAdj()) {
            Edge* e = pair.second;
            Vertex* vertex = e->getDest();
            if(vertex->isVisited()) continue;
            double dist = e->getDistance();
            if(dist < currentDist) {
                min = vertex;
                currentDist = dist;
            }
        }
    }
    return min;
}

std::vector<Vertex*> DataManager::getNearestNeighbourTour(bool connected, const unsigned int& start) const {
    g->resetAll();
    Vertex* current = g->getVertex(start);
    std::vector<Vertex*> tour;
    tour.push_back(current);

    current->setVisited(true);

    for(size_t i = 1; i < g->getVertices().size(); i++) {
        current = findNearestNeighbour(current, connected);
        if(current == nullptr) {
            return {};
        }
        current->setVisited(true);
        tour.push_back(current);
    }

    return tour;
}