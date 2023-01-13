#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


namespace BookShop {
    
    class Shop{
        public:
            // constructor
            Shop();
            // destructor



            // allows for a user to purchase a book
            bool buyBook();

            // prints books available
            void printLibrary(); //

            // employee system
            bool login();
            
            // adds a book to the library
            void addBook(); //

        private:
            // the int is the ID and the string is the title of the book
            std::unordered_map<int, std::string> LIBRARY;

            // 1st string is username
            // vector contains 2 strings, password and employee type (admin/regular)
            // admins will be allowed to hire/fire 
            std::unordered_map<std::string, std::vector<std::string>> EMPLOYEE_LOGIN;
            int numOfBooks;
    };
}

#endif