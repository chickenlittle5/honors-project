// HonorsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Park.cpp"
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;


/*
 * Main method/menu
 */
int main()
{

    string fileName = "";
    string method;
    cout << "t0.txt" << endl;
    cout << "t1.txt" << endl;
    cout << "t2.txt" << endl;
    cout << "t3.txt" << endl;
    cout << "t4.txt" << endl;
    cout << "t5.txt" << endl;
    cout << "test.txt" << endl;
    cout << "Enter File name: ";
    cin >> fileName;
    cout << endl;

    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        cout << "Error opening file, exiting";
        return 1;
    }
    
    Park park(ifs);

    cout << "Park layout: " << endl;
    park.print();

    cout << "Enter method to use Stack(S) / Recursive(R): " << method;
    cin >> method;

    while (true) {
        if (method == "S" || method == "s" || method == "stack") {
            park.getNumObjectsStack();
            break;
        }
        else if (method == "R" || method == "r" || method == "recursive") {
            park.getNumObjectsRecursion();
            break;
        }
        else if (method == "Q" || method == "q") {
            break;
        }
        else {
            cout << "Invalid method. Please input again or quit(Q): ";
            cin >> method;
        }
    } 
    

    return 0;
}

