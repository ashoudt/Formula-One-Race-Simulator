#include "Participant.h"

Participant::Participant() : raceScore(0), skillLevel(0), name("") {
}

int Participant::getRaceScore() const {
    return raceScore;
}

int Participant::getSkillLevel() const {
    return skillLevel;
}

string Participant::getName() const {
    return name;
}

void Participant::setRaceScore(int raceScore) {
    this->raceScore = raceScore;
}

void Participant::setSkillLevel(int skillLevel) {
    this->skillLevel = skillLevel;
}

void Participant::setName(string name) {
    this->name = name;
}