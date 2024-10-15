#include "DataLoader.h"
#include <iostream>


void DataLoader::trimLine(std::string& line) {
    if(line.back() == '\r') line.pop_back();
}

void DataLoader::loadSmallDataSet(const std::string& path, Graph& graph) {
    std::string line;
    std::ifstream stream(path);
    std::getline(stream, line);
    while(std::getline(stream, line)) {
        try {
            trimLine(line);
            std::istringstream iss(line);

            std::string originStr, destinationStr, distanceStr, originLabel, destinationLabel;
            int origin, destination;
            double distance;

            std::getline(iss, originStr, ',');
            std::getline(iss, destinationStr, ',');
            std::getline(iss, distanceStr, ',');

            origin = std::stoi(originStr);
            destination = std::stoi(destinationStr);
            distance = std::stod(distanceStr);
            auto* v1 = graph.getVertex(origin) != nullptr ? graph.getVertex(origin) : new Vertex(origin);
            auto* v2 = graph.getVertex(destination) != nullptr ? graph.getVertex(destination) : new Vertex(destination);

            Edge* edge1 = new Edge(v1, v2, distance);
            Edge* edge2 = new Edge(v2, v1, distance);



            graph.addVertex(v1);
            graph.addVertex(v2);

            v1->addEdge(edge1);
            v1->addIncoming(edge2);

            v2->addEdge(edge2);
            v2->addIncoming(edge1);

            if(std::getline(iss, originLabel, ',') && std::getline(iss, destinationLabel, ',')) {
                v1->setLabel(originLabel);
                v2->setLabel(destinationLabel);
            }


        } catch (...) {
            continue;
        }

    }
}

void DataLoader::loadMediumDataSet(const std::string& nodes, const std::string& path, Graph& graph, int count) {
    std::string line, pathline;

    std::ifstream stream(nodes);
    std::ifstream pathstream(path);


    std::getline(stream, line);

    while(std::getline(stream, line) && count > 0) {
        try {
            trimLine(line);
            std::istringstream iss(line);

            std::string idStr, xStr, yStr;
            int id;
            double x, y;

            std::getline(iss, idStr, ',');
            std::getline(iss, xStr, ',');
            std::getline(iss, yStr, ',');

            id = std::stoi(idStr);
            x = std::stod(xStr);
            y = std::stod(yStr);

            auto* v = new Vertex(id);
            v->getCoordinates()->setLatitude(x);
            v->getCoordinates()->setLongitude(y);
            graph.addVertex(v);

            count--;
        } catch (...) {
            continue;
        }

    }
    while(std::getline(pathstream, pathline)) {
        try {
            trimLine(pathline);
            std::istringstream pathiss(pathline);

            std::string originStr, destinationStr, distanceStr;
            int origin, destination;
            double distance;

            std::getline(pathiss, originStr, ',');
            std::getline(pathiss, destinationStr, ',');
            std::getline(pathiss, distanceStr, ',');

            origin = std::stoi(originStr);
            destination = std::stoi(destinationStr);
            distance = std::stod(distanceStr);


            auto* v1 = graph.getVertex(origin);
            auto* v2 = graph.getVertex(destination);

            Edge* edge1 = new Edge(v1, v2, distance);
            Edge* edge2 = new Edge(v2, v1, distance);

            v1->addEdge(edge1);
            v1->addIncoming(edge2);

            v2->addEdge(edge2);
            v2->addIncoming(edge1);



        } catch (...) {
            continue;
        }

    }


}

void DataLoader::loadBigDataSet(const std::string& nodes, const std::string& path, Graph& graph) {
    std::string line, pathline;

    std::ifstream stream(nodes);
    std::ifstream pathstream(path);

    std::getline(pathstream, pathline);
    std::getline(stream, line);


    while(std::getline(stream, line)) {
        try {
            trimLine(line);
            std::istringstream iss(line);

            std::string idStr, xStr, yStr;
            int id;
            double x, y;

            std::getline(iss, idStr, ',');
            std::getline(iss, xStr, ',');
            std::getline(iss, yStr, ',');

            id = std::stoi(idStr);
            x = std::stod(xStr);
            y = std::stod(yStr);

            auto* v = graph.getVertex(id) != nullptr ? graph.getVertex(id) : new Vertex(id);
            graph.addVertex(v);
            v->getCoordinates()->setLatitude(x);
            v->getCoordinates()->setLongitude(y);
            //std::cout << id << ", " << x << ", " << y << '\n';




        } catch (...) {
            continue;
        }

    }
    int i=1;
    while(std::getline(pathstream, pathline)) {
        try {
            trimLine(pathline);
            std::istringstream pathiss(pathline);

            std::string originStr, destinationStr, distanceStr, originLabel, destinationLabel;
            int origin, destination;
            double distance;

            std::getline(pathiss, originStr, ',');
            std::getline(pathiss, destinationStr, ',');
            std::getline(pathiss, distanceStr, ',');

            origin = std::stoi(originStr);
            destination = std::stoi(destinationStr);
            distance = std::stod(distanceStr);


            auto* v1 = graph.getVertex(origin) ;
            auto* v2 = graph.getVertex(destination);

            Edge* edge1 = new Edge(v1, v2, distance);
            Edge* edge2 = new Edge(v2, v1, distance);

            v1->addEdge(edge1);
            v1->addIncoming(edge2);

            v2->addEdge(edge2);
            v2->addIncoming(edge1);

        } catch (...) {
            continue;
        }

    }
}