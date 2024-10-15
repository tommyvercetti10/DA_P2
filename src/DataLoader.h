#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include "./graph/Edge.h"
#include "./graph/Graph.h"

class DataLoader {
    public:
        static void trimLine(std::string& line);
        static void loadSmallDataSet(const std::string& path, Graph& graph);
        static void loadMediumDataSet(const std::string& nodes, const std::string& path, Graph& graph, int count);
        static void loadBigDataSet(const std::string& nodes, const std::string& path, Graph& graph);

};


#endif
