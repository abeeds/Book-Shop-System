#include "shop.h"



int Shop::login() {
    std::string user_inp;
    std::string username;
    std::string password;
    int login_type; //1 for customer, 2 for employee

    std::cout << "Would you like to log-in or continue as a guest?\n\n";
    std::cout << "Please type 1, 2, or 3 to make a selection: \n";
    std::cout << "1. Register\n";
    std::cout << "2. Log-in\n";
    std::cout << "3. Continue As Guest\n";
    std::cin >> user_inp;

    // will end the program.
    if (username == "exit") {
        exit();
    }

    // register as account
    if (user_inp == "1") {
        std::cout << "\n\nRegister account selected.\nPlease type exit if you would like to restart.";
        std::cout << "\n\nPlease type your desired username: ";
        std::getline(std::cin, username);

        if (username == "exit") {
                std::cout<< "\n\n\n\n";
                return 0;
        }

        // if username already exists
        while(Employees.find(username) != Employees.end() || Customers.find(username) != Customers.end()) {
            std::cout << "\n\nSorry, the username you have already entered is already in use.\nPlease try again: ";
            std::getline(std::cin, username);
            if (username == "exit") {
                std::cout << "\n\n\n\n";
                return 0;
            }
        }

        // valid username entered
        std::cout << "\n\nPlease enter your desired password: ";
        std::getline(std::cin, password);
        Customers[username] = password; // store account information

        std::cout << "\n\nWelcome " << username << "!\n\n";

    }

    // log in
    if(user_inp == "2") {
        std::cout << "\n\nLog-in selected.\nPlease type exit if you would like to restart";
        std::cout << "\n\nPlease type your username: ";
        std::getline(std::cin, username);

        // if username does not exist
        while (Employees.find(username) == Employees.end() && Customers.find(username) == Customers.end()) {
            std::cout << "\n\nSorry, the username you have entered is not associated with any account.\nPlease try again: ";
            std::getline(std::cin, username);

            if (username == "exit") {
                std::cout<< "\n\n\n\n";
                return 0;
            }
        }

        //valid username found
        //identify if username is associated with employee or customer type account 
        if(Employees.find(username) != Employees.end()) {
            login_type = 2;
        }
        else { // continuing as customer
            login_type = 1;
        }

        
        std::cout << "\n\nPlease enter your password: ";
        std::getline(std::cin, password);

        if(login_type == 2) {
            while(Employees[username] != password) {
                std::cout << "\n\nSorry, the password you have entered is not associated with the username.\nPlease try again: ";
                std::getline(std::cin, password);

                if(password == "exit") {
                    std::cout<< "\n\n\n\n";
                    return 0;
                }
            }
            std::cout << "\n\nWelcome " << username << "!\n\n";
            return 3;
        } 

        if(login_type == 1) {
            while(Customers[username] != password) {
                std::cout << "\n\nSorry, the password you have entered is not associated with the username.\nPlease try again: ";
                std::getline(std::cin, password);

                if(password == "exit") {
                    std::cout<< "\n\n\n\n";
                    return 0;
                }
            }
            std::cout << "\n\nWelcome " << username << "!\n\n";
            return 2;
        } 


        
    }

    // continue as guest
    if(user_inp == "3") {
        std::cout << "\n\nContinuing as guest.\n\n";
        return 1;
    }
}

// for employees
// will print everything even if the book is unavailable
void Shop::adminDisplay() {
    std::cout << "Displaying all books in the catalogue\n\n";
    std::cout << "ID     Name     Author     Quantity     Price\n";
    for (auto i = Library.begin(); i != Library.end(); i++) {
        std::cout << i->first << "     ";
        i->second.display();
        std::cout << "\n";
    }
}


// for customers
void Shop::printLibrary() {
    std::cout << "Displaying all available books\n\n";
    std::cout << "ID     Name     Author     Quantity     Price\n";
    
    for (auto i = Library.begin(); i != Library.end(); i++) {
        // will only print if available
        if(i->second.isAvailable()) {
            std::cout << i->first << "     ";
            i->second.display();
            std::cout << "\n";
        }
    }
}



void Shop::run() {
    std::cout << "Welcome to the Bookshop!\n";

    int mode;
    mode = login();
    //  mode values: 
    // 0: exit has been entered during login -> call this function again
    // 1: logging in as guest
    // 2: logging in as customer
    // 3: logging in as employee
    // 4: shut down 

    // restart if mistake is made during login
    while(mode == 0) {
        mode = login();
    }

    if(mode == 4) {
        exit();
    }



}

void Shop::exit() {
    std::cout << "\n\n\nShutting down..."; 
}
