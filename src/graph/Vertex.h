#ifndef VERTEX_H
#define VERTEX_H


#include "../Coordinates.h"
#include "Edge.h"
#include <unordered_map>
#include <string>

class Edge;

class Vertex {
    private:
        unsigned int id;
        Coordinates* coordinates = new Coordinates();
        std::unordered_map<unsigned int, Edge*> adj;
        std::unordered_map<unsigned int, Edge*> incoming;
        double dist;
        Edge* path = nullptr;
        bool visited = false;
        std::string label = "";
    public:
        int queueIndex = 0;
        explicit Vertex(const unsigned int& id);
        bool operator<(const Vertex& other) const;
        unsigned int getId() const;
        Coordinates* getCoordinates();
        void setCoordinates(const Coordinates& val);
        std::unordered_map<unsigned int, Edge*> getAdj() const;
        std::unordered_map<unsigned int, Edge*> getIncoming() const;
        double getDist() const;
        void setDist(const double& distance);
        Edge* getPath() const;
        void setPath(Edge* edge);
        void addEdge(Edge* edge);
        void addIncoming(Edge* edge);
        Edge* getEdge(const unsigned int& id) const;
        bool isVisited() const;
        void setVisited(const bool& flag);
        std::string getLabel() const;
        void setLabel(const std::string& val);
};


#endif
