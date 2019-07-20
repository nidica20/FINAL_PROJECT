#ifndef PATIENT_H_
#define PATIENT_H_
#include "Doctor.h"
#include "Nurse.h"
#include <fstream>
#include <string>
#include "RandomsGenerator.h"

struct Patient {
    // variables
    std::string first_name;
    std::string last_name;
    Random randomnumber;
    int illness_level;
    int time_of_arrival;
    int num_of_visits;
    int total_treatment_time;
    int start_treatment_time;
    int discharge_time;

    Patient () {} // No-arg constructor

    // Constructor
    Patient(int clock, std::string first_name, std::string last_name, int total_treatment_time)
    {
        num_of_visits = 0;
        this->first_name = first_name;
        this->last_name = last_name;
        time_of_arrival = clock;
        discharge_time = -1;
        this->illness_level = illness_level;
        this->start_treatment_time = -1;
        this->total_treatment_time = total_treatment_time;
    }

    // Getters
    int getIllnessLevel()
    {
        return illness_level; //returns illness level
    }

    int getNumOfVisits()
    {
        return num_of_visits; //returns number of visits patient has had
    }

    int getTotalTreatmentTime()
    {
        return total_treatment_time; //returns total time it takes to treat patient
    }

    std::string getFirstName()
    {
        return first_name; //returns patient's first name
    }

    std::string getLastName()
    {
        return last_name; //returns patient's last name
    }

    int getStartTreatmentTime()
    {
        return start_treatment_time; //returns the start time of patient's treatment
    }

    int getDischargeTime()
    {
        return discharge_time; //returns the discharge time of a patient
    }

    // Setters
    int setIllnessLevel()
    {
        this->illness_level = randomnumber.Random_Illness_Level(); //getting random number of priority based on patient's illness level
        num_of_visits++; //getting assigned a level of illness with every visit
        return illness_level;
    }

    void setStartTreatmentTime(int startTreatmentTime)
    {
        this->start_treatment_time = start_treatment_time;
    }
};

#endif