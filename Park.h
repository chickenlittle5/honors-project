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

    // cell default contructor
    cell() : value('0'), found(false), row(0), col(0) {}
};

class Park {
private:
    int _rowCount = 0;
    int _colCount = 0;
    cell *_park = nullptr;

public:
    Park() = default;
    Park(ifstream &ifs);
    ~Park();
    // getters
    int getRowCount() const { return _rowCount; }
    int getColCount() const { return _colCount; }
    int cellCount() const { return _rowCount * _colCount; }

    cell at(int row, int col);
    bool inBounds(int row, int col);
    bool inBounds(cell c);
    void set(int row, int col, char value, bool found);
    void print();

    void getNumObjectsStack();
    int check(cell c);
    void getNumObjectsRecursion();
};