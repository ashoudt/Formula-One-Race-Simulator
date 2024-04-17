#ifndef M2OEP_PARTICIPANT_H
#define M2OEP_PARTICIPANT_H

#include <string>

using namespace std;

class Participant {
protected:
    int raceScore;
    int skillLevel;
    string name;
public:
    /**
     * Requires: nothing
    * Modifies: nothing
    * Effects: initialize raceScore, skillLevel, and name to default values
    */
    Participant();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Participant() = default;

    // Getters
    int getRaceScore() const;
    int getSkillLevel() const;
    virtual string getName() const;

    // Setters
    void setRaceScore(int raceScore);
    void setSkillLevel(int skillLevel);
    void setName(string name);
};


#endif //M2OEP_PARTICIPANT_H
