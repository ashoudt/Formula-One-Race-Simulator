#ifndef M2OEP_RACE_H
#define M2OEP_RACE_H

#include "Driver.h"
#include "Circuit.h"
#include <vector>

class Race {
protected:
    vector<Driver> grid;
    Driver polePosition;
    Driver winner;
public:
    // Constructor

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    Race();

    // Getters
    vector<Driver> getGrid() const;
    Driver getPolePosition() const;
    Driver getWinner() const;

    // Setters
    void setGrid(vector<Driver> grid);
    void setPolePosition(Driver polePosition);
    void setWinner(Driver winner);

    // Other methods
    /**
    * Requires: vector of Driver objects and vector of Circuit objects
    * Modifies: nothing
    * Effects: simulates a Formula One race by copying drivers into a grid vector
    *          and creates commentary and race events such as overtake and crash.
    *          calculates final positions and points and displays the results
    */
    void simulateRace(vector<Driver> drivers, vector<Circuit> circuits);
};


#endif //M2OEP_RACE_H
