// dynamically allocated matrix

#include "Park.h"
#include "StackADT.h"
#include <vector>

/*
 * Constructor that uses the input file stream referenced parameter to read
 * the characters in the file and create a matrix that matches the file. The
 * first line reads the row and col then creates a dynamically allocated 
 * array with the given dimensions. It then reads each character and inputs
 * that character into its respective location in the dynamically allocated
 * array
 * 
 * @param ifs   the input file stream where the file is read into
 */

// issue should be in here for error in t4 printing.
// issue is that the bottom right corner is empty
Park::Park(ifstream &ifs) { 
    ifs >> _rowCount >> _colCount >> ws;
    _park = new cell[cellCount()];
    string line;
    for (int i = 0; i < _rowCount; i++) {
        getline(ifs, line);
        for (int j = 0; j < _colCount; j++) {
            set(i, j, line[j], false);
        }
    }
}

/*
 * Destructor that deletes the entire array when out of scope
 */
Park::~Park() {
    delete[] _park;
}

/*
 * Returns the cell in the dynamically allocated array at the given
 * row and col
 * 
 * @param row   the row where cell is located
 * @paran col   the col where cell is located
 */
cell Park::at(int row, int col) {
    if (!inBounds(row, col)) {
        return cell(); // Return a default cell if out of bounds
    }
    return _park[row * _colCount + col];
}

/*
 * Returns a bool that determines whether the given row and col to search 
 * is within bounds
 * 
 * @param row   the row where cell is located
 * @paran col   the col where cell is located
 */
bool Park::inBounds(int row, int col) {  
    return ((row >= 0) && (col >= 0) && (row < _rowCount) && (col < _colCount));
}

bool Park::inBounds(cell c) {
    int row = c.row;
    int col = c.col;
    return inBounds(row, col);
}

/*
 * Sets the value of the cell in the specified row and col with the given
 * parameters
 * @param row - row of the cell
 * @param col - column of the cell
 * @param value - value of the cell
 * @param found - determines of cell has been found already
 */
void Park::set(int row, int col, char value, bool found) {
    cell& c = _park[row * _colCount + col];
    c.value = value;
    c.row = row;
    c.col = col;
    c.found = found;
}

/*
 * Prints the entire park
 */
void Park::print() {
    for (int i = 0; i < _rowCount; i++) {
        for (int j = 0; j < _colCount; j++) {
            cout << at(i, j).value;
        }
        cout << endl;
    }
}

/*
 * Stack function
 * Iterates through the park until first object is found
 * If the cell is a valid cell meaning that it is within bounds
 * and has not been found yet, then push that item onto a stack
 * Loop until the stack is empty. In the loop, pop the stack 
 * and save that value into c. If c is valid, set its found 
 * value to true and increment area. Push adjacent cells.
 * 
 * Once loop terminates, increment the number of objects and add
 * the area to a vector. Repeat until finished interating through
 * park.
 * 
 * Print solution
 */
void Park::getNumObjectsStack() {
    int numObjects = 0;
    vector<int> areas;
    Stack<cell> s;

    for (int i = 0; i < getRowCount(); i++) {
        for (int j = 0; j < getColCount(); j++) {
            if (at(i, j).value != '0' && !at(i, j).found) {
                int area = 0;
                s.push(at(i, j));
                while (!s.isEmpty()) {
                    cell c = s.pop();
                    int x = c.row;
                    int y = c.col;
                    char value = c.value;
                    // initially put c.found but that doesnt work because it uses the cell value in the stack and not the matrix
                    if (inBounds(c) && !at(x, y).found && (value != '0')) { 
                        
                        set(x, y, value, true); // set found to true
                        area++;

                        //push upper, lower, left, right
                        s.push(at(x, y + 1));
                        s.push(at(x, y - 1));
                        s.push(at(x - 1, y));
                        s.push(at(x + 1, y));
                    }
                }
                numObjects++;
                areas.push_back(area);
            }
        }
    }

    cout << "Stack solution" << endl;
    cout << "Num objects: " << numObjects << endl;
    for (int i = 0; i < areas.size(); i++) {
        cout << "Object num " << i + 1  << " area: " << areas[i] << endl;
    }
}

/*
 * Recursive function that checks the cell to determine validity
 * and returns the area of the object
 * @param c - a given cell in the park
 */
int Park::check(cell c) {

    int row = c.row;
    int col = c.col;
    if (!inBounds(row, col) || c.value == '0' || c.found) {
        return 0;
    }

    set(row, col, c.value, true);
    
    int area = 1;
    area += check(at(row, col + 1));
    area += check(at(row, col - 1));
    area += check(at(row - 1, col));
    area += check(at(row + 1, col));

    return area;
}

/*
 * Iterates through the park until the first instance of an object
 * Once found, call the check recursive function and add that int
 * value to the areas vector. Increment the number of objects. 
 * 
 * Print solution
 */
void Park::getNumObjectsRecursion() {

    int numObjects = 0;
    vector<int> areas;

    for (int i = 0; i < getRowCount(); i++) {
        for (int j = 0; j < getColCount(); j++) {
            cell c = at(i, j);
            if (c.value != '0' && !c.found) {
                areas.push_back(check(c));
                numObjects++;
            }
        }
    }

    cout << "Recursive solution" << endl;
    cout << "Num objects: " << numObjects << endl;
    for (int i = 0; i < areas.size(); i++) {
        cout << "Object num " << i + 1  << " area: " << areas[i] << endl;
    }

}