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

    string fileName;
    cout << "File name: ";
    cin >> fileName;
    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        cout << "Error opening file, exiting";
        exit(0);
    }

    Park park(ifs);
    park.print();

    return 0;
}

