//
// Created by CE LABRUGE on 19/05/2024.
//


#include <iostream>
#include "Menu.h"

void Menu::run() {
    int option;
    dataSetPath:
    std::cout << "\nSelect the size of Dataset:" << "\n\n";
    std::cout << "1. Small dataset" <<"\n";
    std::cout << "2. Medium dataset" <<"\n";
    std::cout << "3. Big dataset" <<"\n";
    std::cout << "\nChoose an option: ";
    std::cin >> option;
    if(std::cin.fail()) {
        failInt();
        goto dataSetPath;
    }
    if (option == 1) DataLoader::loadSmallDataSet("../dataset/small/tourism.csv", *dataManager.g);
    if (option == 2) DataLoader::loadMediumDataSet("../dataset/medium/nodes.csv","../dataset/small/tourism.csv", *dataManager.g, 25);
    if (option == 3) DataLoader::loadBigDataSet("../dataset/large/graph1/nodes.csv", "../dataset/large/graph1/edges.csv", *dataManager.g);
    int option2;
    //auto v = dataManager.getNearestNeighbourTour();
    MainMenu:
    std::cout << "\nRouting Algorithm for Ocean Shipping and Urban Deliveries" << "\n";
    std::cout << "===============[ MENU ]===============\n";
    std::cout << "1. TSP Backtracking\n";
    std::cout << "2. Triangular Approximation Heuristic\n";
    std::cout << "3. Other Heuristics (Simulated annealing with 2-opt approximation)\n";
    std::cout << "4. TSP in the Real World\n";
    std::cout << "\nChoose an option: ";
    do {
        std::cin >> option2;
        if(std::cin.fail()) {
            failInt();
            goto MainMenu;
        }
        switch (option2) {
            case 1: {
                int in;
                auto start = std::chrono::high_resolution_clock::now();
                double result = dataManager.tspBacktracking();
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "\nTSP Backtracking";
                std::cout << "\n==============================\n";
                std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;
                std::cout << "Result: " << result << std::endl;
                std::cout << "==============================\n";
                in = finalMenu();
                if (in == 1) goto MainMenu;
                else if (in == 2) option2 = 5;
                break;
            }
            case 2: {
                int in;
                auto start = std::chrono::high_resolution_clock::now();
                double result = dataManager.tspApproximation();
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "\nTriangular Approximation Heuristic";
                std::cout << "\n==============================\n";
                std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;
                std::cout << "Result: " << result << std::endl;
                std::cout << "==============================\n";
                in = finalMenu();
                if (in == 1) goto MainMenu;
                else if (in == 2) option2 = 5;
                break;
            }
            case 3: {
                int in;
                auto start = std::chrono::high_resolution_clock::now();
                //auto v = dataManager.getNearestNeighbourTour();
                //auto a = dataManager.optimizeTour(v);
                //double result = dataManager.getTourDistance(a);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "\nSimulated annealing with 2-opt approximation";
                std::cout << "\n==============================\n";
                std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;
                //std::cout << "Result: " << result << std::endl;
                std::cout << "==============================\n";
                in = finalMenu();
                if (in == 1) goto MainMenu;
                else if (in == 2) option2 = 5;
                break;
            }
            case 4: {
                int in;
                auto start = std::chrono::high_resolution_clock::now();
                //auto v = dataManager.getNearestNeighbourTour();
                //double result = dataManager.getTourDistance(v);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "\nNearest Neighbour";
                std::cout << "\n==============================\n";
                std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;
                //std::cout << "Result: " << result << std::endl;
                std::cout << "==============================\n";
                in = finalMenu();
                if (in == 1) goto MainMenu;
                else if (in == 2) option2 = 5;
                break;
            }
            default:
                std::cout << "\nInvalid Option. Try Again.\n";
                goto MainMenu;
                break;
        }
    }while(option2 != 5);

}

int Menu::finalMenu() {
    finalmenu:
    std::cout << "\n\n============================\n";
    std::cout << "1. Return to main menu\n";
    std::cout << "2. Exit\n";
    std::cout << "\nChoose an option: ";
    int in;
    std::cin >> in;
    if(std::cin.fail()) {
        failInt();
        goto finalmenu;
    }
    return in;
}

void Menu::failInt() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nInvalid input. Please enter an integer." << std::endl;
}