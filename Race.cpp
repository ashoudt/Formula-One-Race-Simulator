#include <algorithm>
#include <random>
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include "Race.h"
#include "Circuit.h"

using namespace std;


Race::Race() : grid(), polePosition(string(),0,0,string(),string()), winner(string(),0,0,string(),string()) {
    grid.clear();
}

vector<Driver> Race::getGrid() const {
    return grid;
}

Driver Race::getPolePosition() const {
    return polePosition;
}


Driver Race::getWinner() const {
    return winner;
}

void Race::setGrid(vector<Driver> grid) {
    this->grid = grid;
}

void Race::setPolePosition(Driver polePosition) {
    this->polePosition = polePosition;
}

void Race::setWinner(Driver winner) {
    this->winner = winner;
}

// Other methods
void Race::simulateRace(vector<Driver> drivers, vector<Circuit> circuits) {
    // Copy drivers into a new vector
    grid = drivers;

    // Set max numbers
    const int NUM_CRASHES = 3;

    // Print race intro
    Circuit currentRace = circuits.front();
    cout << "It's a beautiful race day at the " << currentRace.getName() << "!" << endl;
    cout << "Today's race is an exciting " << currentRace.getNumLaps() << " laps on this ";
    cout << currentRace.getLength() << " km circuit!\n" << endl;

    // Create a random starting grid order
    random_shuffle(grid.begin(), grid.end());

    // Get pole position
    polePosition = grid.front();

    // Delay output
    Sleep(1000);

    // Print pole position and starting grid
    cout << "With " << polePosition.getName() << " number " << polePosition.getDriverNumber() << " at pole, today's starting grid is..." << endl;
    for (int i = 0; i < grid.size(); ++i) {
        cout << i+1 << ". " << grid[i].getName() << " (" << grid[i].getTeam()->getName() << ")" << endl;
        Sleep(500);
    }

    // Start the race
    cout << "\nWith all the drivers lined on the grid, this exciting event is only 5 lights away!" << endl;
    cout << "In five..." << endl;
    Sleep(1000);
    cout << "Four..." << endl;
    Sleep(1000);
    cout << "Three..." << endl;
    Sleep(1000);
    cout << "Two..." << endl;
    Sleep(1000);
    cout << "One and it's lights out and away we go!" << endl;
    cout << "And it looks like " << polePosition.getName() << " gets away with a fantastic start!" << endl;

    // Simulate race events
    int totalCrashes = 0;
    vector<Driver> crashedDrivers;

    for (int lap = 1; lap <= currentRace.getNumLaps(); ++lap) {
        Sleep(500);

        // Flag to track if any events occurred
        bool eventsOccured = false;

        // Create random crash
        for (auto it = grid.begin(); it != grid.end(); ++it) {
            if (it->createCrash() && totalCrashes < NUM_CRASHES) {
                cout << "Oh no! " << it->getName() << " has crashed into the barriers and is out of the race!" << endl;
                // Add crashed driver into vector
                crashedDrivers.push_back(*it);
                // Remove crashed driver from grid
                grid.erase(it);
                ++totalCrashes;
                eventsOccured = true;
            }
        }

        // Create overtakes
        for (int i = 0; i < grid.size(); ++i) {
            // Create random chance of overtaking (10%)
            if (rand() % 100 < 2.5) {
                // Check if driver can overtake the next driver
                if (i < grid.size() - 1 && grid[i].calculatePerformance() > grid[i+1].calculatePerformance()) {
                    // Perform overtake by swapping positions
                    swap(grid[i], grid[i+1]);
                    // Randomly chooses an overtake message
                    if (rand() % 2 == 0) {
                        cout << "Incredible driving from " << grid[i].getName() << " as he passes " << grid[1+1].getName() << "!" << endl;
                    } else {
                        cout << "A bold maneuver from "  << grid[i].getName() << " as he seizes the opportunity to overtake " << grid[1+1].getName() << "!" << endl;
                    }
                    eventsOccured = true;
                }
            }
        }
        // Print lap just completed if an event occured
        if (eventsOccured) {
            cout << "Completed lap " << lap << "/" << currentRace.getNumLaps() << "\n" << endl;
        }
    }
    // Add crashed drivers back to grid
    for (auto& driver : crashedDrivers) {
        grid.push_back(driver);
    }
    // Assign points based on finishing positions
    int points[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    for (int i = 0; i < min(10, (int)grid.size()); ++i) {
        grid[i].setRaceScore(points[i]);
    }

    // Assign the winner
    winner = grid.front();
    // Announce winner
    cout << "And it's " << winner.getName() << " who takes the win at the " << currentRace.getName() << "!" << endl;

    // Print current race standings
    cout << "\nRace Standings:" << endl;
    for (int i = 0; i < grid.size(); i++) {
        bool isCrashedDriver = false;
        for (Driver& driver : crashedDrivers) {
            if (grid[i].getName() == driver.getName()) {
                isCrashedDriver = true;
            }
        }
        // Assign DNF as place if driver crashed
        if (isCrashedDriver) {
            cout << left << "DNF " << grid[i].getName() << " - Points: " << grid[i].getRaceScore() << endl;
        }
        else {
            cout << left << i + 1 << ". " << grid[i].getName() << " - Points: " << grid[i].getRaceScore() << endl;
        }
    }
}

