#include "Menu.h"
#include <iostream>


int main() {
    auto* dataManager = new Graph();
    //d.loadSmallDataSet("../dataset/small/shipping.csv", *dataManager);
    auto start = std::chrono::high_resolution_clock::now();
    DataLoader::loadMediumDataSet("../../dataset/medium/nodes.csv", "../../dataset/medium/edges_100.csv", *dataManager, 100);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "DONE IN :" << elapsed.count() << std::endl;
    DataManager dataManager1 = DataManager(dataManager);
/*
    start = std::chrono::high_resolution_clock::now();
    auto v = dataManager1.getNearestNeighbourTour(false, 5);
    std::cout << dataManager1.getTourDistance(v);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "DONE IN :" << elapsed.count() << std::endl;*/

    start = std::chrono::high_resolution_clock::now();

        auto as = dataManager1.getNearestNeighbourTour(true, 0);
        std::cout << as.size() << std::endl;
        auto a = dataManager1.optimizeTour(as);
        std::cout << dataManager1.getTourDistance(a) << std::endl;


    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "DONE IN :" << elapsed.count() << std::endl;

    //d.loadBigDataSet("../dataset/large/graph1/nodes.csv", "../dataset/large/graph1/edges.csv", *dataManager);
    return 0;
}