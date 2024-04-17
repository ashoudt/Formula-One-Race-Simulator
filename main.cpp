#include <vector>
#include <iostream>
#include <limits>
#include "Race.h"
#include "Driver.h"
#include "Circuit.h"
using namespace std;

int getUserIntInput(string invalid, int low, int high);
char getUserCharInput();
void assignDriversToTeams(vector<Driver>& drivers, vector<Team>& teams);

int main() {
    // create objects and vectors
    Driver d;
    Circuit c;
    Team t;
    Race r;
    vector<Driver> drivers;
    vector<Circuit> circuits;
    vector<Team> teams;

    int intChoice;
    char charChoice;
    bool run = true;

    // read in driver and circuit data
    d.loadDriverData(drivers);
    c.loadCircuitData(circuits);
    t.loadTeamData(teams);

    // assign drivers to their teams
    assignDriversToTeams(drivers, teams);

    // print out display menu
    while(run) {
        cout << "Welcome to the 2023 Formula One season!" << endl;
        cout << "Please choose an option below:" << endl;
        cout << "1. Run Race" << endl;
        cout << "2. View Driver Information" << endl;
        cout << "3. View Circuit Information" << endl;
        cout << "4. Exit Program" << endl;

        intChoice = getUserIntInput("Invalid input. Please enter a number from 1-4.", 1, 4);
        if (intChoice == 1) {
            bool nextRace = true;
            for (int i = 0; i < circuits.size(); i++) {
                if (nextRace) {
                    // run race
                    r.simulateRace(drivers, {circuits[i]});
                    cout << "Do you want to move on to the next race? (y/n): ";
                    charChoice = getUserCharInput();
                    if (charChoice == 'n') {
                        nextRace = false;
                        cout << "Returning to main menu..." << endl;
                        break;
                    }
                    if (i == circuits.size() - 1) {
                        cout << "All races completed!" << endl;
                        cout << "Returning to main menu..." << endl;
                        break;
                    }
                }
            }
        } else if (intChoice == 2) {
            d.driverInfo(drivers);
        }
        else if (intChoice == 3) {
            c.circuitInfo(circuits);
        }
        else {
            cout << "Exiting program...";
            run = false;
        }
    }
    return 0;
}

int getUserIntInput(string invalid, int low, int high) {
    int choice;
    string nothing;
    cout << "Enter your choice: ";
    while(!(cin >> choice) || choice < low || choice > high) {
      cout << invalid;
      cin.clear();
      getline(cin, nothing);
    }
    return choice;
}

char getUserCharInput() {
    char choice;
    // check for invalid input
    while(true) {
        cin >> choice;

         if (cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter y or n (case-sensitive): ";
        }
        else if (choice != 'y' && choice != 'n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter y or n (case-sensitive): ";
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

void assignDriversToTeams(vector<Driver>& drivers, vector<Team>& teams) {
    // Use indexing to assign a driver to a team
    // Red Bull
    drivers[0].setTeam(&teams[0]);
    drivers[1].setTeam(&teams[0]);
    // Ferrari
    drivers[2].setTeam(&teams[1]);
    drivers[3].setTeam(&teams[1]);
    // Mercedes
    drivers[4].setTeam(&teams[2]);
    drivers[5].setTeam(&teams[2]);
    // Alpine
    drivers[6].setTeam(&teams[3]);
    drivers[7].setTeam(&teams[3]);
    // McLaren
    drivers[8].setTeam(&teams[4]);
    drivers[9].setTeam(&teams[4]);
    // Kick Sauber
    drivers[10].setTeam(&teams[5]);
    drivers[11].setTeam(&teams[5]);
    // Aston Martin
    drivers[12].setTeam(&teams[6]);
    drivers[13].setTeam(&teams[6]);
    // Haas
    drivers[14].setTeam(&teams[7]);
    drivers[15].setTeam(&teams[7]);
    // RB
    drivers[16].setTeam(&teams[8]);
    drivers[17].setTeam(&teams[8]);
    // Williams
    drivers[18].setTeam(&teams[9]);
    drivers[19].setTeam(&teams[9]);
}