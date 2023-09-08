#include "arrayhandler.h"
#include <iostream>
using namespace std;


int main() {
    try {
        string filename;
        cout << "Enter the filename to read data from: ";
        cin >> filename;

        ArrayHandler arrayHandler(filename);

        arrayHandler.printArray();

        int searchValue;
        cout << "Enter the integer to search for: ";
        cin >> searchValue;
        int searchIndex = arrayHandler.findInteger(searchValue);
        if (searchIndex != -1) {
            cout << searchValue << " found at index " << searchIndex << endl;
        } else {
            cout << searchValue << " not found in the array." << endl;
        }

        int modifyIndex, newValue;
        cout << "Enter the index to modify: ";
        cin >> modifyIndex;
        cout << "Enter the new value: ";
        cin >> newValue;
        pair<int, int> result = arrayHandler.modifyValue(modifyIndex, newValue);
        cout << "Modified: " << result.second << " -> " << result.first << endl;

        int newValueToAdd;
        cout << "Enter the integer to add to the end: ";
        cin >> newValueToAdd;
        arrayHandler.addInteger(newValueToAdd);

        int indexToRemoveOrReplace;
        bool remove;
        cout << "Enter the index to replace or remove: ";
        cin >> indexToRemoveOrReplace;
        cout << "Do you want to remove it? (0 for replace, 1 for remove): ";
        cin >> remove;
        arrayHandler.replaceOrRemove(indexToRemoveOrReplace, remove);

        arrayHandler.printArray();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
