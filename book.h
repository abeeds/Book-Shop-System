#ifndef SHOP_BOOK
#define SHOP_BOOK

#include <iostream>
#include <string>
#include <vector>


namespace BookShop {
    
    struct Book {
        std::string name;
        int ID;

        // constructor
        Book(const std::string& aName, int anID);
    };

}

#endif