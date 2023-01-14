#include "book.h"
#include "stdlib.h"


// ADD ERROR HANDLING


/*
Book::Book(std::string Name, std::string Author, int Quantity=1, double Price=19.99)
    : name(Name), author(Author), quantity(Quantity), price(Price)  // capitalized vars are the parameters
{}
*/

void Book::addBook( ) {
    int amt_of_copies;

    
    std::cout << "Enter the amount of copies of " << name << " by " << author << " would you like to add: ";
    std::cin >> amt_of_copies;

    quantity += amt_of_copies;
    std::cout << std::endl << amt_of_copies << " have been added.\n\n";
}

double Book::purchaseBook() {
    std::string user_inp;
    int amt_to_purchase;

    std::cout << "Enter the amount of " << name << " by " << author << " you would like to purchase: ";

    // need to throw for catch to work

    /*
    try {
        amt_to_purchase = stoi(user_inp);
        if(amt_to_purchase > quantity) {
            // offer to sell quantity instead
            // or take a different input
        }

    }
    catch(int num) {

    }
    */
    
    // 2nd chance to enter proper value
    
}

void Book::display() {
    std::cout << name << "     " << author << "     " << quantity << "     " << price << std::endl;
}
