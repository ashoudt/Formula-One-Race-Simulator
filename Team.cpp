#include <fstream>
#include <sstream>
#include <limits>
#include "Team.h"

Team::Team(){
}

Team::Team(string name, int skillLevel) {
    this->name = name;
    this->skillLevel = skillLevel;
}

// Other Methods
void Team::loadTeamData(vector<Team> &teams) {
    // Open .csv file
    ifstream inFile;
    inFile.open("../Data/teams.csv");

    // Get header line, read, and ignore it
    string header;
    if(inFile) {
        getline(inFile, header);
    }
    // Read data from each line of the file
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);

        // Team name
        getline(ss, name, ',');

        // Skill level
        ss >> skillLevel;
        if(ss.fail()) {
            // There was no driver number
            ss.clear();
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }
        // Add data from this line into a drivers object and add object to vector
        teams.push_back(Team(name, skillLevel));

    }
    // Close file
    inFile.close();
}