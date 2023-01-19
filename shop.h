#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <unordered_map>
#include <iostream>
#include "book.h"

class Book;

class Shop {
public:
    void addBook(); // employee can add copies of a book.
    void updateBook(); //  update prices/quantities

    void login(); // enter as employee or guest

    void purchaseBook(); 

    void printLibrary(); // displays books available and corresponding data

    void saveData(); // saves information to a text file
    void retrieveData(); // checks for existing save data

    void run(); // Will run this program.
private:
    std::unordered_map<int, Book> Library; // the int is the ID
    std::unordered_map<std::string, std::string> Employees; // username, password
    int quantity;   // amount of unique books
    int revenue;    // money made
    std::string cur_mode; // employee or guest

};

#endif
