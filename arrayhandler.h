#ifndef ARRAYHANDLER_H
#define ARRAYHANDLER_H

#include <vector>
#include <stdexcept>

using namespace std;


class ArrayHandler {
private:
    vector<int> data;

public:
    ArrayHandler(const string& filename);

    int findInteger(int value) const;
    pair<int, int> modifyValue(int index, int newValue);
    void addInteger(int value);
    void replaceOrRemove(int index, bool remove = false);
    void printArray() const;
};

#endif // ARRAYHANDLER_H
