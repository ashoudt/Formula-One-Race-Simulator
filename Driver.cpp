#include "Driver.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

Driver::Driver() {
}

Driver::Driver(string name, int driverNumber, int skillLevel, string nationality, string debut) {
    this->name = name;
    this->driverNumber = driverNumber;
    this->skillLevel = skillLevel;
    this->nationality = nationality;
    this->debut = debut;
}

Team* Driver::getTeam() const {
    return teamPtr;
}

int Driver::getDriverNumber() const {
    return driverNumber;
}

string Driver::getNationality() const {
    return nationality;
}

string Driver::getDebut() const {
    return debut;
}

void Driver::setTeam(Team* teamPtr) {
    this->teamPtr = teamPtr;
}

void Driver::setDriverNumber(int driverNumber) {
    this->driverNumber = driverNumber;
}

void Driver::setNationality(std::string nationality) {
    this->nationality = nationality;
}

void Driver::setDebut(std::string debut) {
    this->debut = debut;
}

// Other Methods
void Driver::loadDriverData(vector<Driver> &drivers) {
    // Open .csv file
    ifstream inFile;
    inFile.open("../Data/drivers.csv");

    // Get header line, read, and ignore it
    string header;
    if(inFile) {
        getline(inFile, header);
    }
    // Read data from each line of the file
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);

        // Driver name
        getline(ss, name, ',');

        // Driver number
        ss >> driverNumber;
        if(ss.fail()) {
            // There was no driver number
            ss.clear();
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }

        ss.ignore(); // ignores comma

        // Skill level
        ss >> skillLevel;
        if(ss.fail()) {
            // There was no skill level
            ss.clear();
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }

        ss.ignore();

        // Nationality
        getline(ss, nationality, ',');

        // F1 debut
        getline(ss, debut, ',');

        // Add data from this line into a drivers object and add object to vector
        drivers.push_back(Driver(name, driverNumber, skillLevel, nationality, debut));

    }
    // Close file
    inFile.close();
}

void Driver::driverInfo(vector<Driver> &drivers) {
    cout << endl;     // for formatting purposes
    for (int i = 0; i < drivers.size(); i++) {
        cout << left << "Name: " << drivers[i].getName() << endl;
        cout << left << "Race Number: " << drivers[i].getDriverNumber() << endl;
        cout << left << "Team: " << drivers[i].getTeam()->getName() << endl;
        cout << left << "Nationality: " << drivers[i].getNationality() << endl;
        cout << left << "F1 Grand Prix Debut: " << drivers[i].getDebut() << endl;
        cout << endl;
    }
}

bool Driver::createCrash() {
    // create a random chance of crashing (1%)
    bool crashed = (rand() % 100) < 1;
    return crashed;
}

int Driver::calculatePerformance() const {
    int performance;
    performance = skillLevel * teamPtr->getSkillLevel();
    return performance;
}