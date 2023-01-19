#include "book.h"
#include "stdlib.h"
#include <algorithm>


// ADD ERROR HANDLING



Book::Book(std::string Name, std::string Author, int Quantity, double Price)
    : name(Name), author(Author), quantity(Quantity), price(Price)  // capitalized vars are the parameters
{}



void Book::addBook( ) {
    int amt_of_copies;
    std::string user_inp;

    
    std::cout << "\nEnter the amount of copies of " << name << " by " << author << " would you like to add: ";
    std::cin >> user_inp;

    // incase a non-number value or a negative is entered
    try{ 
        amt_of_copies = stoi(user_inp);
        if (amt_of_copies >= 0) {
            quantity += amt_of_copies;
            std::cout << "\nAdding " << amt_of_copies << " copies of " << name << " by " << author << " have been added.\n";
            return;
        }
        throw 1;
    }
    catch(...) {
        std::cout << "\nInvalid amount entered. Trying again.\n\n";
        addBook();
    }
    
    
    
}

void Book::updateQuantity() {
    int updated_quantity;
    std::cout << "Please enter the new quantity of " << name << " by " << author << ": ";
    std::cin >> updated_quantity;

    while(updated_quantity < 0) {
        std::cout << "\nPlease enter a valid quantity (integer >= 0): ";
        std::cin >> updated_quantity;
    }

    quantity = updated_quantity;
    std::cout << "\nQuantity of " << name << " by " << author << "has been set to " << quantity << std::endl;
}

void Book::updatePrice() {
    double updated_price;
    std::cout << "Please enter the new price of " << name << " by " << author << ": ";
    std::cin >> updated_price;

    while(updated_price < 0) {
        std::cout << "\nPlease enter a valid price (decimal >= 0): ";
        std::cin >> updated_price;
    }

    price = updated_price;
    std::cout << "\nPrice of " << name << " by " << author << "has been set to " << price << std::endl;
}

bool Book::isAvailable() {
    return(quantity > 0);
}

double Book::purchaseBook() {
    std::string user_inp;
    int amt_to_purchase;
    int revenue;

    // no copies available
    if( quantity == 0) {
        std::cout << "Sorry. There are currently no copies of " << name << " by " << author << 
            " available.\n";
        return 0;
    }

    std::cout << "Enter the amount of " << name << " by " << author << " you would like to purchase: ";
    std::cin >> user_inp; 
    
    // make input lowercase to compare easier
    std::transform(user_inp.begin(), user_inp.end(), user_inp.begin(), ::tolower);

    // exit from task
    if(user_inp == "exit") {
            std::cout << "\nExitting current task.\n";
            return 0;
        }


    // check for valid input
    try {
        amt_to_purchase = stoi(user_inp);

        // Trying to buy more than available
        if(amt_to_purchase > quantity) {
            
            std::cout << "\nThere are only " << quantity << " copies available.\n";
            std::cout << "Would you like to buy " << quantity << " copies instead?\n";
            std::cout << "Type yes, no, or the new amount you would like to purchase instead: ";
            std::cin >> user_inp;
            
            // make input lowercase to compare easier
            std::transform(user_inp.begin(), user_inp.end(), user_inp.begin(), ::tolower);

            // if yes
            if(user_inp == "yes" || user_inp == "y") {

                // confirm purchase
                std::cout << "\nPlease confirm that you would like to purchase " << quantity << "copies of "
                    << name << " by " << author << ": ";
                std::cin >> user_inp;
                std::transform(user_inp.begin(), user_inp.end(), user_inp.begin(), ::tolower);

                if(user_inp == "yes" || user_inp == "y") {
                    std::cout << "\nThank you for shopping!\n\n";
                    revenue = price * quantity;
                    quantity = 0;
                    return revenue;
                }

                if(user_inp == "no" || user_inp == "n") {
                    std::cout << "\nEnding current task.\n";
                    return 0;
                }
            } 


            // if no
            if (user_inp == "no" || user_inp == "n") {
                std::cout << "\nEnding current task.\n";
                return 0;
            }


            // if buying new amount
            try {
                amt_to_purchase = stoi(user_inp);
                if (amt_to_purchase <= quantity) {
                    std::cout << "\nPlease confirm that you would like to purchase " << amt_to_purchase << "copies of "
                        << name << " by " << author << ": ";
                    std::cin >> user_inp;
                    std::transform(user_inp.begin(), user_inp.end(), user_inp.begin(), ::tolower);

                    // if confirm: yes
                    if(user_inp == "yes" || user_inp == "y") {
                    std::cout << "\nThank you for shopping!\n\n";
                    revenue = price * amt_to_purchase;
                    quantity -= amt_to_purchase;
                    return revenue;
                    }

                    // if confirm: no
                    if(user_inp == "no" || user_inp == "n") {
                        std::cout << "\nEnding current task.\n";
                        return 0;
                    }
                }
                throw 1; // if fails to buy anything
            }
            catch(...) {
                std::cout << "Invalid amount entered.";
                return 0;
            }


        }


        // Trying to buy valid amount
        else if (amt_to_purchase <= quantity) {
            std::cout << "\nPlease confirm that you would like to purchase " << amt_to_purchase << "copies of "
                << name << " by " << author << ": ";
            std::cin >> user_inp;
            std::transform(user_inp.begin(), user_inp.end(), user_inp.begin(), ::tolower);

            // if confirm: yes
            if(user_inp == "yes" || user_inp == "y") {
            std::cout << "\nThank you for shopping!\n\n";
            revenue = price * amt_to_purchase;
            quantity -= amt_to_purchase;
            return revenue;
            }

            // if confirm: no
            if(user_inp == "no" || user_inp == "n") {
                std::cout << "\nEnding current task.\n";
                return 0;
            }
        }

        throw 1; // if fail to buy anything
    }


    catch(...) {
        std::cout << "Invalid value entered. Would you like to continue purchasing this book?";
        std::cin >> user_inp;
        std::transform(user_inp.begin(), user_inp.end(), user_inp.begin(), ::tolower);

        // run function again if yes, exit if no/any other value
        if(user_inp == "yes" || user_inp == "y") {
            std::cout << "\n";
            purchaseBook(); 
        }
        else {
            std::cout << "\nEnding current task.\n";
            return 0;
        }
    }
    return 0;
}

void Book::display() {
    std::cout << name << "     " << author << "     " << quantity << "     " << price << std::endl;
}
