#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

struct cell {
    char value;
    bool found = false;
    int row;
    int col;
};

class Park {
private:
    int rowCount = 0;
    int colCount = 0;
    cell *park = nullptr;

public:
    Park() = default;
    Park(ifstream &ifs);
    ~Park();
    // getters
    int getRowCount() const { return rowCount; }
    int getColCount() const { return colCount; }
    int cellCount() const { return rowCount * colCount; }

    cell at(int row, int col) const;
    bool valid(int row, int col) const;
    void set(int row, int col, char value);
    void print() const;

    void getNumObjectsStack();
    int getNumObjectsRecursion();
};