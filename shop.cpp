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
        std::getline(std::cin, title);
        numOfBooks += 1;
        LIBRARY[numOfBooks] = title;
        std::cout << "\n'" << title << "' has been entered with the ID " << numOfBooks << ".\n\n";

    }// bool addBook()

    void Shop::printLibrary() {
        std::cout << "----------------------\n";
        std::cout << "ID       Title\n\n";
        for (auto i : LIBRARY) {
            std::cout << i.first << "       " << i.second << std::endl;
        }
    }
}