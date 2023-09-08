#include "arrayhandler.h"
#include <iostream>
#include <fstream>
using namespace std;


ArrayHandler::ArrayHandler(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file.");
    }

    int num;
    while (file >> num) {
        data.push_back(num);
    }
    file.close();
}

int ArrayHandler::findInteger(int value) const {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

pair<int, int> ArrayHandler::modifyValue(int index, int newValue) {
    if (index < 0 || index >= static_cast<int>(data.size())) {
        throw out_of_range("Index out of range.");
    }

    int oldValue = data[index];
    data[index] = newValue;
    return make_pair(newValue, oldValue);
}

void ArrayHandler::addInteger(int value) {
    data.push_back(value);
}

void ArrayHandler::replaceOrRemove(int index, bool remove) {
    if (index < 0 || index >= static_cast<int>(data.size())) {
        throw out_of_range("Index out of range.");
    }

    if (remove) {
        data.erase(data.begin() + index);
    } else {
        data[index] = 0;
    }
}

void ArrayHandler::printArray() const {
    for (const auto& num : data) {
        cout << num << " ";
    }
    cout << endl;
}
