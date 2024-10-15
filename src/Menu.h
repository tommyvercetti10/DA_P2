//
// Created by CE LABRUGE on 19/05/2024.
//

#ifndef SRC_MENU_H
#define SRC_MENU_H


#include "DataLoader.h"
#include "DataManager.h"
#include <limits>
#include <chrono>

class Menu {
    private:
        DataManager dataManager;
    public:
        Menu() : dataManager(DataManager(new Graph())) {}
        void run();
        void failInt();
        int finalMenu();
};




#endif //SRC_MENU_H
