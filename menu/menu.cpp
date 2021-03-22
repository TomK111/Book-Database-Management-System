//
// Created by tomislav on 3/22/21.
//

#include <iostream>
#include "menu.h"

int menu() {
    int choice;
    std::cout << "\nBook Management";
    std::cout << "\n1.Insert book record";
    std::cout << "\n2.View all book record";
    std::cout << "\n3.Search book record";
    std::cout << "\n4.Delete book record";
    std::cout << "\n5.Update book record";
    std::cout << "\n6.Exit";
    std::cout << "\n\nEnter your choice : ";
    std::cin >> (choice);
    return (choice);
}

