#include "Circuit.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

Circuit::Circuit() {
}

Circuit::Circuit(string name, double length, int numLaps) {
    this->name = name;
    this->length = length;
    this->numLaps = numLaps;
}

string Circuit::getName() const{
    return name;
}

double Circuit::getLength() const {
    return length;
}

int Circuit::getNumLaps() const {
    return numLaps;
}

void Circuit::setName(std::string name) {
    this->name = name;
}

void Circuit::setLength(double length) {
    this->length = length;
}

void Circuit::setNumLaps(int numLaps) {
    this->numLaps = numLaps;
}


// Other methods
void Circuit::loadCircuitData(vector<Circuit>& circuits) {
    // Open .csv file
    ifstream inFile;
    inFile.open("../Data/circuits.csv");

    // Get header line, read, and ignore it
    string header;
    if(inFile) {
        getline(inFile, header);
    }
    // Read data from each line of the file
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);

        // Race name
        getline(ss, name, ',');

        // Length of Circuit
        ss >> length;
        if(!inFile) {
            // The was no length
            ss.clear();
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }
        ss.ignore(); // ignores comma

        // Number of laps at Circuit
        ss >> numLaps;
        if(!inFile) {
            // There was no number of Laps
            ss.clear();
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }

        // Add data from this line into a drivers object and add object to vector
        circuits.push_back(Circuit(name, length, numLaps));
    }
    // Close file
    inFile.close();
}

void Circuit::circuitInfo(vector<Circuit> circuits) {
    cout << endl;   // for formatting purposes
    for (int i = 0; i < circuits.size(); i++) {
        cout << left << "Name: " << circuits[i].getName() << endl;
        cout << left << "Length: " << circuits[i].getLength() << " km" << endl;
        cout << left << "Number of Laps: " << circuits[i].getNumLaps() << endl;
        cout << endl;
    }
}