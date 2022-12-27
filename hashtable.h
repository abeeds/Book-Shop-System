#include <iostream>
#include <list>
#include <cstring>
using namespace std;

namespace BookShop{

    struct Book;

    class HashTable {

        public:
            bool isEmpty() const;
            int hashFunction(int key);
            void insertItem(int key, string value);
            bool removeItem(int key);
            string searchTable(int key);
            void printTable();

        private:
            static const int hashGroups = 10;
            list<pair<int, string>> table[hashGroups];
    };


}