#include "hashtable.h"

namespace BookShop{

    bool HashTable::isEmpty() const{
        int sum = 0;

        // will be 0 if all lists in the array are empty
        for (int i = 0; i < hashGroups; i++) {
            sum += table[i].size();
        }

        // returns true if sum is not 0
        if (!sum) {
            return true;
        }
        return false;
    }   // isEmpty



    int HashTable::hashFunction(int key) {
        return key % hashGroups;
    }   



    void HashTable::insertItem(int key, string value) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        auto iter = begin(cell);
        bool keyExists = false;
        bool replaceVal = false;

        for (; iter != end(cell); iter++) {
            if (iter->first == key) {
                keyExists = true;

                cout << "[WARNING] Key exists. Current value: " << iter->second << endl;
                cout << "Would you like to replace the value? (y/n): ";
                cin >> replaceVal;

                // option to replace value if the key exists
                if (replaceVal) {
                    iter->second = value;
                    cout << endl << "Value has been replaced." << endl;
                }
                else {
                    cout << "Previous value has been kept." << endl;
                }
                break;
            }
        }

        if (!keyExists) {
            cell.emplace_back(key, value);
        }
        return;
    }   // insertItem



    bool HashTable::removeItem(int key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        auto iter = begin(cell);
        bool keyExists = false;

        for (; iter != end(cell); iter++) {
            if (iter->first == key) {

                keyExists = true;
                iter = cell.erase(iter); // avoids segmentation fault bug
                cout << "[INFO] Item removed." << endl;
                return true;

            }
        }

        if (!keyExists) {
            cout << "[WARNING] Item not found. Pair not removed." << endl;
        }

        return false;
    }   // removeItem
    


    void HashTable::printTable() {
        for (int i = 0; i < hashGroups; i++) {
            if (table[i].size() == 0) continue;

            auto iter = table[i].begin();
            for( ; iter != table[i].end(); iter++) {
                cout << "[INFO] Key: " << iter->first<< " Value: " << iter->second << endl;
            }
        }
    }// printTable

}



/*
string searchTable(int key);
void printTable();

*/

