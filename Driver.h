#ifndef M2OEP_DRIVER_H
#define M2OEP_DRIVER_H

#include "Participant.h"
#include "Team.h"
#include <string>
#include <vector>

using namespace std;

class Driver : public Participant {
protected:
    Team* teamPtr;
    int driverNumber;
    string nationality;
    string debut;
public:
    // Constructors
    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    Driver();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: initializes name, diverNumber, skillLevel, nationality, and debut
    */
    Driver(string name, int driverNumber, int skillLevel, string nationality, string debut);

    // Getters
    Team* getTeam() const;
    int getDriverNumber() const;
    string getNationality() const;
    string getDebut() const;


    // Setters
    void setTeam(Team* teamPtr);
    void setDriverNumber(int driverNumber);
    void setNationality(string nationality);
    void setDebut(string debut);


    // Other
    /**
    * Requires: vector of Driver objects
    * Modifies: drivers
    * Effects: loads in driver data from .csv files
    */
    void loadDriverData(vector<Driver>& drivers);

    /**
    * Requires: vector of Driver objects
    * Modifies: nothing
    * Effects: prints out driver info
    */
    void driverInfo(vector<Driver>& drivers);

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: randomly creates a crash with a 1% chance
    */
    bool createCrash();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: calculates performance by Driver skillLevel and Team skillLevel
    *          returns the performance value
    */
    int calculatePerformance() const;

};


#endif //M2OEP_DRIVER_H
