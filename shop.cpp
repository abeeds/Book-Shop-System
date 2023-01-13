#include "shop.h"

namespace BookShop {
    Shop::Shop() {
        numOfBooks = 0;
    }

    // the ID's for each book are assigned by the system
    // only accessible by employee
    void Shop::addBook() {
        std::string title;

        std::cout << "Please enter the title of the book: ";
        std::cin >> title;
        numOfBooks += 1;
        LIBRARY[numOfBooks] = title;
        std::cout << "\nBook has been entered with the ID " << numOfBooks << ".\n";

    }// bool addBook()
}