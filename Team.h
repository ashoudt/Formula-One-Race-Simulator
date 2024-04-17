#ifndef M2OEP_TEAM_H
#define M2OEP_TEAM_H

#include "Participant.h"
#include <string>
#include <vector>

using namespace std;
class Team : public Participant {
public:
    // Constructors
    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    Team();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: initializes name and skillLevel
    */
    Team(string name, int skillLevel);

    // Other methods
    /**
    * Requires: vector of Team objects
    * Modifies: teams
    * Effects: loads in team data from .csv file
    */
    void loadTeamData(vector<Team>& teams);
};


#endif //M2OEP_TEAM_H
