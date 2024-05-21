// dynamically allocated matrix

#include "Park.h"
#include "StackADT.h"
#include <vector>

Park::Park(ifstream &ifs) {
    ifs >> rowCount >> colCount >> ws;
    park = new cell[cellCount()];
    string line;
    for (int i = 0; i < rowCount; i++) {
        getline(ifs, line);
        for (int j = 0; j < colCount; j++) {
            set(i, j, line[j]);
        }
    }
}

Park::~Park() {
    delete[] park;
}

cell Park::at(int row, int col) const {
    return park[row * colCount + col];
}

bool Park::valid(int row, int col) const {  
    return ((row >=0) && (col >= 0) && (row < rowCount) && (col < colCount) && !at(row, col).found);
}

void Park::set(int row, int col, char value) {
    park[row * colCount + col].value = value;
}

void Park::print() const {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << at(i, j).value;
        }
        cout << endl;
    }
}

void Park::getNumObjectsStack() {
    
    int count = 0;
    vector<int> areas;
    
    for (int i = 0; i < cellCount(); i++) {
        Stack<cell> s;
        if (park[i].value != '0') {
            int area = 0;
            s.push(park[i]);
            while (!s.isEmpty()) {
                cell c = s.pop();
                if (c.isValid()) {
                    c.found = true;
                    // s.push upper
                    // s.push lower
                    // s.push right
                    // s.push left
                }
            }
            areas.push_back(area);
            count++;
        }
    }


}