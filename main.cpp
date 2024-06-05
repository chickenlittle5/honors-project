// HonorsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Park.cpp"
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;


/*
Main method
*/
int main()
{

    /*
     * t0.txt
Number of objects: 4
Object 1 area: 6
Object 2 area: 9
Object 3 area: 1
Object 4 area: 17
     */
    string fileName = "t5.txt";
    cout << "File name: " << fileName << endl;
    // cin >> fileName;
    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        cout << "Error opening file, exiting";
        exit(0);
    }

    Park park(ifs);
    park.print();
    park.getNumObjectsStack();

    return 0;
}

