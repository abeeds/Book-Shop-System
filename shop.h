#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <unordered_map>
#include <iostream>
#include "book.h"

class Book;

class Shop {
public:
    void addBookQuantity(); // employee can add copies of a book.
    void updateBook(); //  update prices/quantities

    // enter as employee or guest
    // 0: exit has been entered during login -> call this function again
    // 1: logging in as guest
    // 2: logging in as customer
    // 3: logging in as employee
    // 4: shut down 
    int login(); // exit cannot be a valid user or pass



    void addEmployee(); // can only be done by an employee

    void purchaseBook(); 
    void printLibrary(); // displays books available and corresponding data

    void adminDisplay(); // displays all books 

    void saveData(); // saves information to a text file
    void retrieveData(); // checks for existing save data

    void run(); // Will run this program.
private:
    std::unordered_map<int, Book> Library; // the int is the ID
    std::unordered_map<std::string, std::string> Employees; // username, password
    std::unordered_map<std::string, std::string> Customers; // username, password
    int quantity;   // amount of unique books
    int revenue;    // money made
    std::string cur_mode; // employee or guest

};

#endif
