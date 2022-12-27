#ifndef SHOP_LIBRARY
#define SHOP_LIBRARY

#include <iostream>
#include <string>
#include <vector>
#include "book.h"


namespace BookShop {
    
    struct Book;
    
    class Shop{
        public:


        private:
            std::vector<Book*> library;
    };
}

#endif