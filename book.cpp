#include "book.h"
// Implements constructor of a book

namespace BookShop {

    Book::Book(const std::string& aName, int anID) : 
            name(aName), ID(anID) {}

}