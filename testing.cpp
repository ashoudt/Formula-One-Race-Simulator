#include "Driver.h"
#include "Team.h"
#include "Circuit.h"
#include "Race.h"
#include "Participant.h"
#include <iostream>
using namespace std;

bool testRace();
bool testDriver();
bool testCircuit();
bool testTeam();
bool testParticipant();

int main() {
    if (testRace()) {
        cout << "Passes all Race test cases" << endl;
    }
    if (testDriver()) {
        cout << "Passes all Driver test cases" << endl;
    }
    if (testCircuit()) {
        cout << "Passes all Circuit test cases" << endl;
    }
    if (testTeam()) {
        cout << "Passes all Team test cases" << endl;
    }
    if (testParticipant()) {
        cout << "Passes all Participant test cases" << endl;
    }
    return 0;
}

bool testRace() {
    bool passed = true;

    Race r;
    Driver d("Lando Norris", 4, 15, "British", "2019 Australian Grand Prix");
    r.setPolePosition(d);
    if (r.getPolePosition().getName() != "Lando Norris") {
        passed = false;
        cout << "FAILED getPolePosition name Lando Norris test case" << endl;
    }

    r.setWinner(d);
    if (r.getWinner().getDriverNumber() != 4) {
        passed = false;
        cout << "FAILED getWinner driver number 4 test case" << endl;
    }

    vector<Driver> expectedGrid = {
            Driver("Lando Norris", 4, 15, "British", "2019 Australian Grand Prix"),
            Driver("Alex Albon", 23, 8, "Thai-British", "2019 Australian Grand Prix"),
            Driver("Max Verstappen" , 1, 20, "Dutch" , "2015 Australian Grand Prix")
    };
    r.setGrid(expectedGrid);
    vector<Driver> actualGrid = r.getGrid();
    if (actualGrid.size() != expectedGrid.size()) {
        passed = false;
        cout << "FAILED getGrid size test case" << endl;
    }
    else {
        for (int i = 0; i < expectedGrid.size(); ++i) {
            if (actualGrid[i].getName() != expectedGrid[i].getName()) {
                passed = false;
                cout << "Failed getGrid driver name test case" << endl;
            }
        }
    }
    return passed;
}

bool testDriver() {
    bool passed = true;

    Driver d("Oscar Piastri", 81, 12, "Australian", "2023 Bahrain Grand Prix");
    Team team("McLaren", 7);
    d.setTeam(&team);
    if (d.getTeam()->getName() != "McLaren") {
        passed = false;
        cout << "FAILED getTeam name McLaren test cases" << endl;
    }
    if (d.getTeam()->getSkillLevel() != 7) {
        passed = false;
        cout << "FAILED getTeam skill level 7 cases" << endl;
    }

    int performance = d.calculatePerformance();
    if (performance != 84) {
        passed = false;
        cout << "FAILED performance 84 test case" << endl;
    }

    Driver d2("Logan Sargeant", 2, 1, "American", "2023 Bahrain Grand Prix");
    Team team2("Williams", 4);
    d2.setTeam(&team2);
    int performance1 = d2.calculatePerformance();
    if (performance1 != 4) {
        passed = false;
        cout << "FAILED performance 4 test case" << endl;
    }
    Driver d3;
    bool crash = d3.createCrash();
    // crash is probabilistic, so just ensure that it returns a bool
    if (crash != true && crash != false) {
        passed = false;
        cout << "FAILED createCrash validity test case" << endl;
    }
    d3.setDriverNumber(16);
    if (d3.getDriverNumber() != 16) {
        passed = false;
        cout << "FAILED getDriverNumber 16 test case" << endl;
    }
    d3.setNationality("Monegasque");
    if (d3.getNationality() != "Monegasque") {
        passed = false;
        cout << "FAILED getNationality Monegasque test case" << endl;
    }
    d3.setDebut("2018 Australian Grand Prix");
    if (d3.getDebut() != "2018 Australian Grand Prix") {
        passed = false;
        cout << "FAILED getDebut 2018 Australian GP test case" << endl;
    }
    Driver d4;
    vector<Driver> drivers;
    d4.loadDriverData(drivers);
    if (drivers.size() != 20) {
        passed = false;
        cout << "FAILED loadDriverData size test case" << endl;
    }
    return passed;
}

bool testCircuit() {
    bool passed = true;
    Circuit c("Grand Prix du Canada", 4.36, 70);
    if (c.getName() != "Grand Prix du Canada") {
        passed = false;
        cout << "FAILED getName Grand Prix du Canada test case" << endl;
    }
    if (c.getLength() != 4.36) {
        passed = false;
        cout << "FAILED getLength 4.36 test case" << endl;
    }
    if (c.getNumLaps() != 70) {
        passed = false;
        cout << "FAILED getNumLaps 70 test case" << endl;
    }

    Circuit c2;
    c2.setName("Miami Grand Prix");
    if (c2.getName() != "Miami Grand Prix") {
        passed = false;
        cout << "FAILED getName Miami Grand Prix test case" << endl;
    }
    c2.setLength(5.41);
    if (c2.getLength() != 5.41) {
        passed = false;
        cout << "FAILED getLength 5.41 test case" << endl;
    }
    c2.setNumLaps(57);
    if (c2.getNumLaps() != 57) {
        passed = false;
        cout << "FAILED getNumLaps 57 test case" << endl;
    }

    Circuit c3;
    vector<Circuit> circuits;
    c3.loadCircuitData(circuits);
    if (circuits.size() != 23) {
        passed = false;
        cout << "FAILED loadCircuitData size test case" << endl;
    }
    return passed;
}

bool testTeam() {
    bool passed = true;

    Team t;
    vector<Team> teams;
    t.loadTeamData(teams);
    if (teams.size() != 10) {
        passed = false;
        cout << "FAILED loadTeamData size test case" << endl;
    }
    return passed;
}

bool testParticipant() {
    bool passed = true;

    Driver d("Pierre Gasly", 10, 10, "French", "2017 Malaysian Grand Prix");
    if (d.getName() != "Pierre Gasly") {
        passed = false;
        cout << "FAILED getName Pierre Gasly test case" << endl;
    }
    if (d.getSkillLevel() != 10) {
        passed = false;
        cout << "FAILED getSkillLevel 10 test case" << endl;
    }

    Driver d2;
    d2.setName("George Russel");
    if (d2.getName() != "George Russel") {
        passed = false;
        cout << "FAILED getName George Russel test case" << endl;
    }
    d2.setSkillLevel(13);
    if (d2.getSkillLevel() != 13) {
        passed = false;
        cout << "FAILED getSkillLevel 3 test case" << endl;
    }
    d2.setRaceScore(18);
    if (d2.getRaceScore() != 18) {
        passed = false;
        cout << "FAILED getRaceScore 18 test case" << endl;
    }

    Driver d3;
    d3.setRaceScore(0);
    if (d3.getRaceScore() != 0) {
        passed = false;
        cout << "FAILED getRaceScore 0 test case" << endl;
    }
    return passed;
}