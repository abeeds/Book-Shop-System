#include <iostream>
#include "shop.h"
#include "stdlib.h"
#include "book.h"
#include <algorithm>

/*
To Do:
    Save data as txt files
    Check for save data
    confirmation on addBook
    Entire Shop class
*/


int main() {
    Book test("The Dog", "John Wick", 4, 19.99);
    test.addBook();
    test.purchaseBook();
    test.display();
}
