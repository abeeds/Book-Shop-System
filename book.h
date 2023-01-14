#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>


class Book {
    public:
        // Constructor
        // Default quantity is 1 and price is 19.99
        Book(std::string Name, std::string Author, int Quantity=1, double Price=19.99);

        

        // increases quantity of book
        void addBook();
        
        // allows for book to be sold if there are enough copies.
        // returns money made
        double purchaseBook();

        // Prints in the following format
        // Name     Author     Quantity_Available     Price
        void display();
    private:
        std::string name;
        std::string author;
        int quantity;
        double price;
};


#endif
