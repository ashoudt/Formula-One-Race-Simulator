#ifndef M2OEP_CIRCUIT_H
#define M2OEP_CIRCUIT_H

#include <string>
#include <vector>

using namespace std;

class Circuit {
protected:
    string name;
    double length;
    int numLaps;

public:
    // Constructors
    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    Circuit();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: initialize name, length, and numLaps to default values
    */
    Circuit(string name, double length, int numLaps);

    // Getters
    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns name
    */
    string getName() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns length
    */
    double getLength() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns numLaps
    */
    int getNumLaps() const;

    // Setters
    void setName(string name);
    void setLength(double length);
    void setNumLaps(int numLaps);


    // Other methods
    /**
    * Requires: vector of Circuit objects
    * Modifies: circuits
    * Effects: loads in circuit data from .csv files
    */
    void loadCircuitData(vector<Circuit>& circuits);

    /**
    * Requires: vector of Circuit objects
    * Modifies: nothing
    * Effects: prints out circuit info
    */
    void circuitInfo(vector<Circuit> circuits);

};


#endif //M2OEP_CIRCUIT_H
